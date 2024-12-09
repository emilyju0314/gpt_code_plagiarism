int internalSearch(string needle, int row,
                   int col, string hay[],
                   int row_max, int col_max, int xx)
{
    int found = 0;
 
    if (row >= 0 && row <= row_max && col >= 0 &&
        col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;
 
        hay[row][col] = 0;
 
        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {
 
            // through Backtrack searching
            // in every directions
            found += internalSearch(needle, row,
                                    col + 1, hay,
                                    row_max, col_max,xx);
            found += internalSearch(needle, row, col - 1,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row + 1, col,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row - 1, col,
                                    hay, row_max, col_max,xx);
        }
        hay[row][col] = match;
    }
    return found;
}