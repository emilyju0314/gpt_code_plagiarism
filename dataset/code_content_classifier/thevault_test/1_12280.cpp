inline void ImGuiFrameVisualizer::OnFrameCompileEnd(RHI::FrameGraph& frameGraph)
    {
        const AZ::RHI::FrameGraphAttachmentDatabase& attachmentDatabase = frameGraph.GetAttachmentDatabase();
        const AZStd::vector<AZ::RHI::FrameAttachment*>& attachments = attachmentDatabase.GetAttachments();
        m_framesAttachments.clear();
        m_framesAttachments.resize(attachments.size());
        for (size_t i = 0; i < attachments.size(); ++i)
        {
            AZ::RHI::FrameAttachment& attachment = *attachments[i];
            FrameAttachmentVisualizeInfo& attachmentVisualInfo = m_framesAttachments[i];
            attachmentVisualInfo.m_pFirstScopeVisual.clear();
            attachmentVisualInfo.m_pLastScopeVisual.clear();
            const AZ::RHI::ScopeAttachment* scopeAttachment = attachment.GetFirstScopeAttachment();
            while (scopeAttachment)
            {
                attachmentVisualInfo.m_pFirstScopeVisual.push_back({ scopeAttachment->GetScope().GetId() });
                scopeAttachment = scopeAttachment->GetNext();
            }
        }
    }