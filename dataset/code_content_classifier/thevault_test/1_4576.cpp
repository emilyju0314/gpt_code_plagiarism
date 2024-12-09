void GraphicsContext::SetNggControl()
{
    // For GFX10+, initialize NGG control settings
    if (m_gfxIp.major < 10)
    {
        return;
    }

    const bool hasTs = ((m_stageMask & (ShaderStageToMask(ShaderStageTessControl) |
                                        ShaderStageToMask(ShaderStageTessEval))) != 0);
    const bool hasGs = ((m_stageMask & ShaderStageToMask(ShaderStageGeometry)) != 0);

    // Check the use of cull distance for NGG primitive shader
    bool useCullDistance = false;
    bool enableXfb = false;
    if (hasGs)
    {
        // TODO: Support GS in primitive shader.
        const auto pResUsage = GetShaderResourceUsage(ShaderStageGeometry);
        enableXfb = pResUsage->inOutUsage.enableXfb;
    }
    else
    {
        if (hasTs)
        {
            const auto pResUsage = GetShaderResourceUsage(ShaderStageTessEval);
            const auto& builtInUsage = pResUsage->builtInUsage.tes;
            useCullDistance = (builtInUsage.cullDistance > 0);
            enableXfb = pResUsage->inOutUsage.enableXfb;
        }
        else
        {
            const auto pResUsage = GetShaderResourceUsage(ShaderStageVertex);
            const auto& builtInUsage = pResUsage->builtInUsage.vs;
            useCullDistance = (builtInUsage.cullDistance > 0);
            enableXfb = pResUsage->inOutUsage.enableXfb;
        }
    }

    const auto& nggState = m_pPipelineInfo->nggState;

    bool enableNgg = nggState.enableNgg;
    if (enableXfb)
    {
        // TODO: If transform feedback is enabled, disable NGG.
        enableNgg = false;
    }

    if (hasGs && (nggState.enableGsUse == false))
    {
        // NOTE: NGG used on GS is disabled by default
        enableNgg = false;
    }

    if (m_pGpuWorkarounds->gfx10.waNggDisabled)
    {
        enableNgg = false;
    }

    m_nggControl.enableNgg                  = enableNgg;
    m_nggControl.alwaysUsePrimShaderTable   = nggState.alwaysUsePrimShaderTable;
    m_nggControl.compactMode                = nggState.compactMode;

    m_nggControl.enableFastLaunch           = nggState.enableFastLaunch;
    m_nggControl.enableVertexReuse          = nggState.enableVertexReuse;
    m_nggControl.enableBackfaceCulling      = nggState.enableBackfaceCulling;
    m_nggControl.enableFrustumCulling       = nggState.enableFrustumCulling;
    m_nggControl.enableBoxFilterCulling     = nggState.enableBoxFilterCulling;
    m_nggControl.enableSphereCulling        = nggState.enableSphereCulling;
    m_nggControl.enableSmallPrimFilter      = nggState.enableSmallPrimFilter;
    m_nggControl.enableCullDistanceCulling  = (nggState.enableCullDistanceCulling && useCullDistance);

    m_nggControl.backfaceExponent           = nggState.backfaceExponent;
    m_nggControl.subgroupSizing             = nggState.subgroupSizing;
    m_nggControl.primsPerSubgroup           = std::min(nggState.primsPerSubgroup, Gfx9::NggMaxThreadsPerSubgroup);
    m_nggControl.vertsPerSubgroup           = std::min(nggState.vertsPerSubgroup, Gfx9::NggMaxThreadsPerSubgroup);

    if (nggState.enableNgg)
    {
        if (nggState.forceNonPassthrough)
        {
            m_nggControl.passthroughMode = false;
        }
        else
        {
            m_nggControl.passthroughMode = (m_nggControl.enableVertexReuse == false) &&
                                           (m_nggControl.enableBackfaceCulling == false) &&
                                           (m_nggControl.enableFrustumCulling == false) &&
                                           (m_nggControl.enableBoxFilterCulling == false) &&
                                           (m_nggControl.enableSphereCulling == false) &&
                                           (m_nggControl.enableSmallPrimFilter == false) &&
                                           (m_nggControl.enableCullDistanceCulling == false);
        }

        // NOTE: Further check if we have to turn on pass-through mode forcibly.
        if (m_nggControl.passthroughMode == false)
        {
            // NOTE: Further check if pass-through mode should be enabled
            const auto topology = m_pPipelineInfo->iaState.topology;
            if ((topology == VK_PRIMITIVE_TOPOLOGY_POINT_LIST) ||
                (topology == VK_PRIMITIVE_TOPOLOGY_LINE_LIST)  ||
                (topology == VK_PRIMITIVE_TOPOLOGY_LINE_STRIP) ||
                (topology == VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY) ||
                (topology == VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY))
            {
                // NGG runs in pass-through mode for non-triangle primitives
                m_nggControl.passthroughMode = true;
            }
            else if (topology == VK_PRIMITIVE_TOPOLOGY_PATCH_LIST)
            {
                // NGG runs in pass-through mode for non-triangle tessellation output
                LLPC_ASSERT(hasTs);

                const auto& builtInUsage = GetShaderResourceUsage(ShaderStageTessEval)->builtInUsage.tes;
                if (builtInUsage.pointMode || (builtInUsage.primitiveMode == Isolines))
                {
                    m_nggControl.passthroughMode = true;
                }
            }

            const auto polygonMode = m_pPipelineInfo->rsState.polygonMode;
            if ((polygonMode == VK_POLYGON_MODE_LINE) || (polygonMode == VK_POLYGON_MODE_POINT))
            {
                // NGG runs in pass-through mode for non-fill polygon mode
                m_nggControl.passthroughMode = true;
            }
        }

        // Build NGG culling-control registers
        BuildNggCullingControlRegister();

        LLPC_OUTS("===============================================================================\n");
        LLPC_OUTS("// LLPC NGG control settings results\n\n");

        // Control option
        LLPC_OUTS("EnableNgg                    = " << m_nggControl.enableNgg << "\n");
        LLPC_OUTS("EnableGsUse                  = " << m_nggControl.enableGsUse << "\n");
        LLPC_OUTS("AlwaysUsePrimShaderTable     = " << m_nggControl.alwaysUsePrimShaderTable << "\n");
        LLPC_OUTS("PassthroughMode              = " << m_nggControl.passthroughMode << "\n");
        LLPC_OUTS("CompactMode                  = ");
        switch (m_nggControl.compactMode)
        {
        case NggCompactSubgroup:
            LLPC_OUTS("Subgroup\n");
            break;
        case NggCompactVertices:
            LLPC_OUTS("Vertices\n");
            break;
        default:
            break;
        }
        LLPC_OUTS("EnableFastLaunch             = " << m_nggControl.enableFastLaunch << "\n");
        LLPC_OUTS("EnableVertexReuse            = " << m_nggControl.enableVertexReuse << "\n");
        LLPC_OUTS("EnableBackfaceCulling        = " << m_nggControl.enableBackfaceCulling << "\n");
        LLPC_OUTS("EnableFrustumCulling         = " << m_nggControl.enableFrustumCulling << "\n");
        LLPC_OUTS("EnableBoxFilterCulling       = " << m_nggControl.enableBoxFilterCulling << "\n");
        LLPC_OUTS("EnableSphereCulling          = " << m_nggControl.enableSphereCulling << "\n");
        LLPC_OUTS("EnableSmallPrimFilter        = " << m_nggControl.enableSmallPrimFilter << "\n");
        LLPC_OUTS("EnableCullDistanceCulling    = " << m_nggControl.enableCullDistanceCulling << "\n");
        LLPC_OUTS("BackfaceExponent             = " << m_nggControl.backfaceExponent << "\n");
        LLPC_OUTS("SubgroupSizing               = ");
        switch (m_nggControl.subgroupSizing)
        {
#if LLPC_CLIENT_INTERFACE_MAJOR_VERSION >= 26
        case NggSubgroupSizingType::Auto:
            LLPC_OUTS("Auto\n");
            break;
#endif
        case NggSubgroupSizingType::MaximumSize:
            LLPC_OUTS("MaximumSize\n");
            break;
        case NggSubgroupSizingType::HalfSize:
            LLPC_OUTS("HalfSize\n");
            break;
        case NggSubgroupSizingType::OptimizeForVerts:
            LLPC_OUTS("OptimizeForVerts\n");
            break;
        case NggSubgroupSizingType::OptimizeForPrims:
            LLPC_OUTS("OptimizeForPrims\n");
            break;
        case NggSubgroupSizingType::Explicit:
            LLPC_OUTS("Explicit\n");
            break;
        default:
            LLPC_NEVER_CALLED();
            break;
        }
        LLPC_OUTS("PrimsPerSubgroup             = " << m_nggControl.primsPerSubgroup << "\n");
        LLPC_OUTS("VertsPerSubgroup             = " << m_nggControl.vertsPerSubgroup << "\n");
        LLPC_OUTS("\n");
    }
}