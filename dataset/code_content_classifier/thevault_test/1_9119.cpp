TEST_F(ProcessingSubTaskQueueTest, QueueCreating)
{
    std::vector<SGProcessing::SubTaskQueue> queueSnapshotSet;

    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto pubs2 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs2->Start(40001, { pubs1->GetLocalAddress() });

    auto pubs1Channel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "PROCESSING_CHANNEL_ID");
    pubs1Channel->Subscribe([](boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message)
    {     
    });

    auto pubs2Channel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs1, "PROCESSING_CHANNEL_ID");
    pubs2Channel->Subscribe([&queueSnapshotSet](
        boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message)
    {
        if (message)
        {
            SGProcessing::ProcessingChannelMessage channelMessage;
            if (channelMessage.ParseFromArray(message->data.data(), static_cast<int>(message->data.size())))
            {
                if (channelMessage.has_subtask_queue())
                {
                    queueSnapshotSet.push_back(channelMessage.subtask_queue());
                }
            }

        }
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

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

    auto nodeId = pubs1->GetLocalAddress();
    ProcessingSubTaskQueue queue(pubs1Channel, pubs1->GetAsioContext(), nodeId);

    queue.CreateQueue(subTasks);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    pubs1->Stop();

    ASSERT_EQ(1, queueSnapshotSet.size());
    EXPECT_EQ(nodeId, queueSnapshotSet[0].processing_queue().owner_node_id());
    ASSERT_EQ(2, queueSnapshotSet[0].processing_queue().items_size());
    EXPECT_EQ("", queueSnapshotSet[0].processing_queue().items(0).lock_node_id());
    EXPECT_EQ("", queueSnapshotSet[0].processing_queue().items(1).lock_node_id());
}