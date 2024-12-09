void GraphicsContext::BuildNggCullingControlRegister()
{
    const auto& vpState = m_pPipelineInfo->vpState;
    const auto& rsState = m_pPipelineInfo->rsState;

    auto& pipelineState = m_nggControl.primShaderTable.pipelineStateCb;

    //
    // Program register PA_SU_SC_MODE_CNTL
    //
    PaSuScModeCntl paSuScModeCntl;
    paSuScModeCntl.u32All = 0;

    paSuScModeCntl.bits.POLY_OFFSET_FRONT_ENABLE = rsState.depthBiasEnable;
    paSuScModeCntl.bits.POLY_OFFSET_BACK_ENABLE  = rsState.depthBiasEnable;
    paSuScModeCntl.bits.MULTI_PRIM_IB_ENA        = true;

    paSuScModeCntl.bits.POLY_MODE            = (rsState.polygonMode != VK_POLYGON_MODE_FILL);

    if (rsState.polygonMode == VK_POLYGON_MODE_FILL)
    {
        paSuScModeCntl.bits.POLYMODE_BACK_PTYPE  = POLY_MODE_TRIANGLES;
        paSuScModeCntl.bits.POLYMODE_FRONT_PTYPE = POLY_MODE_TRIANGLES;
    }
    else if (rsState.polygonMode == VK_POLYGON_MODE_LINE)
    {
        paSuScModeCntl.bits.POLYMODE_BACK_PTYPE  = POLY_MODE_LINES;
        paSuScModeCntl.bits.POLYMODE_FRONT_PTYPE = POLY_MODE_LINES;
    }
    else if (rsState.polygonMode == VK_POLYGON_MODE_POINT)
    {
        paSuScModeCntl.bits.POLYMODE_BACK_PTYPE  = POLY_MODE_POINTS;
        paSuScModeCntl.bits.POLYMODE_FRONT_PTYPE = POLY_MODE_POINTS;
    }
    else
    {
        LLPC_NEVER_CALLED();
    }

    paSuScModeCntl.bits.CULL_FRONT = ((rsState.cullMode == VK_CULL_MODE_FRONT_BIT) ||
                                      (rsState.cullMode == VK_CULL_MODE_FRONT_AND_BACK));
    paSuScModeCntl.bits.CULL_BACK  = ((rsState.cullMode == VK_CULL_MODE_BACK_BIT) ||
                                      (rsState.cullMode == VK_CULL_MODE_FRONT_AND_BACK));

    paSuScModeCntl.bits.FACE = rsState.frontFace;

    pipelineState.paSuScModeCntl = paSuScModeCntl.u32All;

    //
    // Program register PA_CL_CLIP_CNTL
    //
    PaClClipCntl paClClipCntl;
    LLPC_ASSERT((rsState.usrClipPlaneMask & ~0x3F) == 0);
    paClClipCntl.u32All = rsState.usrClipPlaneMask;

    paClClipCntl.bits.DX_CLIP_SPACE_DEF = true;
    paClClipCntl.bits.DX_LINEAR_ATTR_CLIP_ENA = true;

    if (vpState.depthClipEnable == false)
    {
        paClClipCntl.bits.ZCLIP_NEAR_DISABLE = true;
        paClClipCntl.bits.ZCLIP_FAR_DISABLE  = true;
    }

    if (rsState.rasterizerDiscardEnable)
    {
        paClClipCntl.bits.DX_RASTERIZATION_KILL = true;
    }

    pipelineState.paClClipCntl = paClClipCntl.u32All;

    //
    // Program register PA_CL_VTE_CNTL
    //
    PaClVteCntl paClVteCntl;
    paClVteCntl.u32All = 0;

    paClVteCntl.bits.VPORT_X_SCALE_ENA  = true;
    paClVteCntl.bits.VPORT_X_OFFSET_ENA = true;
    paClVteCntl.bits.VPORT_Y_SCALE_ENA  = true;
    paClVteCntl.bits.VPORT_Y_OFFSET_ENA = true;
    paClVteCntl.bits.VPORT_Z_SCALE_ENA  = true;
    paClVteCntl.bits.VPORT_Z_OFFSET_ENA = true;
    paClVteCntl.bits.VTX_W0_FMT         = true;

    pipelineState.paClVteCntl = paClVteCntl.u32All;
}