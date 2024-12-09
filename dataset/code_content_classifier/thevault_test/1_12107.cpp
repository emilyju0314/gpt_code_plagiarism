TEST_F(TaskGraphTestFixture, SpawnSubgraph)
    {
        AZStd::atomic<int> x = 0;

        TaskGraph graph;
        auto a = graph.AddTask(
            defaultTD,
            [&]
            {
                x = 0b111;
            });
        auto b = graph.AddTask(
            defaultTD,
            [&]
            {
                x ^= 1;
            });
        auto c = graph.AddTask(
            defaultTD,
            [&]
            {
                x ^= 2;

                TaskGraph subgraph;
                auto e = subgraph.AddTask(
                    defaultTD,
                    [&]
                    {
                        x ^= 0b1000;
                    });
                auto f = subgraph.AddTask(
                    defaultTD,
                    [&]
                    {
                        x ^= 0b10000;
                    });
                auto g = subgraph.AddTask(
                    defaultTD,
                    [&]
                    {
                        x += 0b1000;
                    });
                e.Precedes(g);
                f.Precedes(g);
                TaskGraphEvent ev;
                subgraph.SubmitOnExecutor(*m_executor, &ev);
                // TaskGraphEvent::Wait asserts if called on a worker thread, suppress & validate assert
                AZ_TEST_START_TRACE_SUPPRESSION;
                ev.Wait();
                AZ_TEST_STOP_TRACE_SUPPRESSION(1);
            });
        auto d = graph.AddTask(
            defaultTD,
            [&]
            {
                x -= 1;
            });

        // NOTE: The ideal way to express this topology is without the wait on the subgraph
        // at task g, but this is more an illustrative test. Better is to express the entire
        // graph in a single larger graph.
        //   a  <-- Root
        //  / \
        // b   c - f
        //  \   \   \
        //   \   e - g
        //    \     /
        //     \   /
        //      \ /
        //       d

        a.Precedes(b);
        a.Precedes(c);
        b.Precedes(d);
        c.Precedes(d);

        TaskGraphEvent ev;
        graph.SubmitOnExecutor(*m_executor, &ev);
        ev.Wait();
    }