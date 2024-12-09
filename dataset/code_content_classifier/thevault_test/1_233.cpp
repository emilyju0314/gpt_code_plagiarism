static
int icvGetHaarTrainingDataFromVec( CvHaarTrainingData* data, int first, int count,                                   
                                   CvIntHaarClassifier* cascade,
                                   const char* filename,
                                   int* consumed )
{
    int getcount = 0;

    CV_FUNCNAME( "icvGetHaarTrainingDataFromVec" );

    __BEGIN__;

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
            getcount = icvGetHaarTrainingData( data, first, count, cascade,
                icvGetHaarTraininDataFromVecCallback, &file, consumed, NULL);
            cvFree( &file.vector );
        }
        fclose( file.input );
    }

    __END__;

    return getcount;
}