bool TressFXAsset::GenerateFollowHairs(int numFollowHairsPerGuideHair, float tipSeparationFactor, float maxRadiusAroundGuideHair)
    {
        TRESSFX_ASSERT(numFollowHairsPerGuideHair >= 0);

        m_numFollowStrandsPerGuide = numFollowHairsPerGuideHair;

        // Nothing to do, just exit. 
        if (numFollowHairsPerGuideHair == 0)
            return false;

        // Recompute total number of hair strands and vertices with considering number of follow hairs per a guide hair. 
        m_numTotalStrands = m_numGuideStrands * (m_numFollowStrandsPerGuide + 1);
        m_numTotalVertices = m_numTotalStrands * m_numVerticesPerStrand;

        // keep the old buffers until the end of this function. 
        std::vector<Vector3> positionsGuide = m_positions;
        std::vector<AMD::float2> strandUVGuide = m_strandUV;

        // re-allocate all buffers
        m_positions.resize(m_numTotalVertices);
        m_strandUV.resize(m_numTotalStrands);

        m_followRootOffsets.resize(m_numTotalStrands);

        // type-cast to Vector3 to handle data easily. 
        Vector3* pos = m_positions.data();
        Vector3* followOffset = m_followRootOffsets.data();

        // Generate follow hairs
        for (int i = 0; i < m_numGuideStrands; i++)
        {
            int indexGuideStrand = i * (m_numFollowStrandsPerGuide + 1);
            int indexRootVertMaster = indexGuideStrand * m_numVerticesPerStrand;

            memcpy(&pos[indexRootVertMaster], &positionsGuide[i * m_numVerticesPerStrand], sizeof(Vector3) * m_numVerticesPerStrand);
            m_strandUV[indexGuideStrand] = strandUVGuide[i];

            followOffset[indexGuideStrand].Set(0, 0, 0);
            followOffset[indexGuideStrand].w = (float)indexGuideStrand;
            Vector3 v01 = pos[indexRootVertMaster + 1] - pos[indexRootVertMaster];
            v01.Normalize();

            // Find two orthogonal unit tangent vectors to v01
            Vector3 t0, t1;
            GetTangentVectors(v01, t0, t1);

            for (int j = 0; j < m_numFollowStrandsPerGuide; j++)
            {
                int indexStrandFollow = indexGuideStrand + j + 1;
                int indexRootVertFollow = indexStrandFollow * m_numVerticesPerStrand;

                m_strandUV[indexStrandFollow] = m_strandUV[indexGuideStrand];

                // offset vector from the guide strand's root vertex position
                Vector3 offset = GetRandom(-maxRadiusAroundGuideHair, maxRadiusAroundGuideHair) * t0 + GetRandom(-maxRadiusAroundGuideHair, maxRadiusAroundGuideHair) * t1;
                followOffset[indexStrandFollow] = offset;
                followOffset[indexStrandFollow].w = (float)indexGuideStrand;

                for (int k = 0; k < m_numVerticesPerStrand; k++)
                {
                    const Vector3* guideVert = &pos[indexRootVertMaster + k];
                    Vector3* followVert = &pos[indexRootVertFollow + k];

                    float factor = tipSeparationFactor * ((float)k / ((float)m_numVerticesPerStrand)) + 1.0f;
                    *followVert = *guideVert + offset * factor;
                    (*followVert).w = guideVert->w;
                }
            }
        }

        return true;
    }