void ConvLocalToWorld (const positionTy& pos,
                       double& lat, double& lon, double& alt)
{
    XPLMLocalToWorld(pos.x, pos.y, pos.z,
                     &lat, &lon, &alt);
}