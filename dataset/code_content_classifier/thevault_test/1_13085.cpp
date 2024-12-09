void OutputLayer::InitModel(NMTConfig& config)
{
    SetTrainingFlag(config.training.isTraining);
    devID = config.common.devID;
    hSize = config.model.decEmbDim;
    vSize = config.model.tgtVocabSize;
    shareDecInputOutputEmb = config.model.shareDecInputOutputEmb;

    if (!shareDecInputOutputEmb) {
        w = NewTensor2D(vSize, hSize, X_FLOAT, devID);

        DTYPE v = 1.0F / (float)sqrt((float)hSize);
        if (isTraining) {
            w->SetDataRandn(0, v);
        }
    }
}