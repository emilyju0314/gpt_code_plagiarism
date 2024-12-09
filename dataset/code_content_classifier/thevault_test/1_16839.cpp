void clearMapToBlackWhite(map_t &map)
{
    // 0 = black
    // 255 = white

    for( int i = 1; i<map.size_y-1; i++)
        for(int j = 1; j<map.size_x-1; j++)
        {
            if(map.array[i][j] != WHITE_VALUE && map.array[i][j] != GRAY_VALUE && map.array[i][j] > 60)
                map.array[i][j] = WHITE_VALUE;       // set all values to white
            if(map.array[i][j] != WHITE_VALUE && map.array[i][j] != GRAY_VALUE && map.array[i][j] <= 60)
                map.array[i][j] = BLACK_VALUE;       // set all values to BLACK
        }
}