void
insertToHeaps(unsigned dataHeap[],
              unsigned indexHeap[],
              unsigned &heapSize,
              const vector< Array<unsigned>* > &lists,
              unsigned pointersIndexList[],
              unsigned vectorIndexContainer[],
              unsigned containerSize)

{
    for (unsigned i = 0; i < containerSize; i++) {
        unsigned index = vectorIndexContainer[i];

        unsigned position = pointersIndexList[index];

        unsigned newData =
            (lists.at(index))->at(position);

        heapInsert(newData, index, dataHeap, indexHeap, heapSize);

    }//end for

}