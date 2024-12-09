void RenderViewWidget::OnOptions()
    {
        if (m_renderOptionsWindow == nullptr)
        {
            m_renderOptionsWindow = new PreferencesWindow(this);
            m_renderOptionsWindow->Init();

            AzToolsFramework::ReflectedPropertyEditor* generalPropertyWidget = m_renderOptionsWindow->FindPropertyWidgetByName("General");
            if (!generalPropertyWidget)
            {
                generalPropertyWidget = m_renderOptionsWindow->AddCategory("General");
                generalPropertyWidget->ClearInstances();
                generalPropertyWidget->InvalidateAll();
            }

            AZ::SerializeContext* serializeContext = nullptr;
            AZ::ComponentApplicationBus::BroadcastResult(serializeContext, &AZ::ComponentApplicationBus::Events::GetSerializeContext);
            if (!serializeContext)
            {
                AZ_Error("EMotionFX", false, "Can't get serialize context from component application.");
                return;
            }

            PluginOptions* pluginOptions = m_plugin->GetOptions();
            AZ_Assert(pluginOptions, "Expected options in render plugin");
            generalPropertyWidget->AddInstance(pluginOptions, azrtti_typeid(pluginOptions));

            // Now add EMStudio settings
            generalPropertyWidget->SetAutoResizeLabels(true);
            generalPropertyWidget->Setup(serializeContext, nullptr, true);
            generalPropertyWidget->show();
            generalPropertyWidget->ExpandAll();
            generalPropertyWidget->InvalidateAll();
        }

        m_renderOptionsWindow->show();
    }