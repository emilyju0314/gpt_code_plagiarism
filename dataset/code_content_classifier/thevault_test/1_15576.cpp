bool HashTable::increase(int position)
{
    if (position >= 0)
        if (position > capacity) 
        {
            ListWordC emptyList;
            for (int i=capacity; i<= position; i++)
                storage.push_back(emptyList);
            capacity = position + 1;
            return true;
        }
    return false; 
}