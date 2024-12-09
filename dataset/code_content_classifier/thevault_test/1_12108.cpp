void EditorCommonSystemComponent::Reflect(AZ::ReflectContext* context)
        {
            if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
            {
                serialize->Class<EditorCommonSystemComponent, AZ::Component>()
                    ->Version(1)
                    ->Attribute(Edit::Attributes::SystemComponentTags, AZStd::vector<Crc32>({ AssetBuilderSDK::ComponentTags::AssetBuilder }))
                    ;

                if (AZ::EditContext* ec = serialize->GetEditContext())
                {
                    ec->Class<EditorCommonSystemComponent>("Common", "Configures editor- and tool-specific functionality for common render features.")
                        ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System", 0xc94d118b))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                        ;
                }

                AZ::Render::UseTextureFunctorSourceData::Reflect(context);
                AZ::Render::DrawListFunctorSourceData::Reflect(context);
                AZ::Render::Transform2DFunctorSourceData::Reflect(context);
                AZ::Render::ConvertEmissiveUnitFunctorSourceData::Reflect(context);
                AZ::Render::SubsurfaceTransmissionParameterFunctorSourceData::Reflect(context);

                AZ::Render::EditorLightingPreset::Reflect(context);
                AZ::Render::EditorModelPreset::Reflect(context);
            }
        }