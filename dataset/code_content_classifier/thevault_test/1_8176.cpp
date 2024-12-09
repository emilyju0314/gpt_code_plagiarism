void ORBDetectorDescriptor::computeBRISKDescriptorsPerPyramidLevel( \
    const cv::Mat& image, \
    std::vector<cv::KeyPoint>& keypoints, \
    cv::Mat& descriptors )
{
    // Zero out container
    descriptors = cv::Mat::zeros( keypoints.size(), 32, CV_8UC1 );

    const float factorPi = (float)(CV_PI/180.0);
    
    // step that opencv used to save image
    const int img_step = int(image.step);

    // Compute BRISK descriptor for every keypoint
    for ( size_t keypoint_idx = 0; keypoint_idx < keypoints.size(); ++keypoint_idx )
    {
        // Ptr to brisk random pair pattern
        const cv::Point* brisk_random_pattern_ptr = brisk_random_pattern.data();

        // Get reference to keypoint
        const cv::KeyPoint& keypoint_i = keypoints.at( keypoint_idx );

        // get the angle of the keypoint (and get the cos and sin value)
        float keypoint_i_angle = keypoint_i.angle * factorPi;
        float keypoint_i_cos = cos( keypoint_i_angle );
        float keypoint_i_sin = sin( keypoint_i_angle );

        // get the center of the keypoint in image
        const uchar* keypoint_i_img_center = &image.at<uchar>( \
            cvRound( keypoint_i.pt.y ), \
            cvRound( keypoint_i.pt.x ) );

        #define ORB_BRISK_GET_PATTERN( idx ) \
            keypoint_i_img_center[ \
                cvRound( brisk_random_pattern_ptr[ idx ].x * keypoint_i_sin + \
                         brisk_random_pattern_ptr[ idx ].y * keypoint_i_cos ) * img_step + \
                cvRound( brisk_random_pattern_ptr[ idx ].x * keypoint_i_cos - \
                         brisk_random_pattern_ptr[ idx ].y * keypoint_i_sin ) ]

        // Random sample 8 pixel pair around the the keypoint's image location center
        // NOTE: below for loop run for each keypoint
        for ( int i = 0; i < 32; ++i, brisk_random_pattern_ptr += 16 )
        {
            // t0, t1 : two random pixel define by brisk_random_pattern
            // val : use every bit to represent the descriptor result
            //      after the 8 pair finish, val contain 8 binary represent result
            int t0, t1, val;

            t0 = ORB_BRISK_GET_PATTERN( 0 ); 
            t1 = ORB_BRISK_GET_PATTERN( 1 );
            val = t0 < t1;

            t0 = ORB_BRISK_GET_PATTERN( 2 ); 
            t1 = ORB_BRISK_GET_PATTERN( 3 );
            val |= (t0 < t1) << 1;

            t0 = ORB_BRISK_GET_PATTERN( 4 ); 
            t1 = ORB_BRISK_GET_PATTERN( 5 );
            val |= (t0 < t1) << 2;

            t0 = ORB_BRISK_GET_PATTERN( 6 ); 
            t1 = ORB_BRISK_GET_PATTERN( 7 );
            val |= (t0 < t1) << 3;

            t0 = ORB_BRISK_GET_PATTERN( 8 ); 
            t1 = ORB_BRISK_GET_PATTERN( 9 );
            val |= (t0 < t1) << 4;

            t0 = ORB_BRISK_GET_PATTERN( 10 ); 
            t1 = ORB_BRISK_GET_PATTERN( 11 );
            val |= (t0 < t1) << 5;

            t0 = ORB_BRISK_GET_PATTERN( 12 ); 
            t1 = ORB_BRISK_GET_PATTERN( 13 );
            val |= (t0 < t1) << 6;

            t0 = ORB_BRISK_GET_PATTERN( 14 ); 
            t1 = ORB_BRISK_GET_PATTERN( 15 );
            val |= (t0 < t1) << 7;                

            descriptors.ptr(keypoint_idx)[ i ] = (uchar)val;
        }
    }
}