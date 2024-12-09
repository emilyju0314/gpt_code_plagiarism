void increment(HashTable &indexing, string word)
{
    //Declare a new WordCounter and set it equal to the passed in word.
    WordCounter wordc = word;

    //Attempt remove word from the table.
    if (indexing.remove(wordc, word))
        //If word was found in the table, increment its count of the word.
        wordc.increment();

    //Insert wordc into the hash table.  If it was found previously, it will have a count > 1, if
    //not, it will be inserted for the first time with a count of 1.
    indexing.insert(wordc);
}