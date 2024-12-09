void GeometryTileWorker::setData(std::unique_ptr<const GeometryTileData> data_,
                                 std::set<std::string> availableImages_,
                                 uint64_t correlationID_) {
    try {
        data = std::move(data_);
        correlationID = correlationID_;
        availableImages = std::move(availableImages_);

        switch (state) {
        case Idle:
            parse();
            coalesce();
            break;

        case Coalescing:
        case NeedsParse:
        case NeedsSymbolLayout:
            state = NeedsParse;
            break;
        }
    } catch (...) {
        parent.invoke(&GeometryTile::onError, std::current_exception(), correlationID);
    }
}