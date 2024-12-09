static sk_sp<GrTextureProxy> decimate(GrRecordingContext* context,
                                      sk_sp<GrTextureProxy> src,
                                      const SkIPoint& proxyOffset,
                                      SkIPoint* srcOffset,
                                      SkIRect* contentRect,
                                      int scaleFactorX, int scaleFactorY,
                                      bool willBeXFiltering, bool willBeYFiltering,
                                      int radiusX, int radiusY,
                                      GrTextureDomain::Mode mode,
                                      int finalW,
                                      int finalH,
                                      sk_sp<SkColorSpace> finalCS) {
    SkASSERT(SkIsPow2(scaleFactorX) && SkIsPow2(scaleFactorY));
    SkASSERT(scaleFactorX > 1 || scaleFactorY > 1);

    // TODO: Once GrPixelConfig is gone we'll need the source's color type here.
    GrColorType colorType = get_blur_color_type(src.get());

    SkIRect srcRect;
    if (GrTextureDomain::kIgnore_Mode == mode) {
        srcRect = SkIRect::MakeWH(finalW, finalH);
    } else {
        srcRect = *contentRect;
        srcRect.offset(*srcOffset);
    }

    scale_irect_roundout(&srcRect, 1.0f / scaleFactorX, 1.0f / scaleFactorY);
    scale_irect(&srcRect, scaleFactorX, scaleFactorY);

    SkIRect dstRect(srcRect);

    sk_sp<GrRenderTargetContext> dstRenderTargetContext;

    for (int i = 1; i < scaleFactorX || i < scaleFactorY; i *= 2) {
        shrink_irect_by_2(&dstRect, i < scaleFactorX, i < scaleFactorY);

        // We know this will not be the final draw so we are free to make it an approx match.
        dstRenderTargetContext = context->priv().makeDeferredRenderTargetContext(
                SkBackingFit::kApprox,
                dstRect.fRight,
                dstRect.fBottom,
                colorType,
                finalCS,
                1,
                GrMipMapped::kNo,
                src->origin(),
                nullptr,
                SkBudgeted::kYes,
                src->isProtected() ? GrProtected::kYes : GrProtected::kNo);
        if (!dstRenderTargetContext) {
            return nullptr;
        }

        GrPaint paint;
        if (GrTextureDomain::kIgnore_Mode != mode && i == 1) {
            // GrTextureDomainEffect does not support kRepeat_Mode with GrSamplerState::Filter.
            GrTextureDomain::Mode modeForScaling = GrTextureDomain::kRepeat_Mode == mode
                                                                ? GrTextureDomain::kDecal_Mode
                                                                : mode;

            SkRect domain = SkRect::Make(*contentRect);
            domain.inset((i < scaleFactorX) ? SK_ScalarHalf + SK_ScalarNearlyZero : 0.0f,
                         (i < scaleFactorY) ? SK_ScalarHalf + SK_ScalarNearlyZero : 0.0f);
            // Ensure that the insetting doesn't invert the domain rectangle.
            if (domain.fRight < domain.fLeft) {
                domain.fLeft = domain.fRight = SkScalarAve(domain.fLeft, domain.fRight);
            }
            if (domain.fBottom < domain.fTop) {
                domain.fTop = domain.fBottom = SkScalarAve(domain.fTop, domain.fBottom);
            }
            domain.offset(proxyOffset.x(), proxyOffset.y());
            auto fp = GrTextureDomainEffect::Make(std::move(src),
                                                  SkMatrix::I(),
                                                  domain,
                                                  modeForScaling,
                                                  GrSamplerState::Filter::kBilerp);
            paint.addColorFragmentProcessor(std::move(fp));
            srcRect.offset(-(*srcOffset));
            // TODO: consume the srcOffset in both first draws and always set it to zero
            // back in GaussianBlur
            srcOffset->set(0, 0);
        } else {
            paint.addColorTextureProcessor(std::move(src), SkMatrix::I(),
                                           GrSamplerState::ClampBilerp());
        }
        paint.setPorterDuffXPFactory(SkBlendMode::kSrc);

        dstRenderTargetContext->fillRectToRect(GrFixedClip::Disabled(), std::move(paint), GrAA::kNo,
                                               SkMatrix::I(), SkRect::Make(dstRect),
                                               SkRect::Make(srcRect.makeOffset(proxyOffset.x(),
                                                                               proxyOffset.y())));

        src = dstRenderTargetContext->asTextureProxyRef();
        if (!src) {
            return nullptr;
        }
        srcRect = dstRect;
    }

    *contentRect = dstRect;

    SkASSERT(dstRenderTargetContext);

    if (willBeXFiltering) {
        if (scaleFactorX > 1) {
            // Clear out a radius to the right of the contentRect to prevent the
            // X convolution from reading garbage.
            SkIRect clearRect = SkIRect::MakeXYWH(contentRect->fRight, contentRect->fTop,
                                                  radiusX, contentRect->height());
            dstRenderTargetContext->priv().absClear(&clearRect, SK_PMColor4fTRANSPARENT);
        }
    } else {
        if (scaleFactorY > 1) {
            // Clear out a radius below the contentRect to prevent the Y
            // convolution from reading garbage.
            SkIRect clearRect = SkIRect::MakeXYWH(contentRect->fLeft, contentRect->fBottom,
                                                  contentRect->width(), radiusY);
            dstRenderTargetContext->priv().absClear(&clearRect, SK_PMColor4fTRANSPARENT);
        }
    }

    return dstRenderTargetContext->asTextureProxyRef();
}