DisplayRGB
ClampToGamut(DisplayRGB &rgb)
{
    float fLum, t;
    DisplayRGB rgbClamped;

    fLum = Luminance(rgb);
    if (fLum < 0.0)
        return DisplayRGB(0.0);
    else if (fLum > 1.0)
        return DisplayRGB(1.0);
    else {
        //
        //  Use clipping to find the intersection of the RGB cube
        //  with the ray from (fLum, fLum, fLum) to (rgb.red, rgb.grn, rgb.blu).
        //
        t = 1.0;
        if (rgb.red < 0.0 && -fLum > (rgb.red - fLum)*t)
            t = -fLum/(rgb.red - fLum);
        if (rgb.red > 1.0 && 1.0 - fLum < (rgb.red - fLum)*t)
            t = (1.0f - fLum)/(rgb.red - fLum);
        if (rgb.grn < 0.0 && -fLum > (rgb.grn - fLum)*t)
            t = -fLum/(rgb.grn - fLum);
        if (rgb.grn > 1.0 && 1.0 - fLum < (rgb.grn - fLum)*t)
            t = (1.0f - fLum)/(rgb.grn - fLum);
        if (rgb.blu < 0.0 && -fLum > (rgb.blu - fLum)*t)
            t = -fLum/(rgb.blu - fLum);
        if (rgb.blu > 1.0 && 1.0 - fLum < (rgb.blu - fLum)*t)
            t = (1.0f - fLum)/(rgb.blu - fLum);
        rgbClamped.red = fLum + t*(rgb.red - fLum);
        rgbClamped.grn = fLum + t*(rgb.grn - fLum);
        rgbClamped.blu = fLum + t*(rgb.blu - fLum);
        return rgbClamped;
    }
}