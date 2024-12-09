inline float GetTimeFragment ()
{
    const float t = XPLMGetDataf(dr_time);
    return std::fmod(t, PLANE_CIRCLE_TIME_S) / PLANE_CIRCLE_TIME_S;
}