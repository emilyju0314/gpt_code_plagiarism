void CompositedLayerMapping::setContentsNeedDisplayInRect(const LayoutRect& r, PaintInvalidationReason invalidationReason)
{
    // TODO(wangxianzhu): Enable the following assert after paint invalidation for spv2 is ready.
    // ASSERT(!RuntimeEnabledFeatures::slimmingPaintV2Enabled());

    SetContentsNeedsDisplayInRectFunctor functor = {
        enclosingIntRect(LayoutRect(r.location() + m_owningLayer.subpixelAccumulation(), r.size())),
        invalidationReason
    };
    ApplyToGraphicsLayers(this, functor, ApplyToContentLayers);
}