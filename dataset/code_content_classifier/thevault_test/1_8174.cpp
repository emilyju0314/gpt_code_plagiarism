void ORBDetectorDescriptor::computePyramid( const cv::Mat& image )
{

    for (int level_i = 0; level_i < pyramid_num_level; ++level_i) 
    {    
        float level_i_inv_scale = pyramid_inv_scale_factors.at( level_i );

        cv::Size level_i_scale_size( cvRound((float) image.cols * level_i_inv_scale ), \
                                     cvRound((float) image.rows * level_i_inv_scale ));

        cv::Size level_i_whole_size( level_i_scale_size.width + PYRAMID_EDGE_SIZE * 2, \
                                     level_i_scale_size.height + PYRAMID_EDGE_SIZE * 2 );
        
        // Tmp image that contain border on both side
        // We only need the center part of this tmp image
        cv::Mat tmp_image( level_i_whole_size, image.type() );

        // NOTE: cv::Mat operator ( cv::Rect ) is shallow copy
        // when below line run, `pyramid_scaled_image[ level_i ]` and `tmp_image` all refer to the same underlying data
        // `pyramid_scaled_image[ level_i ]` point to the region of interest specified by cv::Rect
        // when the for loop finish, `tmp_image` out of scope, the reference count to that particular data - 1
        // but the `pyramid_scaled_image[ level_i ]` still point to that data
        pyramid_scaled_image.at( level_i ) = tmp_image( cv::Rect( PYRAMID_EDGE_SIZE, \
                                                               PYRAMID_EDGE_SIZE, \
                                                               level_i_scale_size.width, \
                                                               level_i_scale_size.height ) );

        // Compute the resized image
        // For non first layer image, resize + padding border
        if ( level_i != 0) 
        {
            // Use previous layer + resize to generate current layer
            cv::resize( pyramid_scaled_image.at( level_i -1 ), \
                        pyramid_scaled_image.at( level_i ), \
                        level_i_scale_size, 0, 0, cv::INTER_LINEAR );

            // Padding the resized to tmp
            // https://docs.opencv.org/3.4/dc/da3/tutorial_copyMakeBorder.html
            // Below line change data in tmp_image, and thus change the `pyramid_scaled_image[ level_i ]` that share the same data
            cv::copyMakeBorder( pyramid_scaled_image.at(  level_i ), tmp_image, \
                PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, \
                cv::BorderTypes::BORDER_REFLECT_101 + cv::BorderTypes::BORDER_ISOLATED);
        }
        // For first layer image, padding border
        else 
        {
            cv::copyMakeBorder( image, tmp_image, \
                PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, PYRAMID_EDGE_SIZE, \
                cv::BorderTypes::BORDER_REFLECT_101 );
        }
    }
}