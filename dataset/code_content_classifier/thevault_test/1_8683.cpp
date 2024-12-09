void calcReliability(vector<double>& Reliability, const double* unwrappedImage, const int& numRows, 
    const int& numCols, const long int numPages) {
    //horizontal, vertical, in-plane diagonals, page, through-page diagonals.
    double H, V, D1, D2;
    double P = 0, PD1 = 0, PD2 = 0, PD3 = 0, PD4 = 0;
    //End result stored in D
    double D;
    int colIndex, rowIndex, pageIndex;

    for (int index = 0; index < numRows * numCols * numPages; index++) {
        //protect against out of range errors hopefully. Had some past issues in that regard.
        try {
            colIndex = index % numCols;
            rowIndex = ((index % (numRows * numCols)) - colIndex) / numCols;
            pageIndex = (index - rowIndex * numCols - colIndex) / (numRows * numCols);

            if (rowIndex > 0 && rowIndex < numRows - 1 && colIndex > 0 && colIndex < numCols - 1) {
                H = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex-1, colIndex, pageIndex, numCols, numRows)],
                    unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                    pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex+1, colIndex, pageIndex, numCols, numRows)]);

                V = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex-1, pageIndex, numCols, numRows)],
                    unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                    pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex+1, pageIndex, numCols, numRows)]);

                D1 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex-1, colIndex-1, pageIndex, numCols, numRows)],
                    unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                    pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex+1, colIndex+1, pageIndex, numCols, numRows)]);

                D2 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex-1, colIndex+1, pageIndex, numCols, numRows)],
                    unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                    pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex+1, colIndex-1, pageIndex, numCols, numRows)]);
                
                if (pageIndex > 0 && pageIndex < numPages - 1) {
                    P = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex - 1, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                        pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                            unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex + 1, numCols, numRows)]);
                    
                    PD1 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex - 1, colIndex - 1, pageIndex - 1, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                        pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                            unwrappedImage[get3Dindex(rowIndex + 1, colIndex + 1, pageIndex + 1, numCols, numRows)]);
                    
                    PD2 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex + 1, colIndex - 1, pageIndex - 1, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                        pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                            unwrappedImage[get3Dindex(rowIndex - 1, colIndex + 1, pageIndex + 1, numCols, numRows)]);
                    
                    PD3 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex - 1, colIndex + 1, pageIndex - 1, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                        pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                            unwrappedImage[get3Dindex(rowIndex + 1, colIndex - 1, pageIndex + 1, numCols, numRows)]);
                    
                    PD4 = pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex + 1, colIndex + 1, pageIndex - 1, numCols, numRows)],
                        unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)]) -
                        pairwiseUnwrap(unwrappedImage[get3Dindex(rowIndex, colIndex, pageIndex, numCols, numRows)],
                            unwrappedImage[get3Dindex(rowIndex - 1, colIndex - 1, pageIndex + 1, numCols, numRows)]);
                    
                }
                
                D = sqrt(H * H + V * V + D1 * D1 + D2 * D2 + P * P + PD1 * PD1 + PD2 * PD2 + PD3 * PD3 + PD4 * PD4);
                Reliability[index] = 1 / D;

            }
            else {
                Reliability[index] = 0.0;
            }
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            return;
        }
    }
}