void
skipNodes(const vector<Array<unsigned>* > &lists,
          unsigned vectorIndexContainer[],
          unsigned containerSize,
          unsigned pivotData,
          unsigned pointersIndexList[])

{

    for (unsigned i = 0; i < containerSize; i++) {

        unsigned j = vectorIndexContainer[i];

        unsigned oldPosition = pointersIndexList[j];

        pointersIndexList[j] =
            lists.at(j)->binarySearch(pivotData, oldPosition);

        // cout<< "new data" << lists.at(j)->at( pointersIndexList[j]) <<
        //	" old data " << pivotData <<endl;

        //assert(lists.at(j)->at( pointersIndexList[j]) >= pivotData);

    }//end for

}