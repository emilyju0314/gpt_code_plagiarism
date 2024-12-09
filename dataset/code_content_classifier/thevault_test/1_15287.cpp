NvDlaError engine_ast::SDPScaleOpNode::rescaleScaleDataForPerKernel()
{
    NvDlaError e = NvDlaSuccess;

    ConvCoreNode* fusedConv;

    std::vector<NvF32> filterScales;
    std::vector<NvF32> inTensorScales;
    std::vector<NvF32> outTensorScales;
    NvF32 perKernelScale;
    NvF32 perTensorInTensorScale;
    NvF32 perTensorOutTensorScale;

    Weights origScaleBlob;
    Dims4 origScaleDims;

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
    perKernelScale = filterScales.at(0);
    inTensorScales = fusedConv->inputEdges().at(0)->originalTensor()->getChannelScales();
    perTensorInTensorScale = inTensorScales.at(0);
    outTensorScales = outputEdges().at(0)->originalTensor()->getChannelScales();
    perTensorOutTensorScale = outTensorScales.at(0);

    origScaleBlob = params().rawScaleData();
    origScaleDims = params().scaleDims();

    // Preliminary checks
    ASSERT(filterScales.size() == (size_t)outputEdges().at(0)->tensorSurfaceDesc()->dimensions().c);
    for (NvU32 ff = 1; ff < filterScales.size(); ++ff)
    {
        if ( perKernelScale != filterScales[ff] )
        {
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Filter scales should be same for %s when PER_KERNEL "
                                    "quantization is ON", fusedConv->name().c_str());
        }
    }

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
        for (NvS32 hh = 0; hh < origScaleDims.h; hh++)
        {
            for (NvS32 ww = 0; ww < origScaleDims.w; ww++)
            {
                NvU32 offset =  ww +
                                origScaleDims.w * ( hh +
                                origScaleDims.h * (cc) );
                trnsScaleData[offset] =
                    (((trnsFp32Scale.at(offset) * perKernelScale) * perTensorInTensorScale) / perTensorOutTensorScale);
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