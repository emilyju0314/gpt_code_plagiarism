TEST_F(ProcessingRoomTest, AttachToProcessingRoom)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto pubs2 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs2->Start(40001, {pubs1->GetLocalAddress()});

    auto processingCore = std::make_shared<ProcessingCoreImpl>();

    ProcessingNode node1(pubs1, 2, processingCore, [](const SGProcessing::TaskResult&) {});
    ProcessingNode node2(pubs2, 2, processingCore, [](const SGProcessing::TaskResult&) {});

    SGProcessing::Task task;
    task.set_ipfs_block_id("DATABLOCKID");
    node1.CreateProcessingHost(task);
    node2.AttachTo("DATABLOCKID", 500);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    pubs2->Stop();
    pubs1->Stop();

    EXPECT_EQ(node1.GetRoom()->GetNodeIds().size(), 2);
    EXPECT_EQ(node2.GetRoom()->GetNodeIds().size(), 2);
}