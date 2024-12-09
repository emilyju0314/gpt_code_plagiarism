seconds TimeToAccelerateOverDistance(const mmM& initial_velocity, const mm& distance, const mmS2& acceleration_arg)
{
    if (distance == 0.0f)
        return seconds(0.0f);
    if (acceleration_arg <= 0.0f && initial_velocity <= 0.0f)
        return seconds(NAN); // you can't decelerate from zero

    mmS velocity_S(initial_velocity);

    /*
    bool test = false;
    float up = (-velocity_S + sqrt(velocity_S*velocity_S + 2.0f * acceleration_arg * distance)) / acceleration_arg;
    float down = (-velocity_S - sqrt(velocity_S*velocity_S + 2.0f * acceleration_arg * distance)) / acceleration_arg;
    if (isnan(up))
        test = true;
    */


    // standard quadratic solver
    return (sqrt(velocity_S*velocity_S + 2.0f * acceleration_arg * distance) - velocity_S) / acceleration_arg;

    // Citardauq quadratic solver
    //return (2.0f * -distance) / (-velocity_S - sqrt(velocity_S*velocity_S + 2.0f * acceleration_arg * distance));
}