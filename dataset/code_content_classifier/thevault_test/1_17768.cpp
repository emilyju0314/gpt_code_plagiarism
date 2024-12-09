void CustomGeometryTile::setNecessity(TileNecessity newNecessity) {
   if (newNecessity != necessity || stale ) {
        necessity = newNecessity;
        if (necessity == TileNecessity::Required) {
            loader.invoke(&style::CustomTileLoader::fetchTile, id, actorRef);
            stale = false;
        } else if (!isRenderable()) {
            loader.invoke(&style::CustomTileLoader::cancelTile, id);
        }
    }
}