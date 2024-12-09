TEST_F(ProcessingEngineTest, SubscribtionToResultChannel)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto pubs2 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs2->Start(40001, {pubs1->GetLocalAddress()});

    sgns::ipfs_pubsub::GossipPubSubTopic resultChannel(pubs1, "RESULT_CHANNEL_ID");
    resultChannel.Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message)
    {     
    });

    auto queueChannel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "QUEUE_CHANNEL_ID");
    queueChannel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {});


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto processingCore = std::make_shared<ProcessingCoreImpl>(0);

    auto nodeId = "NODE_1";
    ProcessingEngine engine(pubs1, nodeId, processingCore, [](const SGProcessing::TaskResult&) {});

    auto queue = std::make_unique<SGProcessing::SubTaskQueue>();
    queue->mutable_processing_queue()->set_owner_node_id("DIFFERENT_NODE_ID");

    auto item = queue->mutable_processing_queue()->add_items();
    auto subTask = queue->add_subtasks();
    subTask->set_results_channel("RESULT_CHANNEL_ID");

    auto processingQueue = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId);
    // The local queue wrapper doesn't own the queue
    processingQueue->ProcessSubTaskQueueMessage(queue.release());

    engine.StartQueueProcessing(processingQueue);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    SGProcessing::SubTaskResult result;    
    resultChannel.Publish(result.SerializeAsString());

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    pubs1->Stop();
    pubs2->Stop();

    ASSERT_EQ(1, engine.GetResults().size());
    EXPECT_EQ("RESULT_CHANNEL_ID", std::get<0>(engine.GetResults()[0]));
}