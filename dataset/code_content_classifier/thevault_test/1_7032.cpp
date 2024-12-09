void Renderer::RebuildVertices()
{
    mVertices.clear();
    for (uint i = 0; i < mQueue.size(); i++)
        for (uint j = 0; j < mQueue[i]->mVertices.size(); j++)
            mVertices.emplace_back(mQueue[i]->mVertices[j]);
}