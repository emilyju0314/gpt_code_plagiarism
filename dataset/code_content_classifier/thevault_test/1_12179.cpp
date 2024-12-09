bool MeshDeformerStack::CheckIfHasDeformerOfType(uint32 deformerTypeID) const
    {
        return AZStd::any_of(begin(m_deformers), end(m_deformers), [deformerTypeID](const MeshDeformer* deformer)
        {
            return deformer->GetType() == deformerTypeID;
        });
    }