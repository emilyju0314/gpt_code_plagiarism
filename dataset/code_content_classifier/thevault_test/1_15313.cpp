NvDlaError Runtime::mergeSetTensorDesc(IOD iod, int bindId, int tensorDescId, const IRuntime::NvDlaTensor *tdl)
{
    Runtime::TensorDesc *origEntry = 0;
    const NvU32 *newStrides = 0;
    NvU32 *oldStrides = 0;
    bool nameDiff = false;
    bool stridesDiff = false, dimsDiff; //, sizeDiff;
    bool dataFormatDiff, dataTypeDiff, dataCategoryDiff;
    bool pixelFormatDiff, pixelMappingDiff;

    NvDlaError e = NvDlaSuccess;

    if ( (tensorDescId < 0) || (size_t(tensorDescId) >= m_tensor_desc.size()) )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Tensor desc id out of range:%d", tensorDescId);
    }

    origEntry = &m_tensor_desc[tensorDescId];

    newStrides = &tdl->stride[0];
    oldStrides = &(origEntry->stride[0]);

    nameDiff = (std::strncmp(tdl->name, origEntry->name.c_str(), sizeof(tdl->name)) != 0);

    stridesDiff = false;

    dimsDiff = ( (origEntry->dims.n != tdl->dims.n) ||
                 (origEntry->dims.c != tdl->dims.c) ||
                 (origEntry->dims.h != tdl->dims.h) ||
                 (origEntry->dims.w != tdl->dims.w) );

    for ( size_t ss = 0; ss < NVDLA_RUNTIME_TENSOR_DESC_NUM_STRIDES; ++ss )
    {
        // assume the worst for now.  avoid missing a set which was actually needed.
        stridesDiff = true; // stridesDiff || (oldStrides[ss] != newStrides[ss]);
    }

    dataFormatDiff   = origEntry->dataFormat   != tdl->dataFormat;
    dataTypeDiff     = origEntry->dataType     != tdl->dataType;
    dataCategoryDiff = origEntry->dataCategory != tdl->dataCategory;

    pixelFormatDiff  = origEntry->pixelFormat  != tdl->pixelFormat;
    pixelMappingDiff = origEntry->pixelMapping != tdl->pixelMapping;

    // Name changes are not supported
    if ( nameDiff )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported, "name change requested");
    }

    // at the moment no formatting changes are allowed.  eventually we may be
    // in a position to do inline or hand-off formatting operations.
    if ( dataFormatDiff || dataTypeDiff || dataCategoryDiff )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_NotImplemented, "data format/type/category change requested");
    }

    // pixel format and mapping changes are unlikely to be allowed
    if ( pixelFormatDiff || pixelMappingDiff )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported, "pixel format/mapping change requested");
    }

    if ( dimsDiff )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported, "dimensions change requested");
    }

    if ( stridesDiff )
    {
        // the way this works, whatever was written last is what will be set thereafter.
        // even if extra work is required.  it's sticky.
        for ( size_t ss = 0; ss < NVDLA_RUNTIME_TENSOR_DESC_NUM_STRIDES; ++ss )
        {
            oldStrides[ss] = newStrides[ss];
        }

        PROPAGATE_ERROR_FAIL( rewriteStrides(iod, bindId, tensorDescId, newStrides) );
    }

 fail:
    return e;
}