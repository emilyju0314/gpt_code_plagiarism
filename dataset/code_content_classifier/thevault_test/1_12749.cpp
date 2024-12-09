void GrahamScan::partition_points()
    {
        //
        // Step one in partitioning the points is to sort the raw data
        //
        std::sort( raw_points.begin(), raw_points.end() );
        //
        // The the far left and far right points, remove them from the
        // sorted sequence and store them in special members
        //
        left = raw_points.front();
        raw_points.erase( raw_points.begin() );
        right = raw_points.back();
        raw_points.pop_back();
        //
        // Now put the remaining points in one of the two output sequences
        //
        for ( size_t i = 0 ; i < raw_points.size() ; i++ )
        {
            double dir = direction( left, right, raw_points[ i ] );
            if ( dir < 0 )
                upper_partition_points.push_back( raw_points[ i ] );
            else
                lower_partition_points.push_back( raw_points[ i ] );
        }
    }