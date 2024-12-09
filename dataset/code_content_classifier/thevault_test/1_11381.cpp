I3CLSimStepSeriesConstPtr I3CLSimLightSourceToStepConverterFlasher::MakeSteps(bool &barrierWasReset)
{
    barrierWasReset=false;
    
    if (inputQueue_.empty()) return I3CLSimStepSeriesConstPtr(); // queue is empty
    
    LightSourceData_t &currentElement = inputQueue_.front();

    // barrier?
    if (currentElement.isBarrier) {
        inputQueue_.pop_front(); // remove the element
        barrierWasReset=true;
        return I3CLSimStepSeriesConstPtr(new I3CLSimStepSeries());
    }

    I3CLSimStepSeriesPtr outputSteps(new I3CLSimStepSeries());
    
    bool entryCanBeRemoved;
    
    uint64_t numSteps;                  // number of steps to generate
    uint64_t numAppendedDummySteps;     // number of dummy steps to append in order to achieve the correct steps vector size granularity
    uint32_t numPhotonsInLastStep;      // number of photons in the last step
    // (the number of photons in all other steps is photonsPerStep_)
    
    const uint64_t maxPhotonsPerResult = maxBunchSize_*static_cast<uint64_t>(photonsPerStep_);
    if (currentElement.numPhotonsWithBias >= maxPhotonsPerResult) {
        numSteps = maxBunchSize_;
        numPhotonsInLastStep = photonsPerStep_; // nothing special for the last step
        
        numAppendedDummySteps=0;
        
        currentElement.numPhotonsWithBias -= numSteps*static_cast<uint64_t>(photonsPerStep_);
        entryCanBeRemoved = (currentElement.numPhotonsWithBias == 0);
        
        outputSteps->reserve(maxBunchSize_);
    } else {
        if (currentElement.numPhotonsWithBias <= static_cast<uint64_t>(photonsPerStep_)) {
            // only a single step
            numSteps = 1;
            numPhotonsInLastStep=static_cast<uint32_t>(currentElement.numPhotonsWithBias);
        } else {
            numSteps = currentElement.numPhotonsWithBias / static_cast<uint64_t>(photonsPerStep_);
            numPhotonsInLastStep = static_cast<uint32_t>(currentElement.numPhotonsWithBias % static_cast<uint64_t>(photonsPerStep_));
            if (numPhotonsInLastStep>0) {
                // one step more with less photons
                ++numSteps;
            }
        }

        entryCanBeRemoved=true;
        currentElement.numPhotonsWithBias = 0;

        const uint64_t modulo = numSteps % bunchSizeGranularity_;
        numAppendedDummySteps=0;
        if (modulo>0) {
            // we need some dummy steps
            
            numAppendedDummySteps = bunchSizeGranularity_-modulo;
        }
        
        outputSteps->reserve(numSteps+numAppendedDummySteps);
    }
    
    // now make the steps
    for (uint64_t i=0;i<numSteps;++i)
    {
        const uint32_t numberOfPhotonsForThisStep = (i==numSteps-1)?numPhotonsInLastStep:photonsPerStep_;
        if (numberOfPhotonsForThisStep==0) {++numAppendedDummySteps; continue;}
        
        outputSteps->push_back(I3CLSimStep());
        I3CLSimStep &newStep = outputSteps->back();

        FillStep(newStep,
                 numberOfPhotonsForThisStep,
                 currentElement.flasherPulse,
                 currentElement.identifier
                );
    }

    // and the dummy steps
    for (uint64_t i=0;i<numAppendedDummySteps;++i)
    {
        outputSteps->push_back(I3CLSimStep());
        I3CLSimStep &newStep = outputSteps->back();

        newStep.SetPosX(0.); newStep.SetPosY(0.); newStep.SetPosZ(0.);
        newStep.SetTime(0.);
        newStep.SetDirTheta(0.); newStep.SetDirPhi(0.);
        newStep.SetLength(0.);
        newStep.SetBeta(1.);
        newStep.SetNumPhotons(0);
        newStep.SetWeight(0);
        newStep.SetSourceType(0);
        newStep.SetID(currentElement.identifier);
    }
    
    if (entryCanBeRemoved) inputQueue_.pop_front();
    
    return outputSteps;
}