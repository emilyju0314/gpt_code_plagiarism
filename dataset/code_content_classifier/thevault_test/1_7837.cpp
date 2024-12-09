void
mergeSkipShortLists(const vector<Array<unsigned>*> &arrays,
                    const unsigned threshold,
                    vector<unsigned> &results,
                    vector<unsigned> &counters)
{

    //const unsigned maxUnsigned = 0x10000000 - 2;
    const unsigned maxUnsigned = 0xFFFFFFFF;

    unsigned numberOfInvertedList = arrays.size();

    if (threshold > numberOfInvertedList)
        return; // no answer

    unsigned pointersIndex [numberOfInvertedList];

    for (unsigned k = 0; k < numberOfInvertedList; k++)
        pointersIndex[k] = 0;

    addMAXUnsigned2EachList(arrays, maxUnsigned);

    unsigned dataHeap [numberOfInvertedList];
    unsigned indexHeap [numberOfInvertedList];

    makeInitialHeap(dataHeap, indexHeap, arrays);

    unsigned sizeOfHeaps = numberOfInvertedList;

    unsigned pivot = threshold - 1;

    while (dataHeap[0] < maxUnsigned) {

        //cout<< " Current heaps are : " << endl;
        //printArrayUnsigned (dataHeap, sizeOfHeaps);
        //printArrayUnsigned (indexHeap, sizeOfHeaps);

        // Container of vector indexes which should be moved to the next position
        unsigned vectorIndexContainer[numberOfInvertedList];
        unsigned containerSize = 0;


        // Check if we can get the result
        unsigned minData = dataHeap[0];

        while (minData == dataHeap[0] && containerSize < numberOfInvertedList) {
            vectorIndexContainer[containerSize++] = indexHeap[0];

            heapDelete(dataHeap, indexHeap, sizeOfHeaps);

        }//end while

        if (containerSize >= threshold) // we got the result
        {
            counters.push_back(containerSize);
            results.push_back(minData);

            //cout<< "We get a result, rule ID is " << minData <<", count is " << containerSize <<endl;

            //move to the next element
            for (unsigned i = 0; i < containerSize; i++) {
                unsigned j = vectorIndexContainer[i];
                pointersIndex[j]++;
            }//end for

            insertToHeaps(dataHeap, indexHeap,
                          sizeOfHeaps,
                          arrays, pointersIndex,
                          vectorIndexContainer,
                          containerSize);

            continue;

        }//end if


        // pop more elements from heap
        // and skip nodes

        while (containerSize < pivot) {

            vectorIndexContainer[containerSize++] = indexHeap[0];

            heapDelete(dataHeap, indexHeap, sizeOfHeaps);


        }//end while (containerSize < pivot )

        //printArray( vectorIndexContainer,containerSize);

        // cout<< "Pivot node is " <<  dataHeap[0] << endl;

        skipNodes(arrays, vectorIndexContainer, containerSize,
                  dataHeap[0], pointersIndex);

        //cout<<"After skip, current nodes are : " <<endl;

        //showCurrentNodes(&pointersNode, &pointersIndex, numberOfInvertedList);

        insertToHeaps(dataHeap,
                      indexHeap,
                      sizeOfHeaps,
                      arrays,
                      pointersIndex,
                      vectorIndexContainer,
                      containerSize);

    }//end while  ( thresholdHeap[0]  < MAX)

    deleteMAXUnsignedfromEachList(arrays);

}