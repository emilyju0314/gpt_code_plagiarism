void Renderer::BuildBatches()
{
    mVertices.clear();
    mIndexes.clear();
    mBatches.clear();

    DrawType lastDrawType = D_NONE;
    GLuint lastTextureId = 0;
    uint verticesOffs = 0, indexesOffs = 0;
    RenderBatch* batch = nullptr;

    for (uint i = 0; i < mQueue.size(); i++) {
        if (lastDrawType != mQueue[i]->mDrawType || lastTextureId != mQueue[i]->textureId) {
            lastDrawType = mQueue[i]->mDrawType;
            lastTextureId = mQueue[i]->textureId;
            batch = GetBatch(lastDrawType, lastTextureId, verticesOffs, indexesOffs);
        }
        uint indexGOffs = mVertices.size();

        mVertices.insert(mVertices.end(), mQueue[i]->mVertices.begin(), mQueue[i]->mVertices.end());
        verticesOffs += mQueue[i]->mVertices.size();
        batch->numVertices += mQueue[i]->mVertices.size();

        for (uint j = 0; j < mQueue[i]->mIndexes.size(); j++)
            mIndexes.emplace_back(indexGOffs + mQueue[i]->mIndexes[j]);
        indexesOffs += mQueue[i]->mIndexes.size();
        batch->numIndexes += mQueue[i]->mIndexes.size();
    }
    mDirty = false;
}