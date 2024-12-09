IDirect3DBaseTexture9 *TextureCubeMap::createTexture()
{
    IDirect3DDevice9 *device = getDevice();
    D3DFORMAT format = selectFormat(mImageArray[0][0].format, mType);

    IDirect3DCubeTexture9 *texture;

    HRESULT result = device->CreateCubeTexture(mWidth, creationLevels(mWidth, 0), 0, format, D3DPOOL_DEFAULT, &texture, NULL);

    if (FAILED(result))
    {
        ASSERT(result == D3DERR_OUTOFVIDEOMEMORY || result == E_OUTOFMEMORY);
        return error(GL_OUT_OF_MEMORY, (IDirect3DBaseTexture9*)NULL);
    }

    if (mTexture) mTexture->Release();

    mTexture = texture;
    return mTexture;
}