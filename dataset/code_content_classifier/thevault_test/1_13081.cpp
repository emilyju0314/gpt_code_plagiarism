void TrainDataSet::BuildBucket()
{
    int idx = 0;

    /* build buckets by the length of source and target sentences */
    while (idx < int(buf->Size())) {

        /* sentence number in a bucket */
        int sentNum = 1;

        /* get the maximum source sentence length in a bucket */
        int maxSrcLen = MaxSrcLen(idx, idx + sentNum);
        int maxTgtLen = MaxTgtLen(idx, idx + sentNum);
        int maxLen = MAX(maxSrcLen, maxTgtLen);

        /* the maximum sentence number in a bucket */
        const int MAX_SENT_NUM = 5120;

        while ((sentNum < (buf->count - idx))
            && (sentNum < MAX_SENT_NUM)
            && (sentNum * maxLen <= config->common.bucketSize)) {
            sentNum++;
            maxSrcLen = MaxSrcLen(idx, idx + sentNum);
            maxTgtLen = MaxTgtLen(idx, idx + sentNum);
            maxLen = MAX(maxSrcLen, maxTgtLen);
        }

        /* make sure the number is valid */
        if ((sentNum) * maxLen > config->common.bucketSize || sentNum >= MAX_SENT_NUM) {
            sentNum--;
            sentNum = max(8 * (sentNum / 8), sentNum % 8);
        }
        if ((int(buf->Size()) - idx) < sentNum)
            sentNum = int(buf->Size()) - idx;

        /* assign the same key for items in a bucket */
        for (int i = 0; i < sentNum; i++)
            ((Sample*)(buf->Get(idx + i)))->bucketKey = idx;

        randomKeys.Add(idx);
        idx += sentNum;
    }

    /* shuffle buckets */
    ShuffleBuckets();
}