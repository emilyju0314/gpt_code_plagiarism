void patternSearch(char grid[R][C], string word)
{
    // Consider every point as starting point and search
    // given word
    for (int row = 0; row < R; row++)
       for (int col = 0; col < C; col++)
          if (search2D(grid, row, col, word))
             cout << "pattern found at " << row << ", "
                  << col << endl;
}