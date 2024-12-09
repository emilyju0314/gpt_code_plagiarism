static void discoverParticipantsSeveralEndpointsTest(
        bool avoid_multicast,
        size_t n_participants,
        size_t n_topics,
        uint32_t wait_ms,
        const std::string& topic_name)
{
    // Total number of discovered endpoints
    size_t n_total_endpoints = n_participants * n_topics;

    std::vector<std::shared_ptr<PubSubWriterReader<HelloWorldType>>> pubsub;
    pubsub.reserve(n_participants);

    for (unsigned int i = 0; i < n_participants; i++)
    {
        pubsub.emplace_back(std::make_shared<PubSubWriterReader<HelloWorldType>>(topic_name));
    }

    // Initialization of all the participants
    std::cout << "Initializing PubSubs for topic " << topic_name << std::endl;
    uint32_t idx = 1;
    for (auto& ps : pubsub)
    {
        std::cout << "\rParticipant " << idx++ << " of " << n_participants << std::flush;
        ps->init(avoid_multicast);
        ASSERT_EQ(ps->isInitialized(), true);
        ASSERT_TRUE(ps->create_additional_topics(n_topics - 1));
    }

    bool all_discovered = false;
    std::cout << std::endl << "Waiting discovery between " << n_participants << " participants." << std::endl;
    while (!all_discovered)
    {
        all_discovered = true;

        for (auto& ps : pubsub)
        {
            if ((ps->get_num_discovered_participants() < n_participants - 1) ||
                (ps->get_num_discovered_publishers() < n_total_endpoints) ||
                (ps->get_num_discovered_subscribers() < n_total_endpoints) ||
                (ps->get_publication_matched() < n_total_endpoints) ||
                (ps->get_subscription_matched() < n_total_endpoints))
            {
                all_discovered = false;
                break;
            }
        }

        if (!all_discovered)
        {
            // Give some time so that participants can discover each other
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_ms));
        }
    }

    // Test will fail by timeout if a discovery error happens
    std::cout << "All discovered. Closing participants..." << std::endl;
    for (auto& ps : pubsub)
    {
        ps->destroy();
    }
}