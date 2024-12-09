void DeferredFogPass::SetSrgConstants()
        {
            DeferredFogSettings* fogSettings = GetPassFogSettings();
            Data::Instance<RPI::ShaderResourceGroup> srg = m_shaderResourceGroup.get();

            if (!fogSettings->IsInitialized())
            {   // Should be initialize before, but if not - this is a fail safe that will apply it once
                SetSrgBindIndices();
            }

            if (fogSettings->GetSettingsNeedUpdate())
            {   // SRG constants are up to date and will be bound as they are.
                // First time around they will be dirty to ensure properly set. 

                // Load all texture resources:
                //  first set all macros to be empty, but override the texture for setting images.
#include <Atom/Feature/ParamMacros/MapParamEmpty.inl>

#undef  AZ_GFX_TEXTURE2D_PARAM
#define AZ_GFX_TEXTURE2D_PARAM(Name, MemberName, DefaultValue)                  \
                fogSettings->MemberName##Image =                                \
                    fogSettings->LoadStreamingImage( fogSettings->MemberName.c_str(), "DeferredFogSettings" );  \

#include <Atom/Feature/ScreenSpace/DeferredFogParams.inl>
#include <Atom/Feature/ParamMacros/EndParams.inl>

                fogSettings->SetSettingsNeedUpdate(false);   // Avoid doing this unless data change is required
            }

            // The Srg constants value settings
#define AZ_GFX_COMMON_PARAM(ValueType, Name, MemberName, DefaultValue)                          \
            srg->SetConstant( fogSettings->MemberName##SrgIndex, fogSettings->MemberName );     \

#include <Atom/Feature/ParamMacros/MapParamCommon.inl>

            // The following macro overrides the regular macro defined above, loads an image and bind it
#undef AZ_GFX_TEXTURE2D_PARAM
#define AZ_GFX_TEXTURE2D_PARAM(Name, MemberName, DefaultValue)                      \
            if (!srg->SetImage(fogSettings->MemberName##SrgIndex, fogSettings->MemberName##Image ))           \
            {                                                                       \
                AZ_Error( "DeferredFogPass::SetSrgConstants", false, "Failed to bind SRG image for %s = %s",  \
                    #MemberName, fogSettings->MemberName.c_str() );                                      \
            }                                                                       \

#include <Atom/Feature/ScreenSpace/DeferredFogParams.inl>
#include <Atom/Feature/ParamMacros/EndParams.inl>
        }