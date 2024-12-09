size_t MeshDeformerStack::RemoveAllDeformersByType(uint32 deformerTypeID)
    {
        size_t numRemoved = 0;
        for (size_t a = 0; a < m_deformers.size(); )
        {
            MeshDeformer* deformer = m_deformers[a];
            if (deformer->GetType() == deformerTypeID)
            {
                RemoveDeformer(deformer);
                deformer->Destroy();
                numRemoved++;
            }
            else
            {
                a++;
            }
        }

        return numRemoved;
    }