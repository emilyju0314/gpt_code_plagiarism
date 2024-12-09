void AnimGraphRefCountedDataPool::Resize(size_t numItems)
    {
        const size_t numOldItems = m_items.size();

        // if we will remove Items
        if (numItems < numOldItems)
        {
            // remove the last Items
            const size_t numToRemove = numOldItems - numItems;
            for (size_t i = 0; i < numToRemove; ++i)
            {
                AnimGraphRefCountedData* item = m_items.back();
                MCORE_ASSERT(AZStd::find(begin(m_freeItems), end(m_freeItems), item) != end(m_freeItems)); // make sure the Item is not already in use
                delete item;
                m_items.erase(m_items.end() - 1);
            }
        }
        else // we want to add new Items
        {
            const size_t numToAdd = numItems - numOldItems;
            for (size_t i = 0; i < numToAdd; ++i)
            {
                AnimGraphRefCountedData* newItem = new AnimGraphRefCountedData();
                m_items.emplace_back(newItem);
                m_freeItems.emplace_back(newItem);
            }
        }
    }