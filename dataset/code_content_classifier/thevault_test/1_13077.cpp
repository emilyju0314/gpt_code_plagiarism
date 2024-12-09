void CommonConfig::Load(int argsNum, const char** args)
{
    Create(argsNum, args);
    LoadString("model", modelFN, "model.bin");
    LoadString("srcvocab", srcVocabFN, "");
    LoadString("tgtvocab", tgtVocabFN, "");
    LoadInt("seed", &seed, 1);
    LoadInt("dev", &devID, -1);
    LoadInt("sbatch", &sBatchSize, 32);
    LoadInt("wbatch", &wBatchSize, 4096);
    LoadInt("bufsize", &bufSize, 2000000);
    LoadInt("bucketsize", &bucketSize, wBatchSize);
    LoadInt("loginterval", &logInterval, 100);
    LoadBool("fp16", &useFP16, false);
}