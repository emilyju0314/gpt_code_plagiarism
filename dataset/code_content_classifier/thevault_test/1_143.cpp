Error Mpl::UpdateSeedSet(uint16_t aSeedId, uint8_t aSequence)
{
    Error      error    = kErrorNone;
    SeedEntry *insert   = nullptr;
    SeedEntry *group    = mSeedSet;
    SeedEntry *evict    = mSeedSet;
    uint8_t    curCount = 0;
    uint8_t    maxCount = 0;

    for (uint32_t i = 0; i < kNumSeedEntries; i++, curCount++)
    {
        if (mSeedSet[i].mLifetime == 0)
        {
            // unused entries exist

            if (insert == nullptr)
            {
                // no existing group, set insert and evict entry to be the same
                insert = &mSeedSet[i];
            }

            // mark first unused entry for eviction
            evict = &mSeedSet[i];
            break;
        }

        if (mSeedSet[i].mSeedId != group->mSeedId)
        {
            // processing new group

            if (aSeedId == group->mSeedId && insert == nullptr)
            {
                // insert at end of existing group
                insert = &mSeedSet[i];
                curCount++;
            }

            if (maxCount < curCount)
            {
                // look to evict an entry from the seed with the most entries
                evict    = group;
                maxCount = curCount;
            }

            group    = &mSeedSet[i];
            curCount = 0;
        }

        if (aSeedId == mSeedSet[i].mSeedId)
        {
            // have existing entries for aSeedId

            int8_t diff = static_cast<int8_t>(aSequence - mSeedSet[i].mSequence);

            if (diff == 0)
            {
                // already received, drop message
                ExitNow(error = kErrorDrop);
            }
            else if (insert == nullptr && diff < 0)
            {
                // insert in order of sequence
                insert = &mSeedSet[i];
                curCount++;
            }
        }
    }

    if (evict->mLifetime != 0)
    {
        // no free entries available, look to evict an existing entry
        OT_ASSERT(curCount != 0);

        if (aSeedId == group->mSeedId && insert == nullptr)
        {
            // insert at end of existing group
            insert = &mSeedSet[kNumSeedEntries];
            curCount++;
        }

        if (maxCount < curCount)
        {
            // look to evict an entry from the seed with the most entries
            evict    = group;
            maxCount = curCount;
        }

        // require evict group size to have >= 2 entries
        VerifyOrExit(maxCount > 1, error = kErrorDrop);

        if (insert == nullptr)
        {
            // no existing entries for aSeedId
            insert = evict;
        }
        else
        {
            // require Sequence to be larger than oldest stored Sequence in group
            VerifyOrExit(insert > mSeedSet && aSeedId == (insert - 1)->mSeedId, error = kErrorDrop);
        }
    }

    if (evict > insert)
    {
        OT_ASSERT(insert >= mSeedSet);
        memmove(insert + 1, insert, static_cast<size_t>(evict - insert) * sizeof(SeedEntry));
    }
    else if (evict < insert)
    {
        OT_ASSERT(evict >= mSeedSet);
        memmove(evict, evict + 1, static_cast<size_t>(insert - 1 - evict) * sizeof(SeedEntry));
        insert--;
    }

    insert->mSeedId   = aSeedId;
    insert->mSequence = aSequence;
    insert->mLifetime = kSeedEntryLifetime;

    if (!mSeedSetTimer.IsRunning())
    {
        mSeedSetTimer.Start(kSeedEntryLifetimeDt);
    }

exit:
    return error;
}