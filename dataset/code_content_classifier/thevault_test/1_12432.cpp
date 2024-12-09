ExportedComponentResult ResolveExportedComponent(AZ::ExportedComponent component,
            const AZ::PlatformTagSet& platformTags,
            AZ::SerializeContext& serializeContext)
        {
            AZ::Component* inputComponent = component.m_component;

            if (!inputComponent)
            {
                return AZ::Success(AZ::ExportedComponent(component));
            }

            // Don't export the component if it has unmet platform tag requirements.
            ShouldExportResult shouldExportResult = ShouldExportComponent(inputComponent, platformTags, serializeContext);
            if (!shouldExportResult)
            {
                return AZ::Failure(shouldExportResult.TakeError());
            }

            if (!shouldExportResult.GetValue())
            {
                // If the platform tag requirements aren't met, return a null component that's been flagged as exported,
                // so that we know not to try and process it any further.
                return AZ::Success(AZ::ExportedComponent());
            }

            // Determine if the component has a custom export callback, and invoke it if so.
            const AZ::SerializeContext::ClassData* classData = serializeContext.FindClassData(inputComponent->RTTI_GetType());
            if (classData && classData->m_editData)
            {
                const AZ::Edit::ElementData* editorDataElement = classData->m_editData->FindElementData(AZ::Edit::ClassElements::EditorData);
                if (editorDataElement)
                {
                    AZ::Edit::Attribute* exportCallbackAttribute = editorDataElement->FindAttribute(AZ::Edit::Attributes::RuntimeExportCallback);
                    if (exportCallbackAttribute)
                    {
                        PropertyAttributeReader reader(inputComponent, exportCallbackAttribute);
                        AZ::ExportedComponent exportedComponent;

                        if (reader.Read<AZ::ExportedComponent>(exportedComponent, inputComponent, platformTags))
                        {
                            // If the callback handled the export and provided a different component instance, continue to resolve recursively.
                            if (exportedComponent.m_componentExportHandled && (exportedComponent.m_component != inputComponent))
                            {
                                return ResolveExportedComponent(exportedComponent, platformTags, serializeContext);
                            }
                            else
                            {
                                // It provided the *same* component back (or didn't handle the export at all), so we're done.
                                return AZ::Success(exportedComponent);
                            }
                        }
                        else
                        {
                            return AZ::Failure(AZStd::string("Bound 'CustomExportCallback' does not have the required return type/signature."));
                        }
                    }
                }
            }

            // If there's no custom export callback, just return what we were given.
            return AZ::Success(component);
        }