AZ::u32 MotionEventPresetManager::GetEventColor(const EMotionFX::EventDataSet& eventDatas) const
    {
        for (const MotionEventPreset* preset : m_eventPresets)
        {
            EMotionFX::EventDataSet commonDatas;
            const EMotionFX::EventDataSet& presetDatas = preset->GetEventDatas();
            const bool allMatch = AZStd::all_of(presetDatas.cbegin(), presetDatas.cend(), [eventDatas](const EMotionFX::EventDataPtr& presetData)
            {
                const auto thisPresetDataHasMatch = AZStd::find_if(eventDatas.cbegin(), eventDatas.cend(), [presetData](const EMotionFX::EventDataPtr& eventData)
                {
                    return ((presetData && eventData && *presetData == *eventData) || (!presetData && !eventData));
                });
                return thisPresetDataHasMatch != eventDatas.cend();
            });
            if (allMatch)
            {
                return preset->GetEventColor();
            }
        }

        // Use the same color for all events that are not from a preset.
        return s_unknownEventColor;
    }