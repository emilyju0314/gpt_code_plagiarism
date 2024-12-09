void calcEdges(vector <pixelGroup>& groupArray, vector<edgeInfo>& edges, const long int numRows, 
    const long int numCols, const long int numPages, const vector<double>& Reliability){
    long int colIndex, rowIndex, pageIndex,count = 0;
    double rowEdge, columnEdge, pageEdge;

    for (long int index = 0; index < numRows * numCols * numPages; index++) {
        colIndex = index % numCols;
        rowIndex = ((index % (numRows * numCols)) - colIndex) / numCols;
        pageIndex = (index - rowIndex * numCols - colIndex) / (numRows * numCols);

        if (rowIndex < numRows - 1) {
            rowEdge = Reliability[get3Dindex(rowIndex, colIndex, pageIndex,numCols,numRows)]
                + Reliability[get3Dindex(rowIndex+1, colIndex, pageIndex, numCols, numRows)];
            edges[count].edgeType = 'r';
            edges[count].R = rowEdge;
            edges[count].row = rowIndex;
            edges[count].column = colIndex;
            edges[count].page = pageIndex;

            ++count;
        }

        if (colIndex < numCols - 1) {
            columnEdge = Reliability[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]
                + Reliability[get3Dindex(rowIndex, colIndex+1, pageIndex, numCols, numRows)];
            edges[count].edgeType = 'c';
            edges[count].R = columnEdge;
            edges[count].row = rowIndex;
            edges[count].column = colIndex;
            edges[count].page = pageIndex;

            ++count;
        }

        if (pageIndex < numPages - 1) {

            pageEdge = Reliability[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]
                + Reliability[get3Dindex(rowIndex, colIndex, pageIndex+1, numCols, numRows)];
            edges[count].edgeType = 'p';
            edges[count].R = columnEdge;
            edges[count].row = rowIndex;
            edges[count].column = colIndex;
            edges[count].page = pageIndex;

            ++count;
        }

        groupArray[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)].group = get3Dindex(rowIndex, colIndex, pageIndex,numCols,numRows);
        groupArray[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)].nextIndex = -1;
        groupArray[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)].lastIndex = get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows);
        groupArray[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)].firstIndex = get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows);
    }

}