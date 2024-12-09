size_t MeshDeformerStack::EnableAllDeformersByType(uint32 deformerTypeID, bool enabled)
    {
        size_t numChanged = 0;
        for (MeshDeformer* deformer : m_deformers)
        {
             if (deformer->GetType() == deformerTypeID)
            {
                deformer->SetIsEnabled(enabled);
                numChanged++;
            }
        }

        return numChanged;
    }