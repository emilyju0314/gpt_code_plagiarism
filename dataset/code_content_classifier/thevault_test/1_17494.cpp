void MapCreateAll ()
{
    // Loop all possible maps and see if they exist
    for (const char* mapIdentifier: ALL_MAPS)
        if (XPLMMapExists(mapIdentifier))
            MapLayerCreate(mapIdentifier);
}