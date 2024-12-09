static void BM_UnorderedMap_InsertUniqueViaInsert(::benchmark::State& state)
    {
        while (state.KeepRunning())
        {
            UnorderedMap map;
            for (int mapKey = 0; mapKey < kNumInsertions; ++mapKey)
            {
                A& a = map.insert(make_pair(mapKey, A{})).first->second;
                a.m_int += 1;
            }
        }
    }