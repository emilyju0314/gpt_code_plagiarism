bool HashTable::insert(WordCounter &wordc)
{
    //Start with the assumption that the string in wordc is not already in the hash table.
    bool inserted = true;

    //Resizes the storage vector if needed due to high or low load factor.
    //resize();

    //Compute the hash of the string in wordc and store it for later use.
    int hashVal = hashing(key(wordc));

    //Check if the word in wordc is already in the table.
    if (find(wordc, key(wordc), hashVal))
        //If it is, then set the inserted flag to false.
        inserted = false;
    else
        //If it is not, insert the wordc object in the list at the element specified by the hash
        //method.
        inserted = insert(wordc, hashVal);

    //Return whether the insertion operation was successful or not.
    return inserted;
}