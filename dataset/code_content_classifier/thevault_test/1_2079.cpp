CUTBoolean
    savePPM( const char* file, unsigned char *data, 
             unsigned int w, unsigned int h, unsigned int channels) 
    {
        CUT_CONDITION( NULL != data);
        CUT_CONDITION( w > 0);
        CUT_CONDITION( h > 0);

        std::fstream fh( file, std::fstream::out | std::fstream::binary );
        if( fh.bad()) 
        {
            std::cerr << "savePPM() : Opening file failed." << std::endl;
            return CUTFalse;
        }

        if (channels == 1)
        {
            fh << "P5\n";
        }
        else if (channels == 3) {
            fh << "P6\n";
        }
        else {
            std::cerr << "savePPM() : Invalid number of channels." << std::endl;
            return CUTFalse;
        }

        fh << w << "\n" << h << "\n" << 0xff << std::endl;

        for( unsigned int i = 0; (i < (w*h*channels)) && fh.good(); ++i) 
        {
            fh << data[i];
        }
        fh.flush();

        if( fh.bad()) 
        {
            std::cerr << "savePPM() : Writing data failed." << std::endl;
            return CUTFalse;
        } 
        fh.close();

        return CUTTrue;
    }