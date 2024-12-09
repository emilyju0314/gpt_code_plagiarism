static sk_sp<GrRenderTargetContext> reexpand(GrRecordingContext* context,
                                             sk_sp<GrRenderTargetContext> srcRenderTargetContext,
                                             const SkIRect& localSrcBounds,
                                             int scaleFactorX, int scaleFactorY,
                                             GrTextureDomain::Mode mode,
                                             int finalW,
                                             int finalH,
                                             sk_sp<SkColorSpace> finalCS,
                                             SkBackingFit fit) {
    const SkIRect srcRect = SkIRect::MakeWH(srcRenderTargetContext->width(),
                                            srcRenderTargetContext->height());

    // Clear one pixel to the right and below, to accommodate bilinear upsampling.
    // TODO: it seems like we should actually be clamping here rather than darkening
    // the bottom right edges.
    SkIRect clearRect = SkIRect::MakeXYWH(srcRect.fLeft, srcRect.fBottom, srcRect.width() + 1, 1);
    srcRenderTargetContext->priv().absClear(&clearRect, SK_PMColor4fTRANSPARENT);
    clearRect = SkIRect::MakeXYWH(srcRect.fRight, srcRect.fTop, 1, srcRect.height());
    srcRenderTargetContext->priv().absClear(&clearRect, SK_PMColor4fTRANSPARENT);

    sk_sp<GrTextureProxy> srcProxy = srcRenderTargetContext->asTextureProxyRef();
    if (!srcProxy) {
        return nullptr;
    }

    srcRenderTargetContext = nullptr; // no longer needed

    // TODO: Once GrPixelConfig is gone we'll need the source's color type here.
    GrColorType colorType = get_blur_color_type(srcProxy.get());

    sk_sp<GrRenderTargetContext> dstRenderTargetContext =
            context->priv().makeDeferredRenderTargetContext(fit, finalW, finalH, colorType,
                                                            std::move(finalCS), 1, GrMipMapped::kNo,
                                                            srcProxy->origin());
    if (!dstRenderTargetContext) {
        return nullptr;
    }

    GrPaint paint;
    if (GrTextureDomain::kIgnore_Mode != mode) {
        // GrTextureDomainEffect does not support kRepeat_Mode with GrSamplerState::Filter.
        GrTextureDomain::Mode modeForScaling = GrTextureDomain::kRepeat_Mode == mode
                                                            ? GrTextureDomain::kDecal_Mode
                                                            : mode;

        SkRect domain = SkRect::Make(localSrcBounds);
        auto fp = GrTextureDomainEffect::Make(std::move(srcProxy),
                                                SkMatrix::I(),
                                                domain,
                                                modeForScaling,
                                                GrSamplerState::Filter::kBilerp);
        paint.addColorFragmentProcessor(std::move(fp));
    } else {
        // FIXME:  this should be mitchell, not bilinear.
        paint.addColorTextureProcessor(std::move(srcProxy), SkMatrix::I(),
                                       GrSamplerState::ClampBilerp());
    }
    paint.setPorterDuffXPFactory(SkBlendMode::kSrc);
    GrFixedClip clip(SkIRect::MakeWH(finalW, finalH));

    // TODO: using dstII as dstRect results in some image diffs - why?
    SkIRect dstRect(srcRect);
    scale_irect(&dstRect, scaleFactorX, scaleFactorY);

    dstRenderTargetContext->fillRectToRect(clip, std::move(paint), GrAA::kNo, SkMatrix::I(),
                                           SkRect::Make(dstRect), SkRect::Make(srcRect));

    return dstRenderTargetContext;
}