I3CLSimPhotonHistorySeriesPtr ConvertPhotonHistories(const std::vector<cl_float4> &rawData,
                                                         const I3CLSimPhotonSeries &photons,
                                                         std::size_t photonHistoryEntries)
    {
        if (rawData.size() % photonHistoryEntries != 0)
            log_fatal("Internal logic error: rawData.size() (==%zu) is not a multiple of photonHistoryEntries (==%zu)",
                     rawData.size(), photonHistoryEntries);
        
        if (rawData.size()/photonHistoryEntries != photons.size())
            log_fatal("internal logic error: rawData.size()/photonHistoryEntries [==%zu/%zu] != photons.size() [==%zu]",
                      rawData.size(),photonHistoryEntries,photons.size());
        
        I3CLSimPhotonHistorySeriesPtr output(new I3CLSimPhotonHistorySeries());
        
        for (std::size_t i=0;i<rawData.size()/photonHistoryEntries;++i)
        {
            // insert a new history for the current photon
            output->push_back(I3CLSimPhotonHistory());
            I3CLSimPhotonHistory &current_history = output->back();
            
            const I3CLSimPhoton &current_photon = photons[i];
            
            const uint32_t numScatters = current_photon.GetNumScatters();
            if (numScatters==0) continue; // nothing to record for this photon
            if (photonHistoryEntries==0) continue; // no entries => nothing to record
            
            const uint32_t numRecordedScatters = static_cast<uint32_t>(std::min(static_cast<std::size_t>(numScatters), photonHistoryEntries));
            // start with the most recent index
            uint32_t currentScatterIndex;
            
            if (numScatters<=photonHistoryEntries) {
                currentScatterIndex=0; // start with index 0
            } else {
                currentScatterIndex=numScatters%photonHistoryEntries;
            }
            
            for (uint32_t j=0;j<numRecordedScatters;++j)
            {
                // [0], [1] and [2] are x,y,z
                // [3] is the distance the photon traveled in units of absorption lengths
                const cl_float4 &rawDataEntry = rawData[i*photonHistoryEntries + currentScatterIndex];
                current_history.push_back(((const cl_float *)&rawDataEntry)[0], ((const cl_float *)&rawDataEntry)[1], ((const cl_float *)&rawDataEntry)[2], ((const cl_float *)&rawDataEntry)[3]);

                ++currentScatterIndex;
                if (currentScatterIndex>=static_cast<uint32_t>(photonHistoryEntries)) currentScatterIndex=0;
            }
        }

        return output;
    }