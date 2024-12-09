void PluginProcessor::setParameter(int parameterIndex, float newValue)
{
    AudioProcessor::setParameter(parameterIndex, newValue);

    parameters.UpdateWorkingValuesFromPluginParameters();
    oscillator.setWaveform(parameters.waveform);

    PluginEditor* pEditor = (PluginEditor*)getActiveEditor();
    if (pEditor) pEditor->update();
}