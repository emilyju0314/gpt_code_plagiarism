TEST_F(ProcessingSubTaskQueueTest, GrabSubTaskWithOwnershipTransferring)
{
    std::vector<SGProcessing::SubTaskQueue> queueSnapshotSet1;
    std::vector<SGProcessing::SubTaskQueue> queueSnapshotSet2;

    auto pubs1 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs1->Start(40001, {});

    auto pubs2 = std::make_shared<sgns::ipfs_pubsub::GossipPubSub>();;
    pubs2->Start(40001, { pubs1->GetLocalAddress() });

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
    pubs1Channel->Subscribe([&queue1, &queueSnapshotSet1](
        boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {
            if (message)
            {
                SGProcessing::ProcessingChannelMessage channelMessage;
                if (channelMessage.ParseFromArray(message->data.data(), static_cast<int>(message->data.size())))
                {
                    if (channelMessage.has_subtask_queue())
                    {
                        queueSnapshotSet1.push_back(channelMessage.subtask_queue());
                        queue1.ProcessSubTaskQueueMessage(channelMessage.release_subtask_queue());
                    }
                    else if (channelMessage.has_subtask_queue_request())
                    {
                        queue1.ProcessSubTaskQueueRequestMessage(channelMessage.subtask_queue_request());
                    }
                }
            }
        });

    auto pubs2Channel = std::make_shared<sgns::ipfs_pubsub::GossipPubSubTopic>(pubs2, "PROCESSING_CHANNEL_ID");
    auto nodeId2 = pubs2->GetLocalAddress();

    ProcessingSubTaskQueue queue2(pubs2Channel, pubs2->GetAsioContext(), nodeId2);
    pubs2Channel->Subscribe([&queueSnapshotSet2, &queue2](
        boost::optional<const sgns::ipfs_pubsub::GossipPubSub::Message&> message) {
            if (message)
            {
                SGProcessing::ProcessingChannelMessage channelMessage;
                if (channelMessage.ParseFromArray(message->data.data(), static_cast<int>(message->data.size())))
                {
                    if (channelMessage.has_subtask_queue())
                    {
                        queueSnapshotSet2.push_back(channelMessage.subtask_queue());
                        queue2.ProcessSubTaskQueueMessage(channelMessage.release_subtask_queue());
                    }
                    else if (channelMessage.has_subtask_queue_request())
                    {
                        queue2.ProcessSubTaskQueueRequestMessage(channelMessage.subtask_queue_request());
                    }

                }
            }
        });

    // Wait for subscription
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // Create the queue on node1
    queue1.CreateQueue(subTasks);

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    // Grab subtask on Node2
    queue2.GrabSubTask([](boost::optional<const SGProcessing::SubTask&> subtask) {
        if (subtask)
        {
            // process subtask
        }
        });

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    pubs1->Stop();
    pubs2->Stop();

    ASSERT_EQ(3, queueSnapshotSet2.size());

    // Ownership is transferred to node2
    ASSERT_EQ(2, queueSnapshotSet2[2].processing_queue().items_size());
    EXPECT_EQ(nodeId2, queueSnapshotSet2[2].processing_queue().owner_node_id());

    // The subtask is locked by node2
    EXPECT_EQ(nodeId2, queueSnapshotSet2[2].processing_queue().items(0).lock_node_id());
    EXPECT_EQ("", queueSnapshotSet2[2].processing_queue().items(1).lock_node_id());
}