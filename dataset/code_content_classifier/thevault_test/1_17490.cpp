void Aircraft::MapDrawLabel (XPLMMapLayerID inLayer, float yOfs)
{
    // draw only if said to be visible on this map
    if (!std::isnan(mapX) && !std::isnan(mapY)) {
        XPLMDrawMapLabel(inLayer,
                         mapLabel.c_str(),
                         mapX, mapY + yOfs,
                         xplm_MapOrientation_UI,
                         0.0f);
    }
}