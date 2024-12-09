void MemoryTracker::RegisterCategory(uint32 categoryID, const char* name)
    {
        LockGuard lock(m_mutex);

        // try to see if the category exists already
        auto item = m_categories.find(categoryID);
        if (item == m_categories.end())
        {
            // register the new category
            CategoryStats catStats;
            catStats.m_name = name;
            m_categories.insert(std::make_pair(categoryID, catStats));
        }
        else
        {
            item->second.m_name = name;
        }
    }