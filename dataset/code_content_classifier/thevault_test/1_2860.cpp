int searchString(string needle, int row, int col,
                  string str[], int row_count,
                                int col_count)
{
    int found = 0;
    int r, c;
 
    for (r = 0; r < row_count; ++r)
    {
        for (c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str,
                                    row_count - 1,
                                    col_count - 1, 0);
        }
    }
    return found;
}