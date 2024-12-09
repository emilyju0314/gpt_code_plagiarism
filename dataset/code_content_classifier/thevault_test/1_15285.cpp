NvDlaError engine_ast::SDPScaleOpNode::getFp32ScaleData
(
    const Weights data,
    std::vector<NvF32>& trnsFp32Scale
)
{
    NvDlaError e = NvDlaSuccess;

    if (data.count <= 0 || data.values == NULL)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Invalid scale data provided");
    }

    for (NvU32 ii = 0; ii < data.count; ii++)
    {
        NvF32 scaleValue = 0;
        switch(data.type)
        {
            case nvdla::DataType::FLOAT:
                scaleValue = static_cast<NvF32>(reinterpret_cast<NvF32*>(const_cast<void*>(data.values))[ii]);
                break;
            case nvdla::DataType::HALF:
                scaleValue = static_cast<NvF32>(reinterpret_cast<half_float::half*>(const_cast<void*>(data.values))[ii]);
                break;
            case nvdla::DataType::INT16:
                scaleValue = static_cast<NvF32>(reinterpret_cast<NvS16*>(const_cast<void*>(data.values))[ii]);
                break;
            case nvdla::DataType::INT8:
                scaleValue = static_cast<NvF32>(reinterpret_cast<NvS8*>(const_cast<void*>(data.values))[ii]);
                break;
            default:
                ORIGINATE_ERROR_FAIL(NvDlaError_NotSupported,
                        "Can't convert scale data which is not FLOAT/HALF/INT16/INT8 for %s",
                        name().c_str());
        }
        trnsFp32Scale.push_back(scaleValue);
    }

fail:
    return e;
}