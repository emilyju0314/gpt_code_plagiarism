void BitmapImageSingleFrameSkia::draw(GraphicsContext* ctxt,
                                      const FloatRect& dstRect,
                                      const FloatRect& srcRect,
                                      ColorSpace styleColorSpace,
                                      CompositeOperator compositeOp)
{
    FloatRect normDstRect = normalizeRect(dstRect);
    FloatRect normSrcRect = normalizeRect(srcRect);

    if (normSrcRect.isEmpty() || normDstRect.isEmpty())
        return;  // Nothing to draw.

    if (ctxt->platformContext()->useGPU() && ctxt->platformContext()->canAccelerate()) {
        drawBitmapGLES2(ctxt, &m_nativeImage, srcRect, dstRect, styleColorSpace, compositeOp);
        return;
    }

    ctxt->platformContext()->prepareForSoftwareDraw();

    paintSkBitmap(ctxt->platformContext(),
                  m_nativeImage,
                  enclosingIntRect(normSrcRect),
                  normDstRect,
                  WebCoreCompositeToSkiaComposite(compositeOp));
}