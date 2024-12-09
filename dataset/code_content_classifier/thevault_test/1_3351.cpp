point_vector remove_extrinsic_degeneracy ( point_vector points, ues::log::logger & lg, const ues::math::numeric_type & epsilon ) noexcept
{
    // If there is only one point, there cannot be any degeneracy.
    if ( points.size() <= 1 )
        return points;

    // Make a copy of the point vector (only maintaining pointers) and sort it.
    std::vector< const ues::geom::point<2> * > copy;
    std::for_each ( points.begin(), points.end(), [&copy] ( const ues::geom::point<2> & point ) { copy.push_back ( &point ); } );
    std::sort ( copy.begin(), copy.end(), [] ( const ues::geom::point<2> * first, const ues::geom::point<2> * second ) { return first->get_x() < second->get_x(); } );

    // Detect whether or not degeneracy exists in the given set of points and
    // get the (non-zero) minimum x distance between any 2 points.
    bool degeneracy_detected = false;
    ues::math::numeric_type min_x_difference = copy.back()->get_x() - copy.front()->get_x();

    {
        auto it = copy.begin();
        ues::math::numeric_type previous_x_coord = ( *it++ )->get_x();

        while ( it != copy.end() )
        {
            ues::math::numeric_type current_x_coord = ( *it++ )->get_x();
            ues::math::numeric_type x_difference = current_x_coord - previous_x_coord;
            if ( x_difference > epsilon )
            {
                if ( x_difference < min_x_difference )
                {
                    min_x_difference = x_difference;
                }
            }
            else
            {
                degeneracy_detected = true;
            }
            previous_x_coord = current_x_coord;
        }
    }

    if ( degeneracy_detected )
    {
        // If degeneracy was detected, then the points must be transformed.

        // Get the maximum y distance between any 2 points.
        auto minmax = std::minmax_element ( copy.begin(), copy.end(), [] ( const ues::geom::point<2> * first, const ues::geom::point<2> * second ) { return first->get_y() < second->get_y(); } );
        ues::math::numeric_type max_y_difference = ( *minmax.second )->get_y() - ( *minmax.first )->get_y();

        // Compute the rotation angle
        ues::math::numeric_type angle = std::atan2 ( max_y_difference, min_x_difference );

        // A 3x3 matrix for homogeneous 2D transformation
        ues::math::matrix transformation = ues::geom::rotation_matrix_2d ( angle / 2 );

        // Apply the transformation
        std::for_each ( points.begin(), points.end(), [&transformation] ( ues::geom::point<2> & point ) { point.transform ( transformation ); } );

        if ( lg.min_level() <= ues::log::TRACE_LVL )
        {
            ues::log::event e ( ues::log::TRACE_LVL, component_name, "Extrinsic degeneration removed" );
            e.message() << "Points rotated " << angle << " rad.\n";
            e.message() << "Points: ";
            std::for_each ( points.begin(), points.end(), [&e] ( const ues::geom::point<2> & point ) { e.message() << point << ", "; } );
            e.message() << '\n';
            lg.record ( std::move ( e ) );
        }

    }

    return points;
}