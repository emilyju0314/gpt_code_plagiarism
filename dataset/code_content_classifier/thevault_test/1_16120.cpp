static sk_sp<GrRenderTargetContext> convolve_gaussian(GrRecordingContext* context,
                                                      sk_sp<GrTextureProxy> proxy,
                                                      const SkIPoint& proxyOffset,
                                                      const SkIRect& srcRect,
                                                      const SkIPoint& srcOffset,
                                                      Direction direction,
                                                      int radius,
                                                      float sigma,
                                                      SkIRect* contentRect,
                                                      GrTextureDomain::Mode mode,
                                                      int finalW,
                                                      int finalH,
                                                      sk_sp<SkColorSpace> finalCS,
                                                      SkBackingFit fit) {
    SkASSERT(srcRect.width() <= finalW && srcRect.height() <= finalH);

    // TODO: Once GrPixelConfig is gone we'll need the source's color type here.
    GrColorType colorType = get_blur_color_type(proxy.get());

    sk_sp<GrRenderTargetContext> dstRenderTargetContext;
    dstRenderTargetContext = context->priv().makeDeferredRenderTargetContext(
            fit,
            srcRect.width(),
            srcRect.height(),
            colorType,
            std::move(finalCS),
            1,
            GrMipMapped::kNo,
            proxy->origin(),
            nullptr,
            SkBudgeted::kYes,
            proxy->isProtected() ? GrProtected::kYes : GrProtected::kNo);
    if (!dstRenderTargetContext) {
        return nullptr;
    }

    GrFixedClip clip(SkIRect::MakeWH(finalW, finalH));

    int bounds[2] = { 0, 0 };
    SkIRect dstRect = SkIRect::MakeWH(srcRect.width(), srcRect.height());
    SkIPoint netOffset = srcOffset - proxyOffset;
    if (GrTextureDomain::kIgnore_Mode == mode) {
        *contentRect = dstRect;
        convolve_gaussian_1d(dstRenderTargetContext.get(), clip, dstRect, netOffset,
                             std::move(proxy), direction, radius, sigma,
                             GrTextureDomain::kIgnore_Mode, bounds);
        return dstRenderTargetContext;
    }
    // These destination rects need to be adjusted by srcOffset, but should *not* be adjusted by
    // the proxyOffset, which is why keeping them separate is convenient.
    SkIRect midRect = *contentRect, leftRect, rightRect;
    midRect.offset(srcOffset);
    SkIRect topRect, bottomRect;
    if (Direction::kX == direction) {
        bounds[0] = contentRect->left() + proxyOffset.x();
        bounds[1] = contentRect->right() + proxyOffset.x();
        topRect = SkIRect::MakeLTRB(0, 0, dstRect.right(), midRect.top());
        bottomRect = SkIRect::MakeLTRB(0, midRect.bottom(), dstRect.right(), dstRect.bottom());
        midRect.inset(radius, 0);
        leftRect = SkIRect::MakeLTRB(0, midRect.top(), midRect.left(), midRect.bottom());
        rightRect =
            SkIRect::MakeLTRB(midRect.right(), midRect.top(), dstRect.width(), midRect.bottom());
        dstRect.fTop = midRect.top();
        dstRect.fBottom = midRect.bottom();

        contentRect->fLeft = dstRect.fLeft;
        contentRect->fTop = midRect.fTop;
        contentRect->fRight = dstRect.fRight;
        contentRect->fBottom = midRect.fBottom;
    } else {
        bounds[0] = contentRect->top() + proxyOffset.y();
        bounds[1] = contentRect->bottom() + proxyOffset.y();
        topRect = SkIRect::MakeLTRB(0, 0, midRect.left(), dstRect.bottom());
        bottomRect = SkIRect::MakeLTRB(midRect.right(), 0, dstRect.right(), dstRect.bottom());
        midRect.inset(0, radius);
        leftRect = SkIRect::MakeLTRB(midRect.left(), 0, midRect.right(), midRect.top());
        rightRect =
            SkIRect::MakeLTRB(midRect.left(), midRect.bottom(), midRect.right(), dstRect.height());
        dstRect.fLeft = midRect.left();
        dstRect.fRight = midRect.right();

        contentRect->fLeft = midRect.fLeft;
        contentRect->fTop = dstRect.fTop;
        contentRect->fRight = midRect.fRight;
        contentRect->fBottom = dstRect.fBottom;
    }
    if (!topRect.isEmpty()) {
        dstRenderTargetContext->clear(&topRect, SK_PMColor4fTRANSPARENT,
                                      GrRenderTargetContext::CanClearFullscreen::kNo);
    }

    if (!bottomRect.isEmpty()) {
        dstRenderTargetContext->clear(&bottomRect, SK_PMColor4fTRANSPARENT,
                                      GrRenderTargetContext::CanClearFullscreen::kNo);
    }

    if (midRect.isEmpty()) {
        // Blur radius covers srcBounds; use bounds over entire draw
        convolve_gaussian_1d(dstRenderTargetContext.get(), clip, dstRect, netOffset,
                             std::move(proxy), direction, radius, sigma, mode, bounds);
    } else {
        // Draw right and left margins with bounds; middle without.
        convolve_gaussian_1d(dstRenderTargetContext.get(), clip, leftRect, netOffset,
                             proxy, direction, radius, sigma, mode, bounds);
        convolve_gaussian_1d(dstRenderTargetContext.get(), clip, rightRect, netOffset,
                             proxy, direction, radius, sigma, mode, bounds);
        convolve_gaussian_1d(dstRenderTargetContext.get(), clip, midRect, netOffset,
                             std::move(proxy), direction, radius, sigma,
                             GrTextureDomain::kIgnore_Mode, bounds);
    }

    return dstRenderTargetContext;
}