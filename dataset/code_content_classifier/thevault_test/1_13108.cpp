void NMTModel::InitModel(NMTConfig& myConfig)
{
    config = &myConfig;
    devID = config->common.devID;

    /* configurations for the model */
    vector<int*> intConfig = GetIntConfigs();

    FILE* modelFile = NULL;
    modelFile = fopen(config->common.modelFN, "rb");

    /* read model configurations */
    if (modelFile) {

        CheckNTErrors(modelFile, "Failed to open the model file");

        LOG("loading configurations from the model file...");

        fread(&(config->model.encoderL1Norm), sizeof(bool), 1, modelFile);
        fread(&(config->model.decoderL1Norm), sizeof(bool), 1, modelFile);
        fread(&(config->model.useBigAtt), sizeof(bool), 1, modelFile);
        fread(&(config->model.encFinalNorm), sizeof(bool), 1, modelFile);
        fread(&(config->model.decFinalNorm), sizeof(bool), 1, modelFile);
        fread(&(config->model.encPreLN), sizeof(bool), 1, modelFile);
        fread(&(config->model.decPreLN), sizeof(bool), 1, modelFile);
        fread(&(config->model.useEncHistory), sizeof(bool), 1, modelFile);
        fread(&(config->model.useDecHistory), sizeof(bool), 1, modelFile);
        fread(&(config->model.shareEncDecEmb), sizeof(bool), 1, modelFile);
        fread(&(config->model.shareDecInputOutputEmb), sizeof(bool), 1, modelFile);

        int maxSrcLen = config->model.maxSrcLen;
        for (auto c : intConfig) {
            fread(c, sizeof(int), 1, modelFile);
        }
        /* reset the maximum source sentence length */
        config->model.maxSrcLen = MIN(maxSrcLen, config->model.maxSrcLen);
    }

    if (config->training.isTraining) {

        /* currently we do not support training with FP16 */
        config->common.useFP16 = false;

        /* read the source & target vocab size and special tokens from the training file */
        FILE* trainF = fopen(config->training.trainFN, "rb");
        CheckNTErrors(trainF, "Failed to open the training file");

        LOG("loading configurations of the training data...");

        fread(&(config->model.srcVocabSize), sizeof(int), 1, trainF);
        fread(&(config->model.tgtVocabSize), sizeof(int), 1, trainF);
        fread(&(config->model.pad), sizeof(int), 1, trainF);
        fread(&(config->model.sos), sizeof(int), 1, trainF);
        fread(&(config->model.eos), sizeof(int), 1, trainF);
        fread(&(config->model.unk), sizeof(int), 1, trainF);
        CheckNTErrors(config->model.srcVocabSize > 0, "Invalid source vocabulary size");
        CheckNTErrors(config->model.tgtVocabSize > 0, "Invalid target vocabulary size");
        fclose(trainF);

        /* start incremental training from a checkpoint */
        if (modelFile) {
            config->training.incremental = true;
        }
    }

    encoder->InitModel(*config);
    decoder->InitModel(*config);
    outputLayer->InitModel(*config);

    /* share encoder&decoder embeddings */
    if (config->model.shareEncDecEmb) {
        decoder->embedder = &(encoder->embedder);
        LOG("share encoder decoder embeddings");
    }

    /* share embeddings with output weights */
    if (config->model.shareDecInputOutputEmb) {
        outputLayer->w = decoder->embedder->w;
        LOG("share decoder embeddings with output weights");
    }

    ShowModelConfig();

    /* load parameters for translation or incremental training */
    if (config->training.incremental || (!config->training.isTraining))
        LoadFromFile(modelFile);

    if (config->training.isTraining) {
        TensorList params;
        GetParams(params);
        for (int i = 0; i < params.Size(); i++)
            AddParam(params[i]);
    }

    if (modelFile)
        fclose(modelFile);
}