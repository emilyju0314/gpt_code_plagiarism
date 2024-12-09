bool WasLoadSuccess(JsonSerializationResult::Outcomes outcome)
    {
        return (outcome == JsonSerializationResult::Outcomes::Success
            || outcome == JsonSerializationResult::Outcomes::DefaultsUsed
            || outcome == JsonSerializationResult::Outcomes::PartialDefaults);
    }