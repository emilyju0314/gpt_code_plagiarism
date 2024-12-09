NvDlaError engine_ast::SDPScaleOpNode::rescaleScaleDataForNoFusedConv()
{
    NvDlaError e = NvDlaSuccess;

    std::vector<NvF32> trnsFp32Scale;

    std::vector<NvF32> inTensorScales = inputEdges().at(0)->originalTensor()->getChannelScales();
    std::vector<NvF32> outTensorScales = outputEdges().at(0)->originalTensor()->getChannelScales();
    NvF32 perTensorInTensorScale = inTensorScales.at(0);
    NvF32 perTensorOutTensorScale = outTensorScales.at(0);

    Weights origScaleBlob = params().rawScaleData();
    Dims4 origScaleDims = params().scaleDims();

    Weights trnsScaleBlob = Weights(nvdla::DataType::FLOAT, NULL, 0);
    NvF32 *trnsScaleData = NULL;
    NvU32 trnsCnt = 0;

    // Preliminary checks
    ASSERT(inTensorScales.size() == (size_t)inputEdges().at(0)->tensorSurfaceDesc()->dimensions().c);
    for (NvF32 its = 1; its < inTensorScales.size(); ++its)
    {
        if ( perTensorInTensorScale != inTensorScales[its] )
        {
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Channel scales should be same for input of %s when PER_TENSOR "
                                    "scaling is ON", name().c_str());
        }
    }

    ASSERT(outTensorScales.size() == (size_t)outputEdges().at(0)->tensorSurfaceDesc()->dimensions().c);
    for (NvF32 ots = 1; ots < outTensorScales.size(); ++ots)
    {
        if ( perTensorOutTensorScale != outTensorScales[ots] )
        {
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Channel scales should be same for output of %s when PER_TENSOR "
                                    "scaling is ON", name().c_str());
        }
    }

    // Convert scale data into float and get it as vector
    trnsFp32Scale.clear();
    PROPAGATE_ERROR_FAIL(getFp32ScaleData(origScaleBlob, trnsFp32Scale));
    ASSERT(trnsFp32Scale.size() == (NvU32)origScaleBlob.count);

    trnsScaleData =
        reinterpret_cast<NvF32*>(
            engine_ast::MemoryCollector::getInstance()->allocateMemory(origScaleBlob.count * sizeof(NvF32))
        );

    for (NvS32 cc = 0; cc < origScaleDims.c; cc++)
    {
        for (NvS32 hh = 0; hh < origScaleDims.h; hh++)
        {
            for (NvS32 ww = 0; ww < origScaleDims.w; ww++)
            {
                NvU32 offset =  ww +
                                origScaleDims.w * ( hh +
                                origScaleDims.h * (cc) );
                trnsScaleData[offset] = ((trnsFp32Scale.at(offset) * perTensorInTensorScale) / perTensorOutTensorScale);
                trnsCnt++;
                if (graph()->debugQuantization())
                {
                    gLogInfo << name() << " rawScl * Si / So: " << trnsFp32Scale.at(offset)
                             << " * " << perTensorInTensorScale << " / "
                             << perTensorOutTensorScale << " = " << trnsScaleData[offset] << endl;
                }
            }
        }
    }

    trnsScaleBlob.type = nvdla::DataType::FLOAT;
    trnsScaleBlob.count = trnsCnt;
    trnsScaleBlob.values = trnsScaleData;

    params().setRawScaleData(trnsScaleBlob);

fail:
    return e;
}