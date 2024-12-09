bool Texture2D::isComplete() const
{
    GLsizei width = mImageArray[0].width;
    GLsizei height = mImageArray[0].height;

    if (width <= 0 || height <= 0)
    {
        return false;
    }

    bool mipmapping = false;

    switch (mMinFilter)
    {
      case GL_NEAREST:
      case GL_LINEAR:
        mipmapping = false;
        break;
      case GL_NEAREST_MIPMAP_NEAREST:
      case GL_LINEAR_MIPMAP_NEAREST:
      case GL_NEAREST_MIPMAP_LINEAR:
      case GL_LINEAR_MIPMAP_LINEAR:
        mipmapping = true;
        break;
     default: UNREACHABLE();
    }

    if ((getFormat() == GL_FLOAT && !getContext()->supportsFloatLinearFilter()) ||
        (getFormat() == GL_HALF_FLOAT_OES && !getContext()->supportsHalfFloatLinearFilter()))
    {
        if (mMagFilter != GL_NEAREST || (mMinFilter != GL_NEAREST && mMinFilter != GL_NEAREST_MIPMAP_NEAREST))
        {
            return false;
        }
    }


    if ((getWrapS() != GL_CLAMP_TO_EDGE && !isPow2(width))
        || (getWrapT() != GL_CLAMP_TO_EDGE && !isPow2(height)))
    {
        return false;
    }

    if (mipmapping)
    {
        if (!isPow2(width) || !isPow2(height))
        {
            return false;
        }

        int q = log2(std::max(width, height));

        for (int level = 1; level <= q; level++)
        {
            if (mImageArray[level].format != mImageArray[0].format)
            {
                return false;
            }

            if (mImageArray[level].width != std::max(1, width >> level))
            {
                return false;
            }

            if (mImageArray[level].height != std::max(1, height >> level))
            {
                return false;
            }
        }
    }

    return true;
}