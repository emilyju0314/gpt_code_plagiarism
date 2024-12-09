void indexWords(HashTable &stopList, HashTable &indexing)
{
    char word[KEYWORDSIZE];
    WordCounter wordc;
    cout << "Enter words separated by spaces or new lines.\n"
         << "The program will output the Porter transform of the words.\n"
         << "End the input with Ctrl-D." << endl;
    while (!cin.eof()) 
    {
        cin >> word;
        if (!cin.eof()) 
        {
            toLowerCase(word);
            clean(word);
            //Check the table stopList to make sure the word is not there before applying the Porter
            //transformation and adding it to the the indexing hash table.
            if (!stopList.access(wordc, word))
            {
                stripAffixes(word);
                increment(indexing, word);
            }
        }
    }
    cout << endl;
}