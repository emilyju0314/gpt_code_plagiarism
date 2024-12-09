TEST_F(GpuQueryTests, TestQueryPools)
    {
        const uint32_t QueryCount = 1024u;
        const uint32_t QueriesPerInstance = 1u;
        const RHI::QueryType Type = RHI::QueryType::Occlusion;
        const RHI::PipelineStatisticsFlags StatisticsFlags = RHI::PipelineStatisticsFlags::None;
        const uint32_t OcclusionQueryResultSize = sizeof(uint64_t);

        const RHI::FrameGraphExecuteContext::Descriptor desc = {};
        RHI::FrameGraphExecuteContext context(desc);

        // Setup the FrameGraph
        RHI::Scope scope;
        scope.Init(RHI::ScopeId("StubScope"));
        RHI::FrameGraph frameGraph;
        frameGraph.BeginScope(scope);

        AZStd::unique_ptr<RPI::QueryPool> queryPool = RPI::QueryPool::CreateQueryPool(QueryCount, QueriesPerInstance, Type, StatisticsFlags);

        const uint32_t resultSize = queryPool->GetQueryResultSize();
        EXPECT_EQ(resultSize, OcclusionQueryResultSize);

        // Test valid Queries
        {
            RHI::Ptr<RPI::Query> query = queryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);
            EXPECT_TRUE(query.get());
        }

        // Test adding to the FrameGraph multiple times with one Query within a single frame
        {
            RHI::Ptr<RPI::Query> query = queryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);

            QueryResultCode resultCode = query->AddToFrameGraph(frameGraph);
            EXPECT_EQ(resultCode, QueryResultCode::Success);
            resultCode = query->AddToFrameGraph(frameGraph);
            EXPECT_EQ(resultCode, QueryResultCode::Fail);

            // Next frame
            queryPool->Update();
        }

        // Test recording the same Query in different frames
        {
            RHI::Ptr<RPI::Query> query = queryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);
            QueryResultCode resultCode = query->AddToFrameGraph(frameGraph);
            EXPECT_EQ(resultCode, QueryResultCode::Success);

            // Next frame
            queryPool->Update();

            resultCode = query->BeginQuery(context);
            EXPECT_EQ(resultCode, QueryResultCode::Fail);
        }

        // Test Query result
        {
            // Occlusion QueryPool result size is sizeof(uint64_t)
            EXPECT_EQ(queryPool->GetQueryResultSize(), sizeof(uint64_t));
        }

        // Test get result with invalid size
        {
            RHI::Ptr<RPI::Query> query = queryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);

            EXPECT_TRUE(query.get());
            QueryResultCode resultCode = query->AddToFrameGraph(frameGraph);
            EXPECT_EQ(resultCode, QueryResultCode::Success);
            void* data = nullptr;
            // Query type of the pool is occlusion, which expects a result size of sizeof(uint64_t).
            resultCode = query->GetLatestResult(data, sizeof(uint32_t));
            EXPECT_EQ(resultCode, QueryResultCode::Fail);
        }

        // Test going over QueryPool limit
        {
            // Temporary QueryPool with a limit of 1 Query
            AZStd::unique_ptr<RPI::QueryPool> tempRpiQueryPool = RPI::QueryPool::CreateQueryPool(1u, QueriesPerInstance, Type, StatisticsFlags);
            RHI::Ptr<RPI::Query> query = tempRpiQueryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);
            EXPECT_TRUE(query.get());
            RHI::Ptr<RPI::Query> query1 = tempRpiQueryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);
            EXPECT_TRUE(!query1.get());
        }

        // Test different Scopes for Begin() and End()
        {
            RHI::FrameGraphExecuteContext::Descriptor desc2;
            desc2.m_scopeId = RHI::ScopeId("Test");
            desc2.m_commandListIndex = 0;
            desc2.m_commandListCount = 1;
            desc2.m_commandList = nullptr;
            RHI::FrameGraphExecuteContext context2(desc2);

            RHI::Ptr<RPI::Query> query = queryPool->CreateQuery(RHI::QueryPoolScopeAttachmentType::Global, RHI::ScopeAttachmentAccess::Write);

            EXPECT_TRUE(query.get());
            QueryResultCode resultCode = query->AddToFrameGraph(frameGraph);
            EXPECT_EQ(resultCode, QueryResultCode::Success);
            resultCode = query->BeginQuery(context);
            EXPECT_EQ(resultCode, QueryResultCode::Success);
            resultCode = query->EndQuery(context2);
            EXPECT_EQ(resultCode, QueryResultCode::Fail);
        }
    }