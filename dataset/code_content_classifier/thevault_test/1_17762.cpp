void CrossTileSymbolLayerIndex::handleWrapJump(float newLng) {
    const int wrapDelta = std::round((newLng - lng) / 360);
    if (wrapDelta != 0) {
        std::map<uint8_t, std::map<OverscaledTileID,TileLayerIndex>> newIndexes;
        for (auto& zoomIndex : indexes) {
            std::map<OverscaledTileID,TileLayerIndex> newZoomIndex;
            for (auto& index : zoomIndex.second) {
                // change the tileID's wrap and move its index
                index.second.coord = index.second.coord.unwrapTo(index.second.coord.wrap + wrapDelta);
                newZoomIndex.emplace(index.second.coord, std::move(index.second));
            }
            newIndexes.emplace(zoomIndex.first, std::move(newZoomIndex));
        }

        indexes = std::move(newIndexes);
    }

    lng = newLng;
}