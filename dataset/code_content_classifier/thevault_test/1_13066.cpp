void AttEncoder::InitModel(NMTConfig& config)
{
    SetTrainingFlag(config.training.isTraining);
    devID = config.common.devID;
    preLN = config.model.encPreLN;
    dropoutP = config.model.dropout;
    embDim = config.model.encEmbDim;
    nlayer = config.model.encLayerNum;
    vSize = config.model.srcVocabSize;
    finalNorm = config.model.encFinalNorm;
    useHistory = config.model.useEncHistory;
    
    CheckNTErrors(vSize > 1, "Set vocabulary size by \"-vsize\"");
    CheckNTErrors(nlayer >= 1, "We have one encoding layer at least!");

    ffns = new FFN[nlayer];
    selfAtts = new Attention[nlayer];
    attLayerNorms = new LayerNorm[nlayer];
    fnnLayerNorms = new LayerNorm[nlayer];

    if (useHistory) {
        history = new LayerHistory;
        history->InitModel(config, true);
    }

    if (finalNorm) {
        encoderLayerNorm = new LayerNorm;
        encoderLayerNorm->InitModel(config, devID, embDim, config.model.encoderL1Norm);
    }

    /* initialize the stacked layers */
    embedder.InitModel(config);
    for (int i = 0; i < nlayer; i++) {
        ffns[i].InitModel(config, true);
        selfAtts[i].InitModel(config, true, true);
        attLayerNorms[i].InitModel(config, devID, embDim, config.model.encoderL1Norm);
        fnnLayerNorms[i].InitModel(config, devID, embDim, config.model.encoderL1Norm);
    }
}