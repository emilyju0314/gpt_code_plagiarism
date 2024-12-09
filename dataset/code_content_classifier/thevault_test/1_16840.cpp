void fillGrayGradient(map_t &map, int blockSize)
{
    int grayValue = BLACK_VALUE;  // begin with black
    int halfBlock;

    if(blockSize >= 3)
        halfBlock = (blockSize-1) / 2;
    else
        halfBlock = 1;

    for(int iteration = 0; iteration < 800; iteration++, grayValue+=5)    // get brighter
        for( int i = 0; i < map.size_y; i++)
            for(int j = 0; j < map.size_x; j++)
            {
                if(map.array[i][j] == grayValue)
                {
                    setBlockToGrayvalue(map, i, j, grayValue + 5, halfBlock);
                }
            }
}