void Embedder::InitModel(NMTConfig& config, bool isEnc)
{
    SetTrainingFlag(config.training.isTraining);
    fp16 = config.common.useFP16;
    shareEncDecEmb = config.model.shareEncDecEmb;
    padIdx = config.model.pad;
    devID = config.common.devID;
    eSize = isEnc ? config.model.encEmbDim : config.model.decEmbDim;
    maxLength = config.model.maxTgtLen; // TODO: reset the maxLength for src emb
    vSize = isEnc ? config.model.srcVocabSize : config.model.tgtVocabSize;

    if (!w) {
        w = NewTensor2D(vSize, eSize, fp16 ? X_FLOAT16 : X_FLOAT, devID);

        maxLength = maxLength + 1 + 1;
        DTYPE v = 1.0F / (float)sqrt((float)eSize);

        if (isTraining) {
            w->SetDataRandn(0, v);
            for (int i = 0; i < eSize; i++) {
                w->Set2D(0.0F, padIdx, i);
            }
        }
    }

    /* create the positional embedding matrix */
    MakePosEmbedding(maxLength);
}