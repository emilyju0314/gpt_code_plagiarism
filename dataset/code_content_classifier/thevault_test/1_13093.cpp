void Translator::DumpResToFile(const char* ofn)
{
    ofstream f(ofn);
    int sentNum = batchLoader.appendEmptyLine ? outputBuf->Size() - 1 : outputBuf->Size();
    for (int i = 0; i < sentNum; i++) {
        Sample* sample = (Sample*)outputBuf->Get(i);
        if (sample->tgtSeq != NULL) {
            for (int j = 0; j < sample->tgtSeq->Size(); j++) {
                int id = sample->tgtSeq->Get(j);
                f << batchLoader.tgtVocab.id2token[id] << " ";
            }
        }
        f << "\n";
    }
    f.close();
}