void MapLayerCreate (const char* mapIdentifier)
{
    // I've caught a case live in the debugger in which XP passed in NULL!
    // That may or may not be the reason why in some rare instances using maps crashed, especially on Mac.
    // Let's catch that case:
    if (!mapIdentifier)
        return;
    
    // Safety check: Do we already have a layer there?
    if (glob.mapMapLayers.count(mapIdentifier) > 0)
        return;
    
    // Create the map layer
    XPLMCreateMapLayer_t mapParams = {
        sizeof(XPLMCreateMapLayer_t),               // structSize
        mapIdentifier,                              // mapToCreateLayerIn
        xplm_MapLayer_Markings,                     // layerType
        MapDeleteCB,                                // willBeDeletedCallback
        MapPrepareCacheCB,                          // prepCacheCallback
        nullptr,                                    // drawCallback
        MapIconDrawingCB,                           // iconCallback
        MapLabelDrawingCB,                          // labelCallback
        1,                                          // showUiToggle
        glob.pluginName.c_str(),                    // layerName
        nullptr                                     // refcon
    };
    XPLMMapLayerID layerId = XPLMCreateMapLayer(&mapParams);
    if (layerId) {
        // save the layer id for future reference
        glob.mapMapLayers.emplace(mapIdentifier, layerId);
        LOG_MSG(logDEBUG, DEBUG_MAP_LAYER_CREATED, mapIdentifier);
    } else {
        LOG_MSG(logERR, ERR_MAP_LAYER_FAILED, mapIdentifier);
    }
        
    
}