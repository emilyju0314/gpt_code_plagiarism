bool HashTable::insert(WordCounter &wordc, int position)
{
    if (position >=0) 
    {
        //if (!isValid(position))
        //    increase(position);
        storage[position].push_back(wordc);
        numObjects++;
        return true;
    }
    else
        return false;
}