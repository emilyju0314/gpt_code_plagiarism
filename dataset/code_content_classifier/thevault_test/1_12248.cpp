static AZ::Data::Asset<AZ::RPI::StreamingImageAsset> GetStreamingImageAsset(const AZ::RPI::MaterialAsset& materialAsset, const AZ::Name& propertyName)
            {
                if (!materialAsset.IsReady())
                {
                    AZ_Warning("DecalTextureArray", false, "GetStreamingImageAsset() called with material property: %s, was passed a MaterialAsset that was not ready for use", propertyName.GetCStr());
                    return {};
                }

                const AZ::RPI::MaterialPropertiesLayout* materialLayout = materialAsset.GetMaterialPropertiesLayout();
                const AZ::RPI::MaterialPropertyIndex propertyIndex = materialLayout->FindPropertyIndex(propertyName);
                if (propertyIndex.IsNull())
                {
                    AZ_Warning("DecalTextureArray", false, "Unable to find material property with the name: %s", propertyName.GetCStr());
                    return {};
                }

                const auto& propertyValues = materialAsset.GetPropertyValues();
                const AZ::RPI::MaterialPropertyValue& propertyValue = propertyValues[propertyIndex.GetIndex()];
                auto imageAsset = propertyValue.GetValue<Data::Asset<RPI::ImageAsset>>();
                imageAsset.QueueLoad();
                // [GFX TODO][ATOM-14271] - DecalTextureArrayFeatureProcessor should use async loading
                imageAsset.BlockUntilLoadComplete();

                const auto& assetId = imageAsset.GetId();
                if (!assetId.IsValid())
                {
                    AZ_Warning("DecalTextureArray", false, "Material property: %s does not have a valid asset Id", propertyName.GetCStr());
                    return {};
                }
                return Data::static_pointer_cast<AZ::RPI::StreamingImageAsset>(imageAsset);
            }