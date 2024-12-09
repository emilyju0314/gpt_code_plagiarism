void
VolumeAttributes::GetTransferFunction(unsigned char *rgba) const
{
    unsigned char rgb[256 * 3];
    unsigned char alphas[256];
    const unsigned char *a_ptr;

    // Figure out the colors
    colorControlPoints.GetColors(rgb, 256);
    // Figure out the opacities
    if(freeformFlag)
        a_ptr = freeformOpacity;
    else
    {
        GetGaussianOpacities(alphas);
        a_ptr = alphas;
    }

    unsigned char *rgb_ptr = rgb;
    unsigned char *rgba_ptr = rgba;
    for(int i = 0; i < 256; ++i)
    {
        // Copy the color
        *rgba_ptr++ = *rgb_ptr++;
        *rgba_ptr++ = *rgb_ptr++;
        *rgba_ptr++ = *rgb_ptr++;
        // Copy the alpha
        *rgba_ptr++ = *a_ptr++;
    }
}