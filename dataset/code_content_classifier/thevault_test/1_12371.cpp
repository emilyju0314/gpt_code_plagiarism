bool EditorMaterialComponentSlot::ConvertVersion(AZ::SerializeContext& context, AZ::SerializeContext::DataElementNode& classElement)
        {
            if (classElement.GetVersion() < 2)
            {
                constexpr AZ::u32 materialIdDataCrc = AZ_CRC("id", 0xbf396750);

                AZStd::pair<MaterialAssignmentLodIndex, AZ::Data::AssetId> oldId;
                if (!classElement.GetChildData(materialIdDataCrc, oldId))
                {
                    AZ_Error("AZ::Render::EditorMaterialComponentSlot::ConvertVersion", false, "Failed to get id element");
                    return false;
                }

                if (!classElement.RemoveElementByName(materialIdDataCrc))
                {
                    AZ_Error("AZ::Render::EditorMaterialComponentSlot::ConvertVersion", false, "Failed to remove id element");
                    return false;
                }

                const MaterialAssignmentId newId(oldId.first, oldId.second.m_subId);
                classElement.AddElementWithData(context, "id", newId);
            }

            if (classElement.GetVersion() < 4)
            {
                constexpr AZ::u32 matModUvOverridesCrc = AZ_CRC_CE("matModUvOverrides");
                AZStd::unordered_map<uint32_t, AZ::Name> oldMatModUvOverrides;
                if (classElement.GetChildData(matModUvOverridesCrc, oldMatModUvOverrides))
                {
                    // This feature is very new, so we assume that any existing matModUvOverrides data is empty.
                    AZ_Error("AZ::Render::EditorMaterialComponentSlot::ConvertVersion", oldMatModUvOverrides.empty(), "Conversion from old matModUvOverrides is not supported. The new overrides map will be empty.");

                    // We just consume the old element to avoid reporting errors about an unknown class ID when serialization continues.
                    classElement.RemoveElementByName(matModUvOverridesCrc);
                }
            }

            if (classElement.GetVersion() < 5)
            {
                classElement.RemoveElementByName(AZ_CRC_CE("matModUvOverrides"));
                classElement.RemoveElementByName(AZ_CRC_CE("propertyOverrides"));
            }

            return true;
        }