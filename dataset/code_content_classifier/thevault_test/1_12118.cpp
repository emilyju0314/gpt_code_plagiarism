static void BM_UnorderedMap_InsertDuplicatesViaInsert(::benchmark::State& state)
    {
        while (state.KeepRunning())
        {
            UnorderedMap map;
            for (int mapKey = 0; mapKey < kNumInsertions; ++mapKey)
            {
                A& a = map.insert(make_pair(mapKey % kModuloForDuplicates, A())).first->second;
                a.m_int += 1;
            }
        }
    }