bool HashTable::remove(WordCounter &wordc, string k, int position)
{
    if (!isValid(position))
        return false;
    else 
    {
        ListIter iter = storage[position].begin();
        while (iter != storage[position].end() && 
               key(*iter) != k)
            ++iter;
        if (iter == storage[position].end())
            return false;
        else 
        {
            wordc = *iter;
            storage[position].erase(iter);
            numObjects--;
            return true;
        }
    }
}