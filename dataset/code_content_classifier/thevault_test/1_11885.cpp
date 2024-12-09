void RemoveConnectionsForParameters(EMotionFX::AnimGraph* animGraph, const AZStd::vector<AZStd::string>& parameterNames, MCore::CommandGroup& commandGroup)
    {
        const size_t numValueParameters = animGraph->GetNumValueParameters();
        for (size_t i = 0; i < numValueParameters; ++i)
        {
            const size_t valueParameterIndex = numValueParameters - i - 1;
            const EMotionFX::ValueParameter* valueParameter = animGraph->FindValueParameter(valueParameterIndex);
            AZ_Assert(valueParameter, "Value parameter with index %d not found.", valueParameterIndex);

            if (AZStd::find(parameterNames.begin(), parameterNames.end(), valueParameter->GetName().c_str()) != parameterNames.end())
            {
                RemoveConnectionsForParameter(animGraph, valueParameter->GetName().c_str(), commandGroup);
            }
        }
    }