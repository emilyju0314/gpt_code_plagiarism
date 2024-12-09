uint32_t Compiler::ChooseLoopUnrollCountCandidate(
    PipelineStatistics* pPipelineStats,             // [in] Pipeline module info
    uint32_t            candidateCount              // [in] Candidate  Count
    ) const
{
    uint32_t candidateIdx        = 0;
    uint32_t optimalCandidateIdx = 0;
    uint32_t noSpillCandidateIdx = 0;
    uint32_t maxWaveCandidateIdx = 0;

    // Find the optimal candidate with no SGPR spill or scratch buffer.
    for (; candidateIdx < candidateCount; candidateIdx++)
    {
        if ((pPipelineStats[candidateIdx].sgprSpill == false) &&
            (pPipelineStats[candidateIdx].useScratchBuffer == false))
        {
            break;
        }
    }
    noSpillCandidateIdx = candidateIdx;

    // Check available wavefronts
    // Only need to check VGPR usage. There are a lot more SGPRs(800).
    // It will only limit waves to 8, which is not a problem as the designed wave ratio is 0.2
    uint32_t maxWave = 0;
    uint32_t totalVgprs = pPipelineStats[0].numAvailVgprs;
    LLPC_ASSERT(totalVgprs > 0);

    for (candidateIdx = 0; candidateIdx < candidateCount; candidateIdx++)
    {
        uint32_t wave = totalVgprs / pPipelineStats[candidateIdx].numUsedVgprs;
        if (maxWave < wave)
        {
            maxWave = wave;
            maxWaveCandidateIdx = candidateIdx;
        }
    }

    float waveRatio = 0.0f;

    if (noSpillCandidateIdx < candidateCount)
    {
        if (noSpillCandidateIdx < maxWaveCandidateIdx)
        {
            // Choose the optimal candidate with max wave
            optimalCandidateIdx = maxWaveCandidateIdx;
            uint32_t wave = totalVgprs / pPipelineStats[optimalCandidateIdx - 1].numUsedVgprs;

            waveRatio = static_cast<float>(maxWave - wave);
            waveRatio = waveRatio / maxWave;

            // Choose larger loop unroll count if wave difference is relatively small.
            if (waveRatio < 0.2)
            {
                optimalCandidateIdx--;
                int32_t nextIndex = static_cast<int32_t>(optimalCandidateIdx) - 1;
                while (nextIndex > 0)
                {
                    if (wave != (totalVgprs / pPipelineStats[nextIndex].numUsedVgprs))
                    {
                        break;
                    }
                    optimalCandidateIdx--;
                    nextIndex = optimalCandidateIdx - 1;
                }
            }
        }
        else if (noSpillCandidateIdx == maxWaveCandidateIdx)
        {
            optimalCandidateIdx = maxWaveCandidateIdx;
        }
        else
        {
            // Large loop unroll count has more wavefronts.
            // This is not a common case.
            waveRatio = static_cast<float>(maxWave - totalVgprs / pPipelineStats[noSpillCandidateIdx].numUsedVgprs);
            waveRatio = waveRatio / maxWave;
            if (waveRatio < 0.2)
            {
                optimalCandidateIdx = noSpillCandidateIdx;
            }
            else
            {
                optimalCandidateIdx = maxWaveCandidateIdx;
            }
        }
    }
    else
    {
        optimalCandidateIdx = 0;
    }

    return optimalCandidateIdx;
}