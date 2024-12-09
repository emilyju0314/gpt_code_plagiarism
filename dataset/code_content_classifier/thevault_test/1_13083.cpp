Sample* TrainDataSet::LoadSample()
{
    int srcLen;
    int tgtLen;

    fread(&srcLen, sizeof(srcLen), 1, fp);
    fread(&tgtLen, sizeof(tgtLen), 1, fp);

    CheckNTErrors(srcLen > 0, "Invalid source sentence length");
    CheckNTErrors(tgtLen > 0, "Invalid target sentence length");

    IntList* srcSent = new IntList(srcLen);
    IntList* tgtSent = new IntList(tgtLen);
    srcSent->ReadFromFile(fp, srcLen);
    tgtSent->ReadFromFile(fp, tgtLen);

    Sample* sample = new Sample(srcSent, tgtSent, 0);
    
    return sample;
}