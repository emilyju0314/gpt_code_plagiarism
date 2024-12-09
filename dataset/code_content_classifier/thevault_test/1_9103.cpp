TEST_F(ProcessingEngineTest, SharedSubTaskProcessing)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto queueChannel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "QUEUE_CHANNEL_ID");
    queueChannel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {});


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto processingCore = std::make_shared<ProcessingCoreImpl>(500);

    auto nodeId1 = "NODE_1";
    auto nodeId2 = "NODE_2";

    ProcessingEngine engine1(pubs1, nodeId1, processingCore, [](const SGProcessing::TaskResult&) {});
    ProcessingEngine engine2(pubs1, nodeId2, processingCore, [](const SGProcessing::TaskResult&) {});

    auto queue = std::make_unique<SGProcessing::SubTaskQueue>();
    // Local queue wrapped owns the queue
    queue->mutable_processing_queue()->set_owner_node_id(nodeId1);
    {
        auto item = queue->mutable_processing_queue()->add_items();
        auto subTask = queue->add_subtasks();
        subTask->set_results_channel("RESULT_CHANNEL_ID1");
    }
    {
        auto item = queue->mutable_processing_queue()->add_items();
        auto subTask = queue->add_subtasks();
        subTask->set_results_channel("RESULT_CHANNEL_ID2");
    }

    auto processingQueue1 = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId1);
    processingQueue1->ProcessSubTaskQueueMessage(queue.release());

    engine1.StartQueueProcessing(processingQueue1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    auto processingQueue2 = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId2);

    // Change queue owner
    SGProcessing::SubTaskQueueRequest queueRequest;
    queueRequest.set_node_id(nodeId2);
    auto updatedQueue = processingQueue1->ProcessSubTaskQueueRequestMessage(queueRequest);

    // Synchronize the queues
    processingQueue2->ProcessSubTaskQueueMessage(processingQueue1->GetQueueSnapshot().release());
    processingQueue1->ProcessSubTaskQueueMessage(processingQueue2->GetQueueSnapshot().release());

    engine2.StartQueueProcessing(processingQueue2);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    pubs1->Stop();

    ASSERT_EQ(2, processingCore->m_initialHashes.size());
    EXPECT_EQ(static_cast<uint32_t>(std::hash<std::string>{}(nodeId1)), processingCore->m_initialHashes[0]);
    EXPECT_EQ(static_cast<uint32_t>(std::hash<std::string>{}(nodeId2)), processingCore->m_initialHashes[1]);
}