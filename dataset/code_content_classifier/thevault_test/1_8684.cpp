void calcUnwrap(double* unwrappedImage, const long int numGroups, vector<edgeInfo>& edges, 
    vector <pixelGroup>& groupArray, const long int numCols, const long int numRows, const long int numPages) {

    long int adjGroup, adjIndex, currentCol, currentRow, currentPage, currentGroup;
    long int iters, numberOfJumps, jumpDirection, currentFirst, currentLast, nextFirst, nextLast;
    long int nextPixel;

    char edge;
    double phase1, phase2;
    
    int maxIters = 100; //use a modest number of iterations

    for (long int sortedIndex = 0; sortedIndex < numGroups; sortedIndex++) {

        //Retrieve parameters about the current edge type and its location
        currentRow = edges[sortedIndex].row;
        currentCol = edges[sortedIndex].column;
        currentPage = edges[sortedIndex].page;
        //the weird condition on numPages only is so that it still enters the loop in 2D, 
        //when currentPage = 0 always
        if (currentRow < numRows - 1 && currentCol < numCols - 1 && (currentPage < numPages - 1 || currentPage == 0)) {
            currentGroup = groupArray[get3Dindex(currentRow, currentCol, currentPage, numCols, numRows)].group;
            edge = edges[sortedIndex].edgeType;

            //Calculate index of adjacent pixel
            switch (edge) {
                case 'r': //row edge
                    adjIndex = get3Dindex(currentRow + 1, currentCol, currentPage, numCols, numRows);
                    break;
                case 'c': //column edge
                    adjIndex = get3Dindex(currentRow, currentCol + 1, currentPage, numCols, numRows);
                    break;
                case 'p': //page edge
                    adjIndex = get3Dindex(currentRow, currentCol, currentPage + 1, numCols, numRows);
                    break;
                default: {
                    mexPrintf("edgetype = %c \n", edge);
                    mexErrMsgTxt("ERROR: non-existent edge type");
                }
            }

            //group of adjacent pixel
            adjGroup = groupArray[adjIndex].group;
            //current phase of adjacent pixel
            phase1 = unwrappedImage[adjIndex];
            //current phase of current pixel
            phase2 = unwrappedImage[get3Dindex(currentRow, currentCol, currentPage, numCols, numRows)];

            //its is used in a while loop for phase unwrapping
            iters = 0;
            //m is the number of 2pi jumps
            numberOfJumps = 0;
            //jumpDirection indicates the direction of the 2 pi jumps (+1 or -1)
            jumpDirection = 0;
            //Only need to unwrap if the two different pixels are in different groups
            if (adjGroup != currentGroup) {

                //First condition is definition of a phase discontinuity and second condition just makes sure we don't get stuck in an infinite loop
                while (fabs(phase1 - phase2) > M_PI && iters < maxIters) {

                    //if phase needs to decrement by 2pi
                    if (phase1 > phase2 + M_PI) {
                        phase1 = phase1 - 2 * M_PI;
                        jumpDirection = -1;
                        ++numberOfJumps; //increment jump counter
                    }
                    //if phase needs to increment by 2pi
                    else if (phase1 < phase2 - M_PI) {
                        phase1 = phase1 + 2 * M_PI;
                        jumpDirection = 1;
                        ++numberOfJumps;
                    }

                    //if phase is just right
                    else {
                        iters = maxIters + 1;
                        break;
                    }

                    //Increase iteration count
                    ++iters;

                }

                //Merge the two groups by having last index of first group go to first index of second group
                currentFirst = groupArray[get3Dindex(currentRow, currentCol, currentPage, numCols, numRows)].firstIndex;
                currentLast = groupArray[get3Dindex(currentRow, currentCol, currentPage, numCols, numRows)].lastIndex;


                nextLast = groupArray[adjIndex].lastIndex;
                nextFirst = groupArray[adjIndex].firstIndex;

                groupArray[currentLast].nextIndex = nextFirst;
                groupArray[currentFirst].lastIndex = nextLast;

                nextPixel = groupArray[currentFirst].nextIndex;
                //next = -1 indicates end of group
                //Loop over all of group and add correct phase to adjGroup
                while (nextPixel != -1) {

                    if (groupArray[nextPixel].group == adjGroup) {
                        unwrappedImage[nextPixel] = unwrappedImage[nextPixel] + jumpDirection * 2 * M_PI * numberOfJumps;
                    }

                    groupArray[nextPixel].firstIndex = currentFirst;
                    groupArray[nextPixel].group = currentGroup;
                    groupArray[nextPixel].lastIndex = nextLast;

                    nextPixel = groupArray[nextPixel].nextIndex;

                }

            }
        }
    }
}