void ORBDetectorDescriptor::computeFASTKeyPointQuadTree( \
    std::vector<std::vector<cv::KeyPoint>> &pyramid_keypoints_per_level )
{
    // To ensure relative even/uniform keypoint detected across images
    // image is divided into multiple grid
    // an adaptive threshold is used to extract FAST keypoint from every grid

    // cell size
    const int cell_size = 35;

    // itr through the whole pyramid and process each layer.
    for (int level_i = 0; level_i < pyramid_num_level; level_i++) 
    {
        // get the ROI image area of current layer
        // FAST run in radious of 3, thus we can't run fast starting from the (0,0) boundary
        const int roi_min_x = PYRAMID_EDGE_SIZE - 3; // 3 is the radius set for the FAST calculation 
        const int roi_min_y = PYRAMID_EDGE_SIZE - 3;
        const int roi_max_x = pyramid_scaled_image.at( level_i ).cols - roi_min_x;
        const int roi_max_y = pyramid_scaled_image.at( level_i ).rows - roi_min_x;

        const int roi_range_x = roi_max_x - roi_min_x;
        const int roi_range_y = roi_max_y - roi_min_y;

        // get the amount of grids we have within current layer
        // this is equivalent of taking floor
        const int num_cell_x = roi_range_x / cell_size;
        const int num_cell_y = roi_range_y / cell_size;

        // calculate the size of each grid
        // cell_size_x/y might be diff from original cell_size due to boundary
        const int cell_size_x = std::ceil( roi_range_x * 1.0f / num_cell_x );
        const int cell_size_y = std::ceil( roi_range_y * 1.0f / num_cell_y );

        // Container that tmp store keypoints
        // Those keypoints will be "distributed" uniformly across images using octree
        std::vector<cv::KeyPoint> keypoints_to_distribute_level_i;
        keypoints_to_distribute_level_i.reserve( num_features * 10 );

        // traverse all the cell to compute fast on each cell
        for ( int cell_y_i = 0; cell_y_i < num_cell_y; cell_y_i++ )
        {
            // current cell start index ( y )
            const int cell_y_i_start = cell_y_i * cell_size_y + roi_min_y;

            // current cell end index ( y )
            // +6 account for FAST 3 pixel border
            // consider potential out of bound issue
            const int cell_y_i_end = ( cell_y_i_start + cell_size_y + 6 > roi_max_x ? roi_max_x : cell_y_i_start + cell_size_y + 6 );

            // out of bound
            if ( cell_y_i_start > roi_max_y - 3 )
                continue;

            for ( int cell_x_j = 0; cell_x_j < num_cell_x; cell_x_j++ )
            {
                const int cell_x_j_start = cell_x_j * cell_size_x + roi_min_x;
                const int cell_x_j_end = ( cell_x_j_start + cell_size_x + 6 > roi_max_x ? roi_max_x : cell_x_j_start + cell_size_x + 6 );

                // out of bound
                if  (cell_x_j_start > roi_max_x - 3 )
                    continue;

                // Current grid is defined as
                // [ cell_y_i_start, cell_y_i_end ) x [ cell_x_j_start, cell_x_j_end )

                // all of the keypoints within this grid.
                std::vector<cv::KeyPoint> curr_cell_keypoints;

                // OpenCV's FAST detector, first try, with higher threshold.
                // use rowRange colRange to specify only run on the current grid part
                cv::FAST( pyramid_scaled_image.at( level_i ).rowRange( cell_y_i_start, cell_y_i_end ).colRange( cell_x_j_start, cell_x_j_end ), \
                    curr_cell_keypoints, fast_default_threshold, true );

                // adaptive methods, if default threshold do not detect any feature, try lower threshold
                // If still unable to detect any keypoint, give up
                if ( curr_cell_keypoints.empty() )
                    cv::FAST( pyramid_scaled_image.at( level_i ).rowRange( cell_y_i_start, cell_y_i_end).colRange( cell_x_j_start, cell_x_j_end ), \
                        curr_cell_keypoints, fast_min_threshold, true );

                if ( !curr_cell_keypoints.empty() )
                {
                    for ( auto& cell_keypoints_i : curr_cell_keypoints )
                    {
                        // Convert FAST location back to original image coordinate
                        cell_keypoints_i.pt.x += cell_x_j * cell_size_x;
                        cell_keypoints_i.pt.y += cell_y_i * cell_size_y;

                        // Save to tmp container
                        keypoints_to_distribute_level_i.emplace_back( cell_keypoints_i );
                    }
                }
            } // end iterate cell x
        } // end iterate cell y

        // store a reference to all the keypoints that belongs to the current layer
        std::vector<cv::KeyPoint>& keypoints_level_i = pyramid_keypoints_per_level.at( level_i );
        keypoints_level_i.reserve( pyramid_num_features_per_level.at( level_i ) );

        // NOTE: number of keypoints in `keypoints_to_distribute_level_i` may exceed the expected keypoints at current layer
        //      during the quad tree distribution process, we will eliminate those keypoints.
        QuadTreeDistributePerPyramidLevel( \
            keypoints_to_distribute_level_i, \
            keypoints_level_i, \
            roi_min_x, roi_max_x, \
            roi_min_y, roi_max_y, \
            pyramid_num_features_per_level.at( level_i ), \
            level_i );
        
        const int patch_size_level_i = EXTRACTOR_PATCH_SIZE * pyramid_scale_factors.at( level_i );

        // traverse all feature points and restore their coordinates under current layer
        // NOTE: coordinate is set to current layer, not the gloabl layer (layer 0)
        // This is mainly because we need to compute orientation based on per image level keypoints location
        for ( auto& keypoints_level_i_j : keypoints_level_i )
        {
            keypoints_level_i_j.pt.x += roi_min_x;
            keypoints_level_i_j.pt.y += roi_min_y;
            keypoints_level_i_j.octave = level_i;
            keypoints_level_i_j.size = patch_size_level_i;
        }
    } // end of level i
}