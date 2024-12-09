void CirclePos (positionTy& pos,
                float heading,
                float radius)
{
    const double head_rad = deg2rad(heading);
    pos.x += radius * sin(head_rad);        // east axis
    pos.z -= radius * cos(head_rad);        // south axis
}