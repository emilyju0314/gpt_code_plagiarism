void MapDeleteCB (XPLMMapLayerID       inLayer,
                  void *               ) // inRefcon
{
    // This is a plugin entry function, so we try to catch all exceptions
    try {
        // find the entry in the map and remove it
        mapMapLayerIDTy::iterator iter =
        std::find_if(glob.mapMapLayers.begin(), glob.mapMapLayers.end(),
                     [inLayer](const mapMapLayerIDTy::value_type& p)
                     {return p.second == inLayer;});
        if (iter != glob.mapMapLayers.end())
            glob.mapMapLayers.erase(iter);
    }
    catch (const std::exception& e) { LOG_MSG(logFATAL, ERR_EXCEPTION, e.what()); }
    catch (...) { LOG_MSG(logFATAL, ERR_EXCEPTION, "<unknown>"); }
}