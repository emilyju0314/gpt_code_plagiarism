void TrainDataSet::Init(NMTConfig& cfg, bool isTrainDataset)
{
    bufIdx = 0;
    config = &cfg;
    isTraining = isTrainDataset;

    if (isTraining)
        fp = fopen(config->training.trainFN, "rb");
    else
        fp = fopen(config->training.validFN, "rb");
    CheckNTErrors(fp, "Failed to open the training/validation file");

    /* skip the meta information */
    int meta_info[6];
    fread(meta_info, sizeof(*meta_info), 6, fp);

    /* load the number of training samples */
    fread(&sampleNum, sizeof(sampleNum), 1, fp);
    CheckNTErrors(sampleNum > 0, "There is no training/validation data");

    /* reset the buffer size */
    config->common.bufSize = sampleNum;

    LoadBatchToBuf();
}