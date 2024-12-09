bool CompositedLayerMapping::isDirectlyCompositedImage() const
{
    ASSERT(layoutObject()->isImage());
    LayoutImage* imageLayoutObject = toLayoutImage(layoutObject());

    if (m_owningLayer.hasBoxDecorationsOrBackground()
        || imageLayoutObject->hasClip()
        || imageLayoutObject->hasClipPath()
        || imageLayoutObject->hasObjectFit())
        return false;

    if (ImageResource* cachedImage = imageLayoutObject->cachedImage()) {
        if (!cachedImage->hasImage())
            return false;

        Image* image = cachedImage->image();
        if (!image->isBitmapImage())
            return false;

        return true;
    }

    return false;
}