static
int icvInitBackgroundReaders( const char* filename, CvSize winsize )
{
    if( cvbgdata == NULL && filename != NULL )
    {
        cvbgdata = icvCreateBackgroundData( filename, winsize );
    }

    if( cvbgdata )
    {

        #ifdef CV_OPENMP
        #pragma omp parallel
        #endif /* CV_OPENMP */
        {
            #ifdef CV_OPENMP
            #pragma omp critical(c_create_bg_data)
            #endif /* CV_OPENMP */
            {
                if( cvbgreader == NULL )
                {
                    cvbgreader = icvCreateBackgroundReader();
                }
            }
        }

    }

    return (cvbgdata != NULL);
}