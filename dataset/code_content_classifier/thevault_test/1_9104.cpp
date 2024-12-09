TEST_F(ProcessingEngineTest, TaskFinalization)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto queueChannel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "QUEUE_CHANNEL_ID");
    queueChannel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {});

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto processingCore = std::make_shared<ProcessingCoreImpl>(100);

    auto nodeId1 = "NODE_1";

    bool isTaskFinalized = false;
    ProcessingEngine engine1(pubs1, nodeId1, processingCore,
        [&isTaskFinalized](const SGProcessing::TaskResult&) { isTaskFinalized = true; });
    processingCore->m_chunkResultHashes["RESULT_CHANNEL_ID1"] = { 0 };
    processingCore->m_chunkResultHashes["RESULT_CHANNEL_ID2"] = { 0 };

    SGProcessing::ProcessingChunk chunk1;
    chunk1.set_chunkid("CHUNK_1");
    chunk1.set_n_subchunks(1);
    chunk1.set_line_stride(1);
    chunk1.set_offset(0);
    chunk1.set_stride(1);
    chunk1.set_subchunk_height(10);
    chunk1.set_subchunk_width(10);

    auto queue = std::make_unique<SGProcessing::SubTaskQueue>();
    // Local queue wrapped owns the queue
    queue->mutable_processing_queue()->set_owner_node_id(nodeId1);
    {
        auto item = queue->mutable_processing_queue()->add_items();
        auto subTask = queue->add_subtasks();
        subTask->set_results_channel("RESULT_CHANNEL_ID1");
        auto chunk = subTask->add_chunkstoprocess();
        chunk->CopyFrom(chunk1);
    }
    {
        auto item = queue->mutable_processing_queue()->add_items();
        auto subTask = queue->add_subtasks();
        subTask->set_results_channel("RESULT_CHANNEL_ID2");
        auto chunk = subTask->add_chunkstoprocess();
        chunk->CopyFrom(chunk1);
    }

    auto processingQueue1 = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId1);
    processingQueue1->ProcessSubTaskQueueMessage(queue.release());

    engine1.StartQueueProcessing(processingQueue1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    pubs1->Stop();

    ASSERT_TRUE(isTaskFinalized);
}