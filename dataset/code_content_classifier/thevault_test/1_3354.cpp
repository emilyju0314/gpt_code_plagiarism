void split_segments ( const scenario & current_scenario,
                      const point_index_vector & sorted_points,
                      const point_index origin,
                      scenario & fixed_scenario,
                      point_index_vector & fixed_sorted_points,
                      segment_index_vector & segment_equivalence,
                      ues::log::logger & lg )
{
    const ues::geom::point<2> & origin_point = current_scenario.get_points() [origin];

    point_vector fixed_points = current_scenario.get_points();
    segment_vector fixed_segments = current_scenario.get_segments();
    polygon_vector fixed_polygons;

    // Generate a map to be able to check if a point already exists.
    point_map added_points;
    for ( point_index i = 0; i < fixed_points.size(); ++i )
    {
        added_points.insert ( std::make_pair ( fixed_points[i], i ) );
    }

    segment_equivalence.resize ( fixed_segments.size() );
    for ( segment_index_vector::size_type i = 0; i < fixed_segments.size(); ++i )
    {
        segment_equivalence[i] = i;
    }

    for ( const polygon & p : current_scenario.get_polygons() )
    {
        polygon fixed_p;
        for ( const segment_index si : p )
        {
            // Add the segment to the fixed polygon.
            fixed_p.push_back ( si );

            // Check if the segment crosses the positive y-axis.
            const ues::geom::point<2> & p1 = current_scenario.get_points() [ fixed_segments[si].first ];
            const ues::geom::point<2> & p2 = current_scenario.get_points() [ fixed_segments[si].second ];

            if ( ( p1.get_x() <= origin_point.get_x() && origin_point.get_x() < p2.get_x() )
                    || ( p2.get_x() <= origin_point.get_x() && origin_point.get_x() < p1.get_x() ) )
            {
                ues::math::numeric_type dist1 = std::abs ( p1.get_x() - origin_point.get_x() );
                ues::math::numeric_type dist2 = std::abs ( p2.get_x() - origin_point.get_x() );

                ues::math::numeric_type intersection_y = p2.get_y() + ( p1.get_y() - p2.get_y() ) * dist2 / ( dist1 + dist2 );

                if ( intersection_y > origin_point.get_y() )
                {
                    // There is an intersection point.

                    // Add new point only if it hasn't been added before.
                    ues::geom::point<2> intersection_point ( origin_point.get_x(), intersection_y );
                    point_index intersection_point_index = add_if_not_present ( fixed_points, added_points, std::move ( intersection_point ) );

                    // Modify segments.
                    segment new_segment ( intersection_point_index, fixed_segments[si].second );
                    fixed_segments[si].second = intersection_point_index;
                    fixed_segments.push_back ( std::move ( new_segment ) );
                    segment_equivalence.push_back ( si );

                    // Add new segment to the polygon.
                    fixed_p.push_back ( fixed_segments.size() - 1 );

                }
            }
        }
        fixed_polygons.push_back ( std::move ( fixed_p ) );
    }

    // Add the new points at the start of the sorting
    for ( point_index_vector::size_type i = current_scenario.get_points().size(); i < fixed_points.size(); ++i )
    {
        fixed_sorted_points.push_back ( i );
    }
    // Add the rest of the ponts
    fixed_sorted_points.insert ( fixed_sorted_points.end(), sorted_points.begin(), sorted_points.end() );
    // Add the new points also at the end of the sorting
    for ( point_index_vector::size_type i = current_scenario.get_points().size(); i < fixed_points.size(); ++i )
    {
        fixed_sorted_points.push_back ( i );
    }

    fixed_scenario = scenario ( std::move ( fixed_points ), std::move ( fixed_segments ), std::move ( fixed_polygons ) );

    if ( lg.min_level() <= ues::log::TRACE_LVL )
    {
        ues::log::event e ( ues::log::TRACE_LVL, component_name, "Finished splitting segments" );
        e.message() << "Points: ";
        std::for_each ( fixed_scenario.get_points().cbegin(), fixed_scenario.get_points().cend(), [&e] ( const ues::geom::point<2> & p ) { e.message() << p << ", "; } );
        e.message() << '\n' << "Segments: ";
        std::for_each ( fixed_scenario.get_segments().cbegin(), fixed_scenario.get_segments().cend(), [&e] ( const segment & se ) { e.message() << "( " << se.first << " - " << se.second << " ), "; } );
        e.message() << '\n' << "Polygons: ";
        std::for_each ( fixed_scenario.get_polygons().cbegin(), fixed_scenario.get_polygons().cend(), [&e] ( const polygon & po )
        {
            e.message() << "( ";
            std::for_each ( po.cbegin(), po.cend(), [&e] ( const segment_index & si ) { e.message() << si << " "; } );
            e.message() << "), ";
        } );
        e.message() << '\n' << "Sorted point indices: ";
        std::for_each ( fixed_sorted_points.begin(), fixed_sorted_points.end(), [&e] ( const point_index p ) { e.message() << p << ", "; } );
        e.message() << '\n';
        lg.record ( std::move ( e ) );
    }

}