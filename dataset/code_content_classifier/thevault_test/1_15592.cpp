void readStopList(HashTable &stopList)
{
    char word[KEYWORDSIZE];
    ifstream fin("stopWords");
    if (!fin.good())
    {
        cout << "error reading the stop list file" << endl;
        exit(1);
    }
    WordCounter wordc;
    do 
    {
        fin >> word;
        if (!fin.eof()) 
        {
            wordc.setWord(word);
            stopList.insert(wordc);
        }
    } while (!fin.eof());
    fin.close();
}