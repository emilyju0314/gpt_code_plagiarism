int DataSetBase::MaxTgtLen(int begin, int end) {
    CheckNTErrors((end > begin) && (begin >= 0)
                 && (end <= buf->count), "Invalid range");
    int maxLen = 0;
    for (int i = begin; i < end; i++) {
        IntList* tgtSent = ((Sample*)buf->Get(i))->tgtSeq;
        maxLen = MAX(int(tgtSent->Size()), maxLen);
    }
    return maxLen;
}