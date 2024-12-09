ues::math::numeric_type compute_angle ( const ues::geom::point<2> & origin, const ues::geom::point<2> & end, const ues::math::numeric_type & epsilon )
{
    ues::math::numeric_type result = origin.angle_to ( end ) - ues::math::pi / 2;

    if ( result < -epsilon )
        result += 2 * ues::math::pi;

    return result;
}