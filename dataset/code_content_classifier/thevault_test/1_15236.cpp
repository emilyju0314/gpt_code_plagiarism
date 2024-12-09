NvU32 PitchLinearSurfaceDesc::lineStride(const TensorSurfaceDesc* tsd)
{
    NvDlaError e = NvDlaSuccess;
    NVDLA_UNUSED(e);
    NvU32 lineStride   = 0;
    NvU8 bpe = tsd->surfaceFormat().bytesPerElement();
    NvS8  cpa  = tsd->surfaceFormat().channelsPerAtom();

    if (tsd->surfaceFormat().v() > SurfaceFormatEnum::NVDLA_IMG_Y16___V16U16_N444)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Surface Format %s is not Pitch Linear", tsd->surfaceFormat().c_str());
    }

    if (tsd->surfaceFormat().v() < SurfaceFormatEnum::NVDLA_IMG_Y8___U8V8_N444)
    {
        // interleave format, single plannar
        lineStride   = ROUNDUP_AND_ALIGN(tsd->dimensions().w * bpe * cpa, 32);
    }
    else
    {
        lineStride   = ROUNDUP_AND_ALIGN(tsd->dimensions().w * bpe, 32);
    }

fail:
    return lineStride;
}