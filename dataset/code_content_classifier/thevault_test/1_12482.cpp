void BlendTreeParameterNode::Update(AnimGraphInstance* animGraphInstance, float timePassedInSeconds)
    {
        MCORE_UNUSED(timePassedInSeconds);

        if (m_parameterIndices.empty())
        {
            // output all anim graph instance parameter values into the output ports
            const uint32 numParameters = static_cast<uint32>(m_outputPorts.size());
            for (uint32 i = 0; i < numParameters; ++i)
            {
                GetOutputValue(animGraphInstance, i)->InitFrom(animGraphInstance->GetParameterValue(i));
            }
        }
        else
        {
            // output only the parameter values that have been selected in the parameter mask
            const size_t parameterCount = m_parameterIndices.size();
            for (size_t i = 0; i < parameterCount; ++i)
            {
                GetOutputValue(animGraphInstance, static_cast<AZ::u32>(i))->InitFrom(animGraphInstance->GetParameterValue(m_parameterIndices[i]));
            }
        }
    }