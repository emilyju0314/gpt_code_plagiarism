static void drawResampledBitmap(SkCanvas& canvas, SkPaint& paint, const NativeImageSkia& bitmap, const SkIRect& srcIRect, const SkRect& destRect)
{
    // First get the subset we need. This is efficient and does not copy pixels.
    SkBitmap subset;
    bitmap.extractSubset(&subset, srcIRect);
    SkRect srcRect;
    srcRect.set(srcIRect);

    // Whether we're doing a subset or using the full source image.
    bool srcIsFull = srcIRect.fLeft == 0 && srcIRect.fTop == 0
        && srcIRect.width() == bitmap.width()
        && srcIRect.height() == bitmap.height();

    // We will always draw in integer sizes, so round the destination rect.
    SkIRect destRectRounded;
    destRect.round(&destRectRounded);
    SkIRect resizedImageRect =  // Represents the size of the resized image.
        { 0, 0, destRectRounded.width(), destRectRounded.height() };

    // Apply forward transform to destRect to estimate required size of
    // re-sampled bitmap, and use only in calls required to resize, or that
    // check for the required size.
    SkRect destRectTransformed;
    canvas.getTotalMatrix().mapRect(&destRectTransformed, destRect);
    SkIRect destRectTransformedRounded;
    destRectTransformed.round(&destRectTransformedRounded);

    if (srcIsFull && bitmap.hasResizedBitmap(destRectTransformedRounded.width(), destRectTransformedRounded.height())) {
        // Yay, this bitmap frame already has a resized version.
        SkBitmap resampled = bitmap.resizedBitmap(destRectTransformedRounded.width(), destRectTransformedRounded.height());
        canvas.drawBitmapRect(resampled, 0, destRect, &paint);
        return;
    }

    // Compute the visible portion of our rect.
    // We also need to compute the transformed portion of the
    // visible portion for use below.
    SkRect destBitmapSubsetSk;
    ClipRectToCanvas(canvas, destRect, &destBitmapSubsetSk);
    SkRect destBitmapSubsetTransformed;
    canvas.getTotalMatrix().mapRect(&destBitmapSubsetTransformed, destBitmapSubsetSk);
    destBitmapSubsetSk.offset(-destRect.fLeft, -destRect.fTop);
    SkIRect destBitmapSubsetTransformedRounded;
    destBitmapSubsetTransformed.round(&destBitmapSubsetTransformedRounded);
    destBitmapSubsetTransformedRounded.offset(-destRectTransformedRounded.fLeft, -destRectTransformedRounded.fTop);

    // The matrix inverting, etc. could have introduced rounding error which
    // causes the bounds to be outside of the resized bitmap. We round outward
    // so we always lean toward it being larger rather than smaller than we
    // need, and then clamp to the bitmap bounds so we don't get any invalid
    // data.
    SkIRect destBitmapSubsetSkI;
    destBitmapSubsetSk.roundOut(&destBitmapSubsetSkI);
    if (!destBitmapSubsetSkI.intersect(resizedImageRect))
        return;  // Resized image does not intersect.

    if (srcIsFull && bitmap.shouldCacheResampling(
            resizedImageRect.width(),
            resizedImageRect.height(),
            destBitmapSubsetSkI.width(),
            destBitmapSubsetSkI.height())) {
        // We're supposed to resize the entire image and cache it, even though
        // we don't need all of it.
        SkBitmap resampled = bitmap.resizedBitmap(destRectTransformedRounded.width(),
                                                  destRectTransformedRounded.height());
        canvas.drawBitmapRect(resampled, 0, destRect, &paint);
    } else {
        // We should only resize the exposed part of the bitmap to do the
        // minimal possible work.

        // Resample the needed part of the image.
        // Transforms above plus rounding may cause destBitmapSubsetTransformedRounded
        // to go outside the image, so need to clip to avoid problems.
        if (destBitmapSubsetTransformedRounded.intersect(0, 0,
                destRectTransformedRounded.width(), destRectTransformedRounded.height())) {

            SkBitmap resampled = skia::ImageOperations::Resize(subset,
                skia::ImageOperations::RESIZE_LANCZOS3,
                destRectTransformedRounded.width(), destRectTransformedRounded.height(),
                destBitmapSubsetTransformedRounded);

            // Compute where the new bitmap should be drawn. Since our new bitmap
            // may be smaller than the original, we have to shift it over by the
            // same amount that we cut off the top and left.
            destBitmapSubsetSkI.offset(destRect.fLeft, destRect.fTop);
            SkRect offsetDestRect;
            offsetDestRect.set(destBitmapSubsetSkI);

            canvas.drawBitmapRect(resampled, 0, offsetDestRect, &paint);
        }
    }
}