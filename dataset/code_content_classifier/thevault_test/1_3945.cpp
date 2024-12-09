TEST(BlackBox, ParticipantLivelinessAssertion)
{
    PubSubReader<HelloWorldType> reader(TEST_TOPIC_NAME);
    PubSubWriter<HelloWorldType> writer(TEST_TOPIC_NAME);

    auto test_transport = std::make_shared<test_UDPv4TransportDescriptor>();

    reader.disable_builtin_transport().add_user_transport_to_pparams(test_transport).
        lease_duration({ 0, 800000000 }, { 0, 500000000 }).reliability(eprosima::fastrtps::RELIABLE_RELIABILITY_QOS).init();

    ASSERT_TRUE(reader.isInitialized());

    writer.disable_builtin_transport().add_user_transport_to_pparams(test_transport).
        lease_duration({ 0, 800000000 }, { 0, 500000000 }).init();

    ASSERT_TRUE(writer.isInitialized());

    // Wait for discovery.
    writer.wait_discovery();
    reader.wait_discovery();

    test_UDPv4Transport::always_drop_participant_builtin_topic_data = true;

    std::thread thread([&writer]()
            {
                HelloWorld msg;
                for (int count = 0 ; count < 20; ++count)
                {
                    writer.send_sample(msg);
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            });

    ASSERT_FALSE(reader.wait_participant_undiscovery(std::chrono::seconds(1)));
    ASSERT_FALSE(writer.wait_participant_undiscovery(std::chrono::seconds(1)));

    test_UDPv4Transport::always_drop_participant_builtin_topic_data = false;

    thread.join();
}