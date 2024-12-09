bool TrainDataSet::LoadBatchToBuf()
{
    int n = 0;

    while (n < config->common.bufSize) {
        Sample* sample = LoadSample();
        buf->Add(sample);
        n++;
    }
    LOG("loaded %d samples", n);

    /* group samples into buckets */
    SortByTgtLengthAscending();
    SortBySrcLengthAscending();

    /* build buckets for training */
    if (isTraining)
        BuildBucket();

    return true;
}