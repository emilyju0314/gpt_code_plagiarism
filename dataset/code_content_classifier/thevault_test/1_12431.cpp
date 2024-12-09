ShouldExportResult ShouldExportComponent(AZ::Component* component, const AZ::PlatformTagSet& platformTags, AZ::SerializeContext& serializeContext)
        {
            const AZ::SerializeContext::ClassData* classData = serializeContext.FindClassData(component->RTTI_GetType());
            if (!classData || !classData->m_editData)
            {
                return AZ::Success(true);
            }

            const AZ::Edit::ElementData* editorDataElement = classData->m_editData->FindElementData(AZ::Edit::ClassElements::EditorData);
            if (!editorDataElement)
            {
                return AZ::Success(true);
            }

            AZ::Edit::Attribute* allTagsAttribute = editorDataElement->FindAttribute(AZ::Edit::Attributes::ExportIfAllPlatformTags);
            AZ::Edit::Attribute* anyTagsAttribute = editorDataElement->FindAttribute(AZ::Edit::Attributes::ExportIfAnyPlatformTags);

            AZStd::vector<AZ::Crc32> attributeTags;

            // If the component has declared the 'ExportIfAllPlatforms' attribute, skip export if any of the flags are not present.
            if (allTagsAttribute)
            {
                attributeTags.clear();
                PropertyAttributeReader reader(component, allTagsAttribute);
                if (!reader.Read<decltype(attributeTags)>(attributeTags))
                {
                    return AZ::Failure(AZStd::string("'ExportIfAllPlatforms' attribute is not bound to the correct return type. Expects AZStd::vector<AZ::Crc32>."));
                }

                for (AZ::Crc32 tag : attributeTags)
                {
                    if (platformTags.find(tag) == platformTags.end())
                    {
                        // Export platform tags does not contain all tags specified in 'ExportIfAllPlatforms' attribute.
                        return AZ::Success(false);
                    }
                }
            }

            // If the component has declared the 'ExportIfAnyPlatforms' attribute, skip export if none of the flags are present.
            if (anyTagsAttribute)
            {
                attributeTags.clear();
                PropertyAttributeReader reader(component, anyTagsAttribute);
                if (!reader.Read<decltype(attributeTags)>(attributeTags))
                {
                    return AZ::Failure(AZStd::string("'ExportIfAnyPlatforms' attribute is not bound to the correct return type. Expects AZStd::vector<AZ::Crc32>."));
                }

                bool anyFlagSet = false;
                for (AZ::Crc32 tag : attributeTags)
                {
                    if (platformTags.find(tag) != platformTags.end())
                    {
                        anyFlagSet = true;
                        break;
                    }
                }
                if (!anyFlagSet)
                {
                    // None of the flags in 'ExportIfAnyPlatforms' was present in the export platform tags.
                    return AZ::Success(false);
                }
            }

            return AZ::Success(true);
        }