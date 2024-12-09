void
separateTwoSets(vector<Array<unsigned>*> *longLists,
                vector<Array<unsigned>*> *shortLists,
                const unsigned threshold,
                const vector<Array<unsigned>*> &originalLists,
                unsigned sortedIndex[])
{
    unsigned originalListSize = originalLists.size();

    for (unsigned i = 0; i < originalListSize; i++) {
        if (i < threshold - 1)
            longLists->push_back(originalLists.at(sortedIndex[originalListSize - i - 1]));
        else
            shortLists->push_back(originalLists.at(sortedIndex[originalListSize - i - 1]));

    }//end for

}