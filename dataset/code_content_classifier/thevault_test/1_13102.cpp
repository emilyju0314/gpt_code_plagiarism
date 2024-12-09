void Embedder::MakePosEmbedding(int length)
{
    InitTensor2D(&posEmbeddingBase, length, eSize, X_FLOAT, devID);

    float* data = new float[posEmbeddingBase.unitNum];

    for (int pos = 0; pos < length; pos++) {
        float* dp = data + pos * eSize;

        int channelSize = eSize / 2;
        int offset = 0;
        for (int i = 0; i < channelSize; i++) {
            dp[offset++] = (float)sin(pos * exp(-i * log(10000.0F) / (channelSize - 1)));
        }
        for (int i = 0; i < channelSize; i++) {
            dp[offset++] = (float)cos(pos * exp(-i * log(10000.0F) / (channelSize - 1)));
        }
    }

    /* padding zeros */
    int padStart = padIdx * eSize;
    for (int i = padStart; i < padStart + eSize; i++)
        data[i] = 0.F;

    posEmbeddingBase.SetData(data, posEmbeddingBase.unitNum);

    delete[] data;
}