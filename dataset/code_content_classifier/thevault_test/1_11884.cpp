void ClearParametersCommand(EMotionFX::AnimGraph* animGraph, MCore::CommandGroup* commandGroup)
    {
        const EMotionFX::ValueParameterVector parameters = animGraph->RecursivelyGetValueParameters();
        if (parameters.empty())
        {
            return;
        }

        // Iterate through all parameters and fill the parameter name array.
        AZStd::vector<AZStd::string> parameterNames;
        parameterNames.reserve(static_cast<size_t>(parameters.size()));
        for (const EMotionFX::ValueParameter* parameter : parameters)
        {
            parameterNames.push_back(parameter->GetName());
        }

        // Is the command group parameter set?
        if (!commandGroup)
        {
            // Create and fill the command group.
            AZStd::string outResult;
            MCore::CommandGroup internalCommandGroup("Clear parameters");
            BuildRemoveParametersCommandGroup(animGraph, parameterNames, &internalCommandGroup);

            // Execute the command group.
            if (!GetCommandManager()->ExecuteCommandGroup(internalCommandGroup, outResult))
            {
                AZ_Error("EMotionFX", false, outResult.c_str());
            }
        }
        else
        {
            // Use the given parameter command group.
            BuildRemoveParametersCommandGroup(animGraph, parameterNames, commandGroup);
        }
    }