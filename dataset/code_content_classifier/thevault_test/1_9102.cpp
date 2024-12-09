TEST_F(ProcessingEngineTest, SubTaskProcessing)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto queueChannel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "QUEUE_CHANNEL_ID");
    queueChannel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {});


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto processingCore = std::make_shared<ProcessingCoreImpl>(0);

    auto nodeId = "NODE_1";
    ProcessingEngine engine(pubs1, nodeId, processingCore, [](const SGProcessing::TaskResult&) {});

    auto queue = std::make_unique<SGProcessing::SubTaskQueue>();
    // Local queue wrapped owns the queue
    queue->mutable_processing_queue()->set_owner_node_id(nodeId);
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

    auto processingQueue = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId);
    processingQueue->ProcessSubTaskQueueMessage(queue.release());

    engine.StartQueueProcessing(processingQueue);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    pubs1->Stop();

    ASSERT_EQ(2, processingCore->m_processedSubTasks.size());
    EXPECT_EQ("RESULT_CHANNEL_ID1", processingCore->m_processedSubTasks[0].results_channel());
    EXPECT_EQ("RESULT_CHANNEL_ID2", processingCore->m_processedSubTasks[1].results_channel());
}