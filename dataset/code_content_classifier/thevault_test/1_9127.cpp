TEST_F(ProcessingSubTaskQueueTest, TaskSplitSucceeded)
{
    // @todo extend the test to get determite invalid result hashes
    std::vector<SGProcessing::SubTaskQueue> queueSnapshotSet1;

    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});


    ProcessingCore::SubTaskList subTasks;

    // A single chunk is added to 2 subtasks
    SGProcessing::ProcessingChunk chunk1;
    chunk1.set_chunkid("CHUNK_1");
    chunk1.set_n_subchunks(1);
    chunk1.set_line_stride(1);
    chunk1.set_offset(0);
    chunk1.set_stride(1);
    chunk1.set_subchunk_height(10);
    chunk1.set_subchunk_width(10);

    {
        auto subtask = std::make_unique<SGProcessing::SubTask>();
        subtask->set_results_channel("RESULT_CHANNEL_1");
        auto chunk = subtask->add_chunkstoprocess();
        chunk->CopyFrom(chunk1);
        subTasks.push_back(std::move(subtask));
    }

    {
        auto subtask = std::make_unique<SGProcessing::SubTask>();
        subtask->set_results_channel("RESULT_CHANNEL_2");
        auto chunk = subtask->add_chunkstoprocess();
        chunk->CopyFrom(chunk1);
        subTasks.push_back(std::move(subtask));
    }

    auto pubs1Channel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "PROCESSING_CHANNEL_ID");
    auto nodeId1 = pubs1->GetLocalAddress();

    ProcessingSubTaskQueue queue1(pubs1Channel, pubs1->GetAsioContext(), nodeId1);

    // Create the queue on node1
    ASSERT_TRUE(queue1.CreateQueue(subTasks));

    pubs1->Stop();
}