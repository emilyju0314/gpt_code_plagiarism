TEST_F(ProcessingSubTaskQueueTest, TaskSplitFailed)
{
    // @todo extend the test to get determite invalid result hashes
    std::vector<SGProcessing::SubTaskQueue> queueSnapshotSet1;

    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    ProcessingCore::SubTaskList subTasks;
    {
        auto subtask = std::make_unique<SGProcessing::SubTask>();
        subtask->set_results_channel("RESULT_CHANNEL_1");
        subTasks.push_back(std::move(subtask));
    }

    {
        auto subtask = std::make_unique<SGProcessing::SubTask>();
        subtask->set_results_channel("RESULT_CHANNEL_2");
        subTasks.push_back(std::move(subtask));
    }

    auto pubs1Channel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "PROCESSING_CHANNEL_ID");
    auto nodeId1 = pubs1->GetLocalAddress();

    ProcessingSubTaskQueue queue1(pubs1Channel, pubs1->GetAsioContext(), nodeId1);

    // Create the queue on node1
    ASSERT_FALSE(queue1.CreateQueue(subTasks));

    pubs1->Stop();
}