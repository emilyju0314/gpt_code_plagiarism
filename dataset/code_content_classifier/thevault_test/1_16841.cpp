void saveMapToFile(map_t &map, std::string const&path, bool append)
{
    ofstream f_MapOutput;
    if(append)
        f_MapOutput.open(path, std::ios_base::app);
    else
        f_MapOutput.open(path, std::ios_base::trunc);

    f_MapOutput << "P2\n" << map.size_x << " " << map.size_y << " " << WHITE_VALUE << endl;

    for( int i = 0; i< map.size_y; i++)
    {
        for(int j = 0; j< map.size_x; j++)
        {
            f_MapOutput << map.array[i][j]<< " ";
        }
        f_MapOutput << endl;
    }


    f_MapOutput.close();
}