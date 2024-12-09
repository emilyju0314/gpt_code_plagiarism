void AttDecoder::InitModel(NMTConfig& config)
{
    SetTrainingFlag(config.training.isTraining);
    devID = config.common.devID;
    preLN = config.model.decPreLN;
    dropoutP = config.model.dropout;
    embDim = config.model.decEmbDim;
    vSize = config.model.tgtVocabSize;
    nlayer = config.model.decLayerNum;
    finalNorm = config.model.decFinalNorm;
    useHistory = config.model.useDecHistory;
    shareEncDecEmb = config.model.shareEncDecEmb;

    CheckNTErrors(vSize > 1, "Set vocabulary size by \"-vsizetgt\"");
    CheckNTErrors(nlayer >= 1, "We have one encoding layer at least!");

    /* remove the FFN modules in some Transformer variants */
    if (config.model.decFFNHiddenDim > 0)
        ffns = new FFN[nlayer];
    selfAtts = new Attention[nlayer];
    enDeAtts = new Attention[nlayer];
    selfAttCache = new Cache[nlayer];
    enDeAttCache = new Cache[nlayer];
    ffnLayerNorms = new LayerNorm[nlayer];
    selfAttLayerNorms = new LayerNorm[nlayer];
    enDeAttLayerNorms = new LayerNorm[nlayer];

    if (useHistory) {
        history = new LayerHistory;
        history->InitModel(config, false);
    }
    if (!config.model.shareEncDecEmb) {
        embedder = new Embedder();
        embedder->InitModel(config, false);
    }
    if (finalNorm) {
        decoderLayerNorm = new LayerNorm;
        decoderLayerNorm->InitModel(config, devID, embDim, config.model.decoderL1Norm);
    }

    /* initialize the stacked layers */
    for (int i = 0; i < nlayer; i++) {
        if (ffns != NULL)
            ffns[i].InitModel(config, false);
        selfAtts[i].InitModel(config, false, true);
        enDeAtts[i].InitModel(config, false, false);
        ffnLayerNorms[i].InitModel(config, devID, embDim, config.model.decoderL1Norm);
        selfAttLayerNorms[i].InitModel(config, devID, embDim, config.model.decoderL1Norm);
        enDeAttLayerNorms[i].InitModel(config, devID, embDim, config.model.decoderL1Norm);
    }
}