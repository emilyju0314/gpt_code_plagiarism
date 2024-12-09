vector<int*> NMTModel::GetIntConfigs()
{
    vector<int*> intConfig = {
        &(config->model.encEmbDim),
        &(config->model.encLayerNum),
        &(config->model.encSelfAttHeadNum),
        &(config->model.encFFNHiddenDim),
        &(config->model.decEmbDim),
        &(config->model.decLayerNum),
        &(config->model.decSelfAttHeadNum),
        &(config->model.encDecAttHeadNum),
        &(config->model.decFFNHiddenDim),
        &(config->model.maxRelativeLength),
        &(config->model.maxSrcLen),
        &(config->model.maxTgtLen),
        &(config->model.sos),
        &(config->model.eos),
        &(config->model.pad),
        &(config->model.unk),
        &(config->model.srcVocabSize),
        &(config->model.tgtVocabSize),
    };

    return intConfig;
}