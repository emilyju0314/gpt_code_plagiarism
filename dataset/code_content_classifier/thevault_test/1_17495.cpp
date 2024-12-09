void MapCreateCB (const char *  mapIdentifier,
                  void *        )       // refcon
{
    // This is a plugin entry function, so we try to catch all exceptions
    try {
        MapLayerCreate(mapIdentifier);
    }
    catch (const std::exception& e) { LOG_MSG(logFATAL, ERR_EXCEPTION, e.what()); }
    catch (...) { LOG_MSG(logFATAL, ERR_EXCEPTION, "<unknown>"); }
}