positionTy FindCenterPos (float dist)
{
    // Current user's plane's position and heading (relative to Z)
    positionTy pos = {
        XPLMGetDatad(dr_x),
        XPLMGetDatad(dr_y),
        XPLMGetDatad(dr_z)
    };
    float heading = XPLMGetDataf(dr_heading);

    // Move point 200m away from aircraft, direction of its heading
    const double head_rad = deg2rad(heading);
    pos.x += sin(head_rad) * dist;              // east axis
    pos.z -= cos(head_rad) * dist;              // south axis

    return pos;
}