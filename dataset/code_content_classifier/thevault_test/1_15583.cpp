bool HashTable::remove(WordCounter &wordc, string s)
{
    //Attempt to remove the passed string s from the table using the private remove() method.
    return remove(wordc, s, hashing(s));
}