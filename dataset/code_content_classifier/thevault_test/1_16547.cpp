GLint Program::getSamplerMapping(unsigned int samplerIndex)
{
    assert(samplerIndex < sizeof(mSamplers)/sizeof(mSamplers[0]));

    GLint logicalTextureUnit = -1;

    if (mSamplers[samplerIndex].active)
    {
        logicalTextureUnit = mSamplers[samplerIndex].logicalTextureUnit;
    }

    if (logicalTextureUnit >= 0 && logicalTextureUnit < MAX_TEXTURE_IMAGE_UNITS)
    {
        return logicalTextureUnit;
    }

    return -1;
}