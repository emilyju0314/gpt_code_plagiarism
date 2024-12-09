NvDlaError engine_ast::SDPScaleOpNode::rescaleScaleDataForPerFilter()
{
    NvDlaError e = NvDlaSuccess;

    ConvCoreNode* fusedConv;

    /* Different scalars */
    std::vector<NvF32> filterScales;
    std::vector<NvF32> inTensorScales;
    std::vector<NvF32> outTensorScales;

    NvF32 perTensorInTensorScale;
    NvF32 perTensorOutTensorScale;

    /* Original data of scale */
    engine_ast::SDPMode scaleMode;
    Dims4 origScaleDims;
    Weights origScaleBlob;

    std::vector<NvF32> trnsFp32Scale;

    Weights trnsScaleBlob = Weights(nvdla::DataType::FLOAT, NULL, 0);
    NvF32 *trnsScaleData = NULL;
    NvU32 trnsCnt = 0;

    fusedConv = NodeFactory::nodeCast<ConvCoreNode*>(dependencyParams(0).fusedNode(IODirectionEnum::INPUT));
    if (fusedConv == NULL)
    {
        // Rescale only if fused conv available.
        goto fail;
    }

    filterScales = fusedConv->params().filterScales();
    inTensorScales = fusedConv->inputEdges().at(0)->originalTensor()->getChannelScales();
    outTensorScales = outputEdges().at(0)->originalTensor()->getChannelScales();

    perTensorInTensorScale = inTensorScales.at(0);
    perTensorOutTensorScale = outTensorScales.at(0);

    origScaleBlob = params().rawScaleData();
    origScaleDims = params().scaleDims();
    scaleMode = params().x1Params().mode();

    // Preliminary checks
    ASSERT(filterScales.size() == (size_t)outputEdges().at(0)->tensorSurfaceDesc()->dimensions().c);

    ASSERT(inTensorScales.size() == (size_t)fusedConv->inputEdges().at(0)->tensorSurfaceDesc()->dimensions().c);
    for (NvF32 its = 1; its < inTensorScales.size(); ++its)
    {
        if ( perTensorInTensorScale != inTensorScales[its] )
        {
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Channel scales should be same for input of %s when PER_TENSOR "
                                    "scaling is ON", fusedConv->name().c_str());
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

    // With PER_FILTER quantization mode, scale data can never be PER_LAYER.
    if (scaleMode.v() == engine_ast::SDPModeEnum::SDP_MODE_PER_LAYER)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Invalid SDP mode: %s when PER_FILTER is ON",
                            scaleMode.c_str());
    }

    // Convert scale data into float and get it as vector
    trnsFp32Scale.clear();
    PROPAGATE_ERROR_FAIL(getFp32ScaleData(origScaleBlob, trnsFp32Scale));
    ASSERT(trnsFp32Scale.size() == (NvU32)origScaleBlob.count);

    trnsScaleData =
        reinterpret_cast<NvF32*>(
            engine_ast::MemoryCollector::getInstance()->allocateMemory(origScaleBlob.count * sizeof(NvF32))
        );

    // Rescale based on filter values. Considering it to NCHW format.
    for (NvS32 cc = 0; cc < origScaleDims.c; cc++)
    {
        NvF32 perChannelScale = filterScales.at(cc);
        for (NvS32 hh = 0; hh < origScaleDims.h; hh++)
        {
            for (NvS32 ww = 0; ww < origScaleDims.w; ww++)
            {
                NvU32 offset =  ww +
                                origScaleDims.w * ( hh +
                                origScaleDims.h * (cc) );
                trnsScaleData[offset] =
                    (((trnsFp32Scale.at(offset) * perChannelScale) * perTensorInTensorScale) / perTensorOutTensorScale);
                trnsCnt++;
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