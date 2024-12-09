TEST(BlackBox, ReqRepVolatileHelloworldRequesterCheckWriteParams)
{
    ReqRepAsReliableHelloWorldRequester requester;

    requester.durability_kind(eprosima::fastrtps::VOLATILE_DURABILITY_QOS).init();

    ASSERT_TRUE(requester.isInitialized());

    requester.send(1);
}