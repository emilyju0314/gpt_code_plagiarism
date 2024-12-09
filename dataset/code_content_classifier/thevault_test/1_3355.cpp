void complete_visibility ( const point_vector & points,
                           const point_index origin,
                           const visibility_problem_solver::visible_point_vector & visible_points,
                           const segment_index_vector & segment_equivalence,
                           const polygon_self_occlusion & polygon_occlusion_info,
                           visibility_graph & graph )
{
    const ues::geom::point<2> & origin_point = points.at ( origin );

    for ( point_vector::size_type i = 0; i < points.size(); ++i )
    {
        const ues::geom::point<2> & destination_point = points.at ( i );
        segment_index self_occluding_segment_index;
        if ( polygon_occlusion_info.check_occluding_segment ( origin, i, self_occluding_segment_index ) )
        {
            graph.add_occlusion_segment ( origin_point, destination_point, self_occluding_segment_index );
        }
        else
        {
            if ( visible_points[i].visible )
            {
                graph.add_visibility ( origin_point, destination_point, origin_point.distance_to ( destination_point ) );
            }
            else
            {
                if ( visible_points[i].segment != NULL_SEGMENT_INDEX )
                {
                    graph.add_occlusion_segment ( origin_point, destination_point, segment_equivalence[ visible_points[i].segment ] );
                }
            }
        }
    }
}