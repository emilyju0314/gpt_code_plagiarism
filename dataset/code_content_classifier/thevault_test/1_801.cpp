void generateData( Mat& data, Mat& labels, const vector<int>& sizes, const vector<Mat>& means, const vector<Mat>& covs, int labelType )
{
    vector<int>::const_iterator sit = sizes.begin();
    int total = 0;
    for( ; sit != sizes.end(); ++sit )
        total += *sit;
    assert( means.size() == sizes.size() && covs.size() == sizes.size() );
    assert( !data.empty() && data.rows == total );
    assert( data.type() == CV_32FC1 );
    
    labels.create( data.rows, 1, labelType );

    randn( data, Scalar::all(0.0), Scalar::all(1.0) );
    vector<Mat>::const_iterator mit = means.begin(), cit = covs.begin();
    int bi, ei = 0;
    sit = sizes.begin();
    for( int p = 0, l = 0; sit != sizes.end(); ++sit, ++mit, ++cit, l++ )
    {
        bi = ei;
        ei = bi + *sit;
        assert( mit->rows == 1 && mit->cols == data.cols );
        assert( cit->rows == data.cols && cit->cols == data.cols );
        for( int i = bi; i < ei; i++, p++ )
        {
            Mat r(1, data.cols, CV_32FC1, data.ptr<float>(i));
            r =  r * (*cit) + *mit; 
            if( labelType == CV_32FC1 )
                labels.at<float>(p, 0) = (float)l;
            else
                labels.at<int>(p, 0) = l;
        }
    }
}