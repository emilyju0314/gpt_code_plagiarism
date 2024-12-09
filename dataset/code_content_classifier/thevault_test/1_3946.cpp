TEST(BlackBox, PubXmlLoadedPartition)
{
    PubSubReader<HelloWorldType> reader(TEST_TOPIC_NAME);
    PubSubWriter<HelloWorldType> writer(TEST_TOPIC_NAME);

    reader.partition("A").init();

    ASSERT_TRUE(reader.isInitialized());

    const std::string xml = R"(<profiles>
  <publisher profile_name="partition_publisher_profile">
    <topic>
      <name>)" + writer.topic_name() + R"(</name>
      <dataType>HelloWorldType</dataType>
    </topic>
    <qos>
      <partition>
        <names>
          <name>A</name>
        </names>
      </partition>
    </qos>
    </publisher>
</profiles>)";

    writer.load_publisher_attr(xml).init();

    ASSERT_TRUE(writer.isInitialized());

    reader.wait_discovery();
    writer.wait_discovery();
}