void DigitalInAnalogIn::Initialize(ClearCorePins clearCorePin) {
    // Set the filter time
    AdcMgr.FilterTc(m_adcChannel,
                    ANALOG_INPUT_FILTER_TC_MS_DEFAULT,
                    AdcManager::FILTER_UNIT_MS);

    // Retrieve the pointers to AdcMgr results.
    m_adcResultConvertedPtr = &AdcMgr.ConvertedResult(m_adcChannel);
    m_adcResultConvertedFilteredPtr = &AdcMgr.FilteredResult(m_adcChannel);

    DigitalIn::Initialize(clearCorePin);
    // Mode is now set to INPUT_DIGITAL, reset state is INPUT_ANALOG, switch now
    Mode(INPUT_ANALOG);
}