bool CompositedLayerMapping::toggleScrollbarLayerIfNeeded(std::unique_ptr<GraphicsLayer>& layer, bool needsLayer, CompositingReasons reason)
{
    if (needsLayer == !!layer)
        return false;
    layer = needsLayer ? createGraphicsLayer(reason) : nullptr;
    return true;
}