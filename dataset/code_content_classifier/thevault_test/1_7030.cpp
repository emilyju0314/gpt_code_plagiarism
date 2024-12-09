RenderBatch* Renderer::GetBatch(
    DrawType drawType, GLuint textureId, uint verticesOffs, uint indexesOffs)
{
    RenderBatch batch(verticesOffs, indexesOffs, drawType, textureId);
    auto it = std::find(mBatches.begin(), mBatches.end(), batch);

    if (it == mBatches.end()) {
        // std::cout << "new batch" << std::endl;
        RenderBatch batch(verticesOffs, indexesOffs, drawType, textureId);
        mBatches.push_back(batch);
        return &mBatches.back();
    }

    return &(*it);
}