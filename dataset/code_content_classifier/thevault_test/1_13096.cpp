void FFN::InitModel(NMTConfig& config, bool isEnc)
{
    SetTrainingFlag(config.training.isTraining);
    devID = config.common.devID;
    dropoutP = config.model.ffnDropout;
    inSize = isEnc ? config.model.encEmbDim : config.model.decEmbDim;
    outSize = isEnc ? config.model.encEmbDim : config.model.decEmbDim;
    hSize = isEnc ? config.model.encFFNHiddenDim : config.model.decFFNHiddenDim;

    InitTensor2D(&w1, inSize, hSize, X_FLOAT, devID);
    InitTensor1D(&b1, hSize, X_FLOAT, devID);

    InitTensor2D(&w2, hSize, outSize, X_FLOAT, devID);
    InitTensor1D(&b2, outSize, X_FLOAT, devID);

    if (isTraining) {
        _SetDataFanInOut(&w1);
        _SetDataFanInOut(&w2);

        b1.SetZeroAll();
        b2.SetZeroAll();
    }
}