void Texture::needRenderTarget()
{
    if (!mIsRenderable)
    {
        mBaseTexture = convertToRenderTarget();
        mIsRenderable = true;
    }

    if (dirtyImageData())
    {
        updateTexture();
    }

    mDirtyMetaData = false;
}