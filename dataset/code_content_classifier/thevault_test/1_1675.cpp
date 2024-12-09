void
Bucket::InputIterator::loadEntry()
{
    if (mIn.readOne(mEntry))
    {
        mEntryPtr = &mEntry;
    }
    else
    {
        mEntryPtr = nullptr;
    }
}