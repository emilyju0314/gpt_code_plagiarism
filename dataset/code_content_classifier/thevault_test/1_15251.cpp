NvDlaError engine_ast::ConcatenationNode::verifySurfaceIsPartOfConcat
(
    surface::TensorSurfaceDesc* srcTSD,
    surface::TensorSurfaceDesc* dstTSD,
    engine_ast::ConcatAxis axis
)
{
    NvDlaError e = NvDlaSuccess;
    Dims4 srcDims = suggestSurfaceDims(srcTSD);
    Dims4 dstDims = suggestSurfaceDims(dstTSD);

    if (axis.v() == engine_ast::ConcatAxisEnum::CONCAT_ALONG_C)
    {
        /* some of the src tensors could be smaller in WxH than the dst
         * if at least one of the concat participants is Winogradable
         */
        if (srcDims.w > dstDims.w || srcDims.h > dstDims.h)
        {
            gLogError << "In-" << srcTSD->id() << " WxH : "
                      << srcDims.w << "x" << srcDims.h << endl;
            gLogError << "Out-" << dstTSD->id() << " WxH : "
                      << dstDims.w << "x" << dstDims.h << endl;
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "(%s) Concat along C should have "
                    "WxH of all input edges <= that of the output tensor", name().c_str());
        }
    }
    else if (axis.v() == engine_ast::ConcatAxisEnum::CONCAT_ALONG_H)
    {
        if (srcDims.w != dstDims.w || srcDims.c != dstDims.c)
        {
            gLogError << "In-" << srcTSD->id() << " WxC : "
                      << srcDims.w << "x" << srcDims.c << endl;
            gLogError << "Out-" << dstTSD->id() << " WxC : "
                      << dstDims.w << "x" << dstDims.c << endl;
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "(%s) Concat along H should have "
                    "all edges of the same WxC", name().c_str());
        }
    }
    else if (axis.v() == engine_ast::ConcatAxisEnum::CONCAT_ALONG_W)
    {
        if (srcDims.h != dstDims.h || srcDims.c != dstDims.c)
        {
            gLogError << "In-" << srcTSD->id() << " HxC : "
                      << srcDims.h << "x" << srcDims.c << endl;
            gLogError << "Out-" << dstTSD->id() << " HxC : "
                      << dstDims.h << "x" << dstDims.c << endl;
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "(%s) Concat along W should have "
                    "all edges of the same HXC", name().c_str());
        }
    }
    else
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Unknown concat axis: %s", axis.c_str());
    }

fail:
     return e;
}