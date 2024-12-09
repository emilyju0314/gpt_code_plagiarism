TEST_F(ProcessingEngineTest, InvalidSubTasksRestart)
{
    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto queueChannel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "QUEUE_CHANNEL_ID");
    queueChannel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {});

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // The processing core 1 has invalid chunk result hashes
    auto processingCore1 = std::make_shared<ProcessingCoreImpl>(500);
    processingCore1->m_chunkResultHashes["RESULT_CHANNEL_ID1"] = { 0 };
    processingCore1->m_chunkResultHashes["RESULT_CHANNEL_ID2"] = { 1 };


    // The processing core 2 has invalid chunk result hashes
    auto processingCore2 = std::make_shared<ProcessingCoreImpl>(100);
    processingCore2->m_chunkResultHashes["RESULT_CHANNEL_ID1"] = { 0 };
    processingCore2->m_chunkResultHashes["RESULT_CHANNEL_ID2"] = { 0 };

    auto nodeId1 = "NODE_1";
    auto nodeId2 = "NODE_2";

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

    bool isTaskFinalized1 = false;
    ProcessingEngine engine1(pubs1, nodeId1, processingCore1,
        [&isTaskFinalized1](const SGProcessing::TaskResult&) { isTaskFinalized1 = true; });

    bool isTaskFinalized2 = false;
    ProcessingEngine engine2(pubs1, nodeId2, processingCore2,
        [&isTaskFinalized2](const SGProcessing::TaskResult&) { isTaskFinalized2 = true; });

    engine1.StartQueueProcessing(processingQueue1);

    // Wait for queue processing by node1
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // No task finalization should be called when there are invalid chunk results
    ASSERT_FALSE(isTaskFinalized1);

    auto processingQueue2 = std::make_shared<ProcessingSubTaskQueue>(
        queueChannel, pubs1->GetAsioContext(), nodeId2);

    // Change queue owner
    SGProcessing::SubTaskQueueRequest queueRequest;
    queueRequest.set_node_id(nodeId2);
    auto updatedQueue = processingQueue1->ProcessSubTaskQueueRequestMessage(queueRequest);

    // Synchronize the queues
    processingQueue2->ProcessSubTaskQueueMessage(processingQueue1->GetQueueSnapshot().release());
    processingQueue1->ProcessSubTaskQueueMessage(processingQueue2->GetQueueSnapshot().release());
    engine1.StopQueueProcessing();

    // Wait for failed tasks expiration
    // @todo Automatically mark failed tasks as exired
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    engine2.StartQueueProcessing(processingQueue2);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    pubs1->Stop();

    // Task should be finalized because chunks have valid hashes
    ASSERT_TRUE(isTaskFinalized2);
}