static
CvHaarTrainigData* icvCreateHaarTrainingData( CvSize winsize, int maxnumsamples )
{
    CvHaarTrainigData* data;
    
    CV_FUNCNAME( "icvCreateHaarTrainingData" );
    
    __BEGIN__;

    data = NULL;
    uchar* ptr = NULL;
    size_t datasize = 0;
    
    datasize = sizeof( CvHaarTrainigData ) +
          /* sum and tilted */
        ( 2 * (winsize.width + 1) * (winsize.height + 1) * sizeof( sum_type ) +
          sizeof( float ) +      /* normfactor */
          sizeof( float ) +      /* cls */
          sizeof( float )        /* weight */
        ) * maxnumsamples;

    CV_CALL( data = (CvHaarTrainigData*) cvAlloc( datasize ) );
    memset( (void*)data, 0, datasize );
    data->maxnum = maxnumsamples;
    data->winsize = winsize;
    ptr = (uchar*)(data + 1);
    data->sum = cvMat( maxnumsamples, (winsize.width + 1) * (winsize.height + 1),
                       CV_SUM_MAT_TYPE, (void*) ptr );
    ptr += sizeof( sum_type ) * maxnumsamples * (winsize.width+1) * (winsize.height+1);
    data->tilted = cvMat( maxnumsamples, (winsize.width + 1) * (winsize.height + 1),
                       CV_SUM_MAT_TYPE, (void*) ptr );
    ptr += sizeof( sum_type ) * maxnumsamples * (winsize.width+1) * (winsize.height+1);
    data->normfactor = cvMat( 1, maxnumsamples, CV_32FC1, (void*) ptr );
    ptr += sizeof( float ) * maxnumsamples;
    data->cls = cvMat( 1, maxnumsamples, CV_32FC1, (void*) ptr );
    ptr += sizeof( float ) * maxnumsamples;
    data->weights = cvMat( 1, maxnumsamples, CV_32FC1, (void*) ptr );

    data->valcache = NULL;
    data->idxcache = NULL;

    __END__;

    return data;
}