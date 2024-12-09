bool TrainDataSet::GetBatchSimple(XList* inputs, XList* golds)
{
    if (bufIdx == buf->Size()) {
        if (isTraining)
            ShuffleBuckets();
        else
            bufIdx = 0;
    }

    wc = 0;
    sc = isTraining ? GetBucket() : config->common.sBatchSize;
    sc = MIN(sc, buf->Size() - bufIdx);

    /* get the maximum sentence length in a mini-batch */
    int maxSrcLen = MaxSrcLen(bufIdx, bufIdx + sc);
    int maxTgtLen = MaxTgtLen(bufIdx, bufIdx + sc);

    CheckNTErrors(maxSrcLen > 0, "Invalid source length for batching");
    CheckNTErrors(maxTgtLen > 0, "Invalid target length for batching");

    int* batchEncValues = new int[sc * maxSrcLen];
    float* paddingEncValues = new float[sc * maxSrcLen];

    int* labelVaues = new int[sc * maxTgtLen];
    int* batchDecValues = new int[sc * maxTgtLen];
    float* paddingDecValues = new float[sc * maxTgtLen];

    for (int i = 0; i < sc * maxSrcLen; i++) {
        batchEncValues[i] = config->model.pad;
        paddingEncValues[i] = 1.0F;
    }
    for (int i = 0; i < sc * maxTgtLen; i++) {
        batchDecValues[i] = config->model.pad;
        labelVaues[i] = config->model.pad;
        paddingDecValues[i] = 1.0F;
    }

    int curSrc = 0;
    int curTgt = 0;

    /*
    batchEnc: end with EOS (left padding)
    batchDec: begin with SOS (right padding)
    label:    end with EOS (right padding)
    */
    for (int i = 0; i < sc; ++i) {

        Sample* sample = (Sample*)(buf->Get(bufIdx + i));
        wc += int(sample->tgtSeq->Size());

        curSrc = maxSrcLen * i;
        for (int j = 0; j < int(sample->srcSeq->Size()); j++)
            batchEncValues[curSrc++] = sample->srcSeq->Get(j);

        curTgt = maxTgtLen * i;
        for (int j = 0; j < int(sample->tgtSeq->Size()); j++) {
            if (j > 0)
                labelVaues[curTgt - 1] = sample->tgtSeq->Get(j);
            batchDecValues[curTgt++] = sample->tgtSeq->Get(j);
        }
        labelVaues[curTgt - 1] = config->model.eos;
        while (curSrc < maxSrcLen * (i + 1))
            paddingEncValues[curSrc++] = 0;
        while (curTgt < maxTgtLen * (i + 1))
            paddingDecValues[curTgt++] = 0;
    }

    XTensor * batchEnc = ((TensorList*)(inputs))->Get(0);
    XTensor * paddingEnc = ((TensorList*)(inputs))->Get(1);
    XTensor * batchDec = ((TensorList*)(golds))->Get(0);
    XTensor * paddingDec = ((TensorList*)(golds))->Get(1);
    XTensor * label = ((TensorList*)(golds))->Get(2);

    InitTensor2D(batchEnc, sc, maxSrcLen, X_INT);
    InitTensor2D(paddingEnc, sc, maxSrcLen, X_FLOAT);
    InitTensor2D(batchDec, sc, maxTgtLen, X_INT);
    InitTensor2D(paddingDec, sc, maxTgtLen, X_FLOAT);
    InitTensor2D(label, sc, maxTgtLen, X_INT);

    bufIdx += sc;

    batchEnc->SetData(batchEncValues, batchEnc->unitNum);
    paddingEnc->SetData(paddingEncValues, paddingEnc->unitNum);
    batchDec->SetData(batchDecValues, batchDec->unitNum);
    paddingDec->SetData(paddingDecValues, paddingDec->unitNum);
    label->SetData(labelVaues, label->unitNum);

    delete[] batchEncValues;
    delete[] paddingEncValues;
    delete[] batchDecValues;
    delete[] paddingDecValues;
    delete[] labelVaues;

    return true;
}