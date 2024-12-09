ScriptCanvasDeveloperModule::ScriptCanvasDeveloperModule()
        : AZ::Module()
    {
        m_descriptors.insert(m_descriptors.end(), {
            ScriptCanvasDeveloper::SystemComponent::CreateDescriptor(),
            ScriptCanvasDeveloperEditor::SystemComponent::CreateDescriptor()
        });

        AZStd::vector<AZ::ComponentDescriptor*> componentDescriptors(ScriptCanvasDeveloper::Libraries::Developer::GetComponentDescriptors());
        m_descriptors.insert(m_descriptors.end(), componentDescriptors.begin(), componentDescriptors.end());
    }