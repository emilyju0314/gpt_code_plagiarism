bool TextureCubeMap::isComplete() const
{
    int size = mImageArray[0][0].width;

    if (size <= 0)
    {
        return false;
    }

    bool mipmapping;

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

    for (int face = 0; face < 6; face++)
    {
        if (mImageArray[face][0].width != size || mImageArray[face][0].height != size)
        {
            return false;
        }
    }

    if ((getFormat() == GL_FLOAT && !getContext()->supportsFloatLinearFilter()) ||
        (getFormat() == GL_HALF_FLOAT_OES && !getContext()->supportsHalfFloatLinearFilter()))
    {
        if (mMagFilter != GL_NEAREST || (mMinFilter != GL_NEAREST && mMinFilter != GL_NEAREST_MIPMAP_NEAREST))
        {
            return false;
        }
    }

    if (mipmapping)
    {
        if (!isPow2(size) && (getWrapS() != GL_CLAMP_TO_EDGE || getWrapT() != GL_CLAMP_TO_EDGE))
        {
            return false;
        }

        int q = log2(size);

        for (int face = 0; face < 6; face++)
        {
            for (int level = 1; level <= q; level++)
            {
                if (mImageArray[face][level].format != mImageArray[0][0].format)
                {
                    return false;
                }

                if (mImageArray[face][level].width != std::max(1, size >> level))
                {
                    return false;
                }

                ASSERT(mImageArray[face][level].height == mImageArray[face][level].width);
            }
        }
    }

    return true;
}