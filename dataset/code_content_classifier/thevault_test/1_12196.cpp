TEST_F(NameTest, DISABLED_NameVsStringPerf_UnorderedSearch)
    {
        constexpr int SearchCount = 10000;
        constexpr int EntryCount = 10000;

        char buffer[RandomStringBufferSize];

        AZStd::sys_time_t nameTime;
        AZStd::sys_time_t stringTime;

        {
            AZStd::unordered_map<AZ::Name, int> nameMap;
            AZStd::vector<AZ::Name> nameList;
            for (int i = 0; i < EntryCount; ++i)
            {
                AZ::Name name{ MakeRandomString(buffer) };
                nameMap[name] = i;
                nameList.push_back(name);
            }

            bool result = true;

            const AZStd::sys_time_t startTime = AZStd::GetTimeNowMicroSecond();

            for (int i = 0; i < SearchCount; ++i)
            {
                const int randomEntry = m_random.GetRandom() % EntryCount;
                auto& name = nameList[randomEntry];
                auto iter = nameMap.find(name);
                result &= (randomEntry == iter->second);
            }

            nameTime = AZStd::GetTimeNowMicroSecond() - startTime;

            EXPECT_TRUE(result);

            nameMap.clear();
            nameList.clear();
        }

        {
            AZStd::unordered_map<AZStd::string, int> nameMap;
            AZStd::vector<AZStd::string> nameList;
            for (int i = 0; i < EntryCount; ++i)
            {
                AZStd::string name{ MakeRandomString(buffer) };
                nameMap[name] = i;
                nameList.push_back(name);
            }

            bool result = true;

            const AZStd::sys_time_t startTime = AZStd::GetTimeNowMicroSecond();

            for (int i = 0; i < SearchCount; ++i)
            {
                const int randomEntry = m_random.GetRandom() % EntryCount;
                auto& name = nameList[randomEntry];
                auto iter = nameMap.find(name);
                result &= (randomEntry == iter->second);
            }

            stringTime = AZStd::GetTimeNowMicroSecond() - startTime;

            EXPECT_TRUE(result);
        }

        AZ_TracePrintf("NameTest", "Search for %d strings:    %d us\n", SearchCount, stringTime);
        AZ_TracePrintf("NameTest", "Search for %d names:      %d us\n", SearchCount, nameTime);

        EXPECT_LT(nameTime, stringTime);
    }