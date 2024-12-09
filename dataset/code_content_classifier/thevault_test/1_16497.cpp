void Context::applyTextures()
{
    IDirect3DDevice9 *device = getDevice();
    Program *programObject = getCurrentProgram();

    for (int sampler = 0; sampler < MAX_TEXTURE_IMAGE_UNITS; sampler++)
    {
        int textureUnit = programObject->getSamplerMapping(sampler);
        if (textureUnit != -1)
        {
            SamplerType textureType = programObject->getSamplerType(sampler);

            Texture *texture = getSamplerTexture(textureUnit, textureType);

            if (programObject->isSamplerDirty(sampler) || texture->isDirty())
            {
                if (texture->isComplete())
                {
                    GLenum wrapS = texture->getWrapS();
                    GLenum wrapT = texture->getWrapT();
                    GLenum minFilter = texture->getMinFilter();
                    GLenum magFilter = texture->getMagFilter();

                    device->SetSamplerState(sampler, D3DSAMP_ADDRESSU, es2dx::ConvertTextureWrap(wrapS));
                    device->SetSamplerState(sampler, D3DSAMP_ADDRESSV, es2dx::ConvertTextureWrap(wrapT));

                    device->SetSamplerState(sampler, D3DSAMP_MAGFILTER, es2dx::ConvertMagFilter(magFilter));
                    D3DTEXTUREFILTERTYPE d3dMinFilter, d3dMipFilter;
                    es2dx::ConvertMinFilter(minFilter, &d3dMinFilter, &d3dMipFilter);
                    device->SetSamplerState(sampler, D3DSAMP_MINFILTER, d3dMinFilter);
                    device->SetSamplerState(sampler, D3DSAMP_MIPFILTER, d3dMipFilter);

                    device->SetTexture(sampler, texture->getTexture());
                }
                else
                {
                    device->SetTexture(sampler, getIncompleteTexture(textureType)->getTexture());
                }
            }

            programObject->setSamplerDirty(sampler, false);
        }
        else
        {
            if (programObject->isSamplerDirty(sampler))
            {
                device->SetTexture(sampler, NULL);
                programObject->setSamplerDirty(sampler, false);
            }
        }   
    }
}