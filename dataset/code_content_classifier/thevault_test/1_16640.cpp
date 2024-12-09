bool TextureCubeMap::redefineTexture(GLint level, GLenum internalFormat, GLsizei width)
{
    // Are these settings compatible with level 0?
    bool sizeOkay = (mImageArray[0][0].width >> level == width);

    bool textureOkay = (sizeOkay && internalFormat == mImageArray[0][0].format);

    if (!textureOkay)
    {
        TRACE("Redefining cube texture (%d, 0x%04X, %d => 0x%04X, %d).", level,
              mImageArray[0][0].format, mImageArray[0][0].width,
              internalFormat, width);

        // Purge all the levels and the texture.
        for (int i = 0; i < IMPLEMENTATION_MAX_TEXTURE_LEVELS; i++)
        {
            for (int f = 0; f < 6; f++)
            {
                if (mImageArray[f][i].surface != NULL)
                {
                    mImageArray[f][i].dirty = false;

                    mImageArray[f][i].surface->Release();
                    mImageArray[f][i].surface = NULL;
                }
            }
        }

        if (mTexture != NULL)
        {
            mTexture->Release();
            mTexture = NULL;
            dropTexture();
        }

        mWidth = width << level;
        mImageArray[0][0].width = width << level;
        mHeight = width << level;
        mImageArray[0][0].height = width << level;

        mImageArray[0][0].format = internalFormat;
    }

    return !textureOkay;
}