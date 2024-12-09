void DeferredFogPass::SetSrgBindIndices()
        {
            DeferredFogSettings* fogSettings = GetPassFogSettings();
            Data::Instance<RPI::ShaderResourceGroup> srg = m_shaderResourceGroup.get();
            
            // match and set all SRG constants' indices
#define AZ_GFX_COMMON_PARAM(ValueType, FunctionName, MemberName, DefaultValue)                          \
            fogSettings->MemberName##SrgIndex = srg->FindShaderInputConstantIndex(Name(#MemberName));   \

#include <Atom/Feature/ParamMacros/MapParamCommon.inl>
            // For texture use a different function call
#undef  AZ_GFX_TEXTURE2D_PARAM
#define AZ_GFX_TEXTURE2D_PARAM(FunctionName, MemberName, DefaultValue)                                  \
            fogSettings->MemberName##SrgIndex = srg->FindShaderInputImageIndex(Name(#MemberName));      \

#include <Atom/Feature/ScreenSpace/DeferredFogParams.inl>
#include <Atom/Feature/ParamMacros/EndParams.inl>

            fogSettings->SetInitialized(true);
        }