void ORBDetectorDescriptor::computeOrientation( \
    std::vector<std::vector<cv::KeyPoint>>& pyramid_keypoints_per_level )
{
    // Compute orientation for every level keypoints
    for ( int level_j = 0; level_j < pyramid_num_level; ++level_j )
    {
        std::vector<cv::KeyPoint>& keypoints_level_j = pyramid_keypoints_per_level.at( level_j );
        cv::Mat image_level_j = pyramid_scaled_image.at( level_j ); // reference to same underlying data, no copy

        // Compute rotation for every keypoints
        for ( auto& keypoint_i : keypoints_level_j )
        {
            const uchar* keypoint_i_img_center = &image_level_j.at<uchar>( \
                cvRound( keypoint_i.pt.y ), cvRound( keypoint_i.pt.x ) );
            
            int m_01 = 0, m_10 = 0;

            for (int u = -HALF_EXTRACTOR_PATCH_SIZE; u <= HALF_EXTRACTOR_PATCH_SIZE; ++u)
            {
                m_10 += u * keypoint_i_img_center[u];
            }

            int img_step = (int)image_level_j.step1();

            for (int v = 1; v <= HALF_EXTRACTOR_PATCH_SIZE; ++v)
            {
                int v_sum = 0;
                int d = patch_umax.at( v );
                for (int u = -d; u <= d; ++u)
                {
                    int val_plus  = keypoint_i_img_center[u + v*img_step];
                    int val_minus = keypoint_i_img_center[u - v*img_step];

                    v_sum += (val_plus - val_minus);

                    m_10 += u * (val_plus + val_minus);
                }
                m_01 += v * v_sum;
            }

            // Compute angle
            keypoint_i.angle = cv::fastAtan2( float(m_01), float(m_10) );

        } // end for every keypoint
    } // end for every layer
}