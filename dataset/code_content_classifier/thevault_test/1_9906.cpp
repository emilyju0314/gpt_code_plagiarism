bool
VolumeAttributes::GradientWontChange(const VolumeAttributes &obj) const
{
    int i;

    // Compare the freeformOpacity arrays.
    bool freeformOpacity_equal = true;
    for(i = 0; i < 256 && freeformOpacity_equal; ++i)
        freeformOpacity_equal = (freeformOpacity[i] == obj.freeformOpacity[i]);

    // Create the return value
    return ((freeformFlag         == obj.freeformFlag) &&
            (opacityControlPoints == obj.opacityControlPoints) &&
            (resampleTarget       == obj.resampleTarget) &&
            (opacityVariable      == obj.opacityVariable) &&
            freeformOpacity_equal &&
            (useColorVarMin       == obj.useColorVarMin) &&
            (colorVarMin          == obj.colorVarMin) &&
            (useColorVarMax       == obj.useColorVarMax) &&
            (colorVarMax          == obj.colorVarMax) &&
            (useOpacityVarMin     == obj.useOpacityVarMin) &&
            (opacityVarMin        == obj.opacityVarMin) &&
            (useOpacityVarMax     == obj.useOpacityVarMax) &&
            (opacityVarMax        == obj.opacityVarMax) &&
            (rendererType         == obj.rendererType) &&
            (gradientType         == obj.gradientType));
}