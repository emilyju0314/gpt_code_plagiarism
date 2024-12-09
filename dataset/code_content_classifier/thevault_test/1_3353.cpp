void compute_rank ( const point_vector & points,
                    const point_index_vector & sorted_points,
                    point_index origin,
                    rank_vector & ranks,
                    rank_vector & unsorted_ranks,
                    angle_vector & angles,
                    ues::log::logger & lg,
                    const ues::math::numeric_type & epsilon )
{
    const ues::geom::point<2> & origin_point = points.at ( origin );

    unsorted_ranks.resize ( points.size() );

    ues::math::numeric_type last_angle = 0;
    point_rank current_rank = 0;
    std::unordered_set<point_index> zero_points;

    angles.push_back ( last_angle );

    for ( point_index p : sorted_points )
    {
        ues::math::numeric_type current_angle = compute_angle ( origin_point, points.at ( p ), epsilon );

        if ( std::abs ( current_angle ) <= epsilon )
        {
            if ( last_angle > epsilon )
            {
                current_angle = 2 * ues::math::pi;
            }
            else
            {
                // Differenciate segment splitting points, as they appear
                // twice in the sorted_points list.
                if ( zero_points.find ( p ) != zero_points.end() )
                {
                    current_angle = 2 * ues::math::pi;
                }
                else
                {
                    zero_points.insert ( p );
                }
            }
        }

        if ( current_angle + epsilon < last_angle )
        {
            std::ostringstream error;
            error << "The points are not correctly sorted. Current angle is " << current_angle << " rad, previous angle was " << last_angle << " rad.\n";
            error << "Provided sorted points (from " << points [origin] << ") were:\n";
            for ( point_index ep : sorted_points )
            {
                error << ep << ". " << points[ep] << " [" << compute_angle ( origin_point, points[ep], epsilon ) << " rad]";
                if ( p == ep )
                {
                    error << " (current)";
                }
                error << '\n';
            }
            error << "Duplicated points may be a cause for incorrect sorting";
            throw ues::exc::exception ( error.str(), UES_CONTEXT );
        }

        if ( current_angle > last_angle + epsilon )
        {
            ranks.push_back ( ++current_rank );
            angles.push_back ( current_angle );
        }
        else
        {
            ranks.push_back ( current_rank );
        }
        last_angle = current_angle;
        if ( current_angle != 2 * ues::math::pi )
        {
            unsorted_ranks[p] = current_rank;
        }
    }

    if ( last_angle < 2 * ues::math::pi )
    {
        angles.push_back ( 2 * ues::math::pi );
    }

    if ( lg.min_level() <= ues::log::TRACE_LVL )
    {
        ues::log::event e ( ues::log::TRACE_LVL, component_name, "Finished computing point ranks" );
        e.message() << "Ranks: ";
        std::for_each ( ranks.cbegin(), ranks.cend(), [&e] ( const point_rank pr ) { e.message() << pr << ", "; } );
        e.message() << '\n' << "Unsorted ranks: ";
        std::for_each ( unsorted_ranks.cbegin(), unsorted_ranks.cend(), [&e] ( const point_rank pr ) { e.message() << pr << ", "; } );
        e.message() << '\n';
        e.message() << '\n' << "Angles: ";
        std::for_each ( angles.cbegin(), angles.cend(), [&e] ( const ues::math::numeric_type & a ) { e.message() << a << ", "; } );
        e.message() << '\n';
        lg.record ( std::move ( e ) );
    }

}