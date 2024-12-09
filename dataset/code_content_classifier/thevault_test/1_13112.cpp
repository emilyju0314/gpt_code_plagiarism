int DataSetBase::MaxSrcLen(int begin, int end) {
    CheckNTErrors((end > begin) && (begin >= 0)
                 && (end <= buf->count), "Invalid range");
    int maxLen = 0;
    for (int i = begin; i < end; i++) {
        IntList* srcSent = ((Sample*)buf->Get(i))->srcSeq;
        maxLen = MAX(int(srcSent->Size()), maxLen);
    }
    return maxLen;
}