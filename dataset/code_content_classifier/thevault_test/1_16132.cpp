sk_sp<GrSurface> GrResourceAllocator::findSurfaceFor(const GrSurfaceProxy* proxy,
                                                     int minStencilSampleCount) {

    if (proxy->asTextureProxy() && proxy->asTextureProxy()->getUniqueKey().isValid()) {
        // First try to reattach to a cached version if the proxy is uniquely keyed
        sk_sp<GrSurface> surface = fResourceProvider->findByUniqueKey<GrSurface>(
                                                        proxy->asTextureProxy()->getUniqueKey());
        if (surface) {
            if (!GrSurfaceProxyPriv::AttachStencilIfNeeded(fResourceProvider, surface.get(),
                                                           minStencilSampleCount)) {
                return nullptr;
            }

            return surface;
        }
    }

    // First look in the free pool
    GrScratchKey key;

    proxy->priv().computeScratchKey(&key);

    auto filter = [] (const GrSurface* s) {
        return true;
    };
    sk_sp<GrSurface> surface(fFreePool.findAndRemove(key, filter));
    if (surface) {
        if (SkBudgeted::kYes == proxy->isBudgeted() &&
            GrBudgetedType::kBudgeted != surface->resourcePriv().budgetedType()) {
            // This gets the job done but isn't quite correct. It would be better to try to
            // match budgeted proxies w/ budgeted surfaces and unbudgeted w/ unbudgeted.
            surface->resourcePriv().makeBudgeted();
        }

        if (!GrSurfaceProxyPriv::AttachStencilIfNeeded(fResourceProvider, surface.get(),
                                                       minStencilSampleCount)) {
            return nullptr;
        }
        SkASSERT(!surface->getUniqueKey().isValid());
        return surface;
    }

    // Failing that, try to grab a new one from the resource cache
    return proxy->priv().createSurface(fResourceProvider);
}