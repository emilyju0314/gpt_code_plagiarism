void
sortBySizeOfLists(const vector<Array<unsigned>*> &allLists,
                  unsigned sortedIndex [])
{
    vector<Array<unsigned>*>::const_iterator ite = allLists.begin();

    unsigned sizeHeap[allLists.size()];
    unsigned indexHeap[allLists.size()];

    unsigned index = 0;

    unsigned heapSize = 0;

    while (ite != allLists.end()) {
        unsigned sizeOfList = (*ite)->size();

        heapInsert(sizeOfList, index++, sizeHeap, indexHeap, heapSize);

        ite++;

    }//end while

    index = 0;

    while (heapSize > 0) {
        sortedIndex[index++] = indexHeap[0];
        heapDelete(sizeHeap, indexHeap, heapSize);
    }//end while

}