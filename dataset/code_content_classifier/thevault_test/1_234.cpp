static
int icvGetHaarTrainingDataFromBG( CvHaarTrainingData* data, int first, int count,
                                  CvIntHaarClassifier* cascade, double* acceptance_ratio, const char * filename = NULL )
{
    CV_FUNCNAME( "icvGetHaarTrainingDataFromBG" );

    __BEGIN__;

    if (filename)
    {
        CvVecFile file;
        short tmp = 0;    
        
        file.input = NULL;
        if( filename ) file.input = fopen( filename, "rb" );

        if( file.input != NULL )
        {
            fread( &file.count, sizeof( file.count ), 1, file.input );
            fread( &file.vecsize, sizeof( file.vecsize ), 1, file.input );
            fread( &tmp, sizeof( tmp ), 1, file.input );
            fread( &tmp, sizeof( tmp ), 1, file.input );
            if( !feof( file.input ) )
            {
                if( file.vecsize != data->winsize.width * data->winsize.height )
                {
                    fclose( file.input );
                    CV_ERROR( CV_StsError, "Vec file sample size mismatch" );
                }

                file.last = 0;
                file.vector = (short*) cvAlloc( sizeof( *file.vector ) * file.vecsize );
                icvGetHaarTrainingData( data, first, count, cascade,
                    icvGetHaarTraininDataFromVecCallback, &file, NULL, acceptance_ratio);
                cvFree( &file.vector );
            }
            fclose( file.input );
        }
    }
    else
    {
        icvGetHaarTrainingData( data, first, count, cascade,
            icvGetHaarTrainingDataFromBGCallback, NULL, NULL, acceptance_ratio);
    }

    __END__;

    return count;
}