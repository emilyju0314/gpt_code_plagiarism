bool HashTable::access(WordCounter &wordc, string s)
{
    //Determine whether the string has been used as a key and if it has, find() copies the found
    //object into wordc and returns true, otherwise it returns false.  The find() returned value is
    //passed on as this function's return value as well.
    return find(wordc, s, hashing(s));
}