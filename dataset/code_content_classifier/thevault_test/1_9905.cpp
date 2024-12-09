bool
VolumeAttributes::ChangesRequireRecalculation(const VolumeAttributes &obj) const
{
    if (opacityVariable != obj.opacityVariable)
        return true;
    if (resampleTarget != obj.resampleTarget)
        return true;
    if (rendererType != obj.rendererType)
        return true;
    if (smoothData != obj.smoothData)
        return true;

    if (rendererType == VolumeAttributes::RayCasting)
    {
        if (scaling != obj.scaling)
            return true;
        if (scaling == VolumeAttributes::Skew && skewFactor != obj.skewFactor)
            return true;
    }

    return false;
}