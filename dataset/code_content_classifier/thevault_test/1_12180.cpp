MeshDeformer* MeshDeformerStack::FindDeformerByType(uint32 deformerTypeID, size_t occurrence) const
    {
        const auto foundDeformer = AZStd::find_if(begin(m_deformers), end(m_deformers), [deformerTypeID, iter = occurrence](const MeshDeformer* deformer) mutable
        {
            return deformer->GetType() == deformerTypeID && iter-- == 0;
        });
        return foundDeformer != end(m_deformers) ? *foundDeformer : nullptr;
    }