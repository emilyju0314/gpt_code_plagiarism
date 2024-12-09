GLenum Context::applyIndexBuffer(const void *indices, GLsizei count, GLenum mode, GLenum type, TranslatedIndexData *indexInfo)
{
    IDirect3DDevice9 *device = getDevice();
    GLenum err = mIndexDataManager->prepareIndexData(type, count, mState.elementArrayBuffer.get(), indices, indexInfo);

    if (err == GL_NO_ERROR)
    {
        device->SetIndices(indexInfo->indexBuffer);
    }

    return err;
}