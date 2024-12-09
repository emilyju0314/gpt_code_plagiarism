inline int TrainDataSet::GetBucket()
{
    int sent = 0;
    int bucketKey = ((Sample*)(buf->Get(bufIdx)))->bucketKey;

    while ((sent < (int(buf->Size()) - bufIdx)) &&
          (((Sample*)(buf->Get(bufIdx + sent)))->bucketKey == bucketKey)) {
        sent++;
    }

    sent = MIN(sent, (int(buf->Size()) - bufIdx));
    CheckNTErrors(sent > 0, "Invalid batch size");

    return sent;
}