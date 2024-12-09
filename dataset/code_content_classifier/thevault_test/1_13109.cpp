void NMTModel::DumpToFile(const char* fn)
{
    double startT = GetClockSec();
    FILE* modelFile = fopen(fn, "wb");
    CheckNTErrors(modelFile, "Cannot open the model file");

    vector<int*> intConfig = GetIntConfigs();

    /* save the configurations */
    fwrite(&(config->model.encoderL1Norm), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.decoderL1Norm), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.useBigAtt), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.encFinalNorm), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.decFinalNorm), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.encPreLN), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.decPreLN), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.useEncHistory), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.useDecHistory), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.shareEncDecEmb), sizeof(bool), 1, modelFile);
    fwrite(&(config->model.shareDecInputOutputEmb), sizeof(bool), 1, modelFile);
    for (auto c : intConfig) {
        fwrite(c, sizeof(int), 1, modelFile);
    }

    /* save the model parameters */
    TensorList params;
    GetParams(params);
    for (int i = 0; i < params.Size(); i++) {
        params[i]->BinaryDump(modelFile);
    }

    fclose(modelFile);
    double elapsed = GetClockSec() - startT;
    LOG("model saved (took %.1fs)", elapsed);
}