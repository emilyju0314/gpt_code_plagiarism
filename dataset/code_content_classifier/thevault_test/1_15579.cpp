bool HashTable::find(WordCounter &wordc, string k, int position)
{
    //Assume this method will not find anything.
    bool found = false;

    //Check to make sure that the position being passed into this method is valid.
    if (isValid(position))
    {
        //Set up a list iterator and point it at the beginning of the list contained in the position
        //element of the storage vector.
        ListIter iter = storage[position].begin();

        //Iterate through the list looking for the string k.
        while (iter != storage[position].end() && key(*iter) != k)
            //If the string is not found at that location, increment the iterator.
            ++iter;

        //Once the loop is done, test the iterator and check if it is at the end of the list.
        if (iter != storage[position].end())
        {
            //If the iterator is not at the end of the list, copy the word counter object that iter
            //references into wordc and set the found flag to true indicating that string k was
            //located.
            wordc = *iter;
            found = true;
        }
    }

    //Return the flag found, be it true or false.
    return found;
}