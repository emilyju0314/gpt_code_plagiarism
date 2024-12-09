TEST(BlackBox, AsyncVolatileSubBetweenPubs)
{
	PubSubReader<HelloWorldType> reader(TEST_TOPIC_NAME);
	PubSubWriter<HelloWorldType> writer(TEST_TOPIC_NAME);

	writer.history_kind(eprosima::fastrtps::KEEP_ALL_HISTORY_QOS).
		reliability(eprosima::fastrtps::RELIABLE_RELIABILITY_QOS).
		durability_kind(eprosima::fastrtps::VOLATILE_DURABILITY_QOS).
		resource_limits_allocated_samples(9).
		resource_limits_max_samples(9).
		asynchronously(eprosima::fastrtps::ASYNCHRONOUS_PUBLISH_MODE).
		heartbeat_period_seconds(3600).
		init();

	ASSERT_TRUE(writer.isInitialized());

	HelloWorld hello;
	hello.index(1);
	hello.message("HelloWorld 1");

	writer.send_sample(hello);

	reader.history_kind(eprosima::fastrtps::KEEP_ALL_HISTORY_QOS).
		reliability(eprosima::fastrtps::RELIABLE_RELIABILITY_QOS).
		durability_kind(eprosima::fastrtps::VOLATILE_DURABILITY_QOS).
		init();

	ASSERT_TRUE(reader.isInitialized());

	writer.wait_discovery();
	reader.wait_discovery();

	auto data = default_helloworld_data_generator(1);
	reader.startReception(data);
	// Send data with some interval, to let async writer thread send samples
	writer.send(data, 300);
	// In this test all data should be sent.
	ASSERT_TRUE(data.empty());
	// Block reader until reception finished or timeout.
	reader.block_for_all();
}