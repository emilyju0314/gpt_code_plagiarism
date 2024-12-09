bool Texture2D::redefineTexture(GLint level, GLenum internalFormat, GLsizei width, GLsizei height, GLenum type)
{
    bool widthOkay = (mWidth >> level == width);
    bool heightOkay = (mHeight >> level == height);

    bool sizeOkay = ((widthOkay && heightOkay)
                     || (widthOkay && mHeight >> level == 0 && height == 1)
                     || (heightOkay && mWidth >> level == 0 && width == 1));

    bool typeOkay = (type == mType);

    bool textureOkay = (sizeOkay && typeOkay && internalFormat == mImageArray[0].format);

    if (!textureOkay)
    {
        TRACE("Redefining 2D texture (%d, 0x%04X, %d, %d => 0x%04X, %d, %d).", level,
              mImageArray[0].format, mWidth, mHeight,
              internalFormat, width, height);

        // Purge all the levels and the texture.

        for (int i = 0; i < IMPLEMENTATION_MAX_TEXTURE_LEVELS; i++)
        {
            if (mImageArray[i].surface != NULL)
            {
                mImageArray[i].dirty = false;

                mImageArray[i].surface->Release();
                mImageArray[i].surface = NULL;
            }
        }

        if (mTexture != NULL)
        {
            mTexture->Release();
            mTexture = NULL;
            dropTexture();
        }

        mWidth = width << level;
        mHeight = height << level;
        mImageArray[0].format = internalFormat;
        mType = type;
    }

    return !textureOkay;
}