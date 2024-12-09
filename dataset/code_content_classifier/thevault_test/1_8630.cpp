String LaunchpadLightsAudioProcessorEditor::FloatArrayToString(float* fData, int numFloat)
{
	String result = "";

	if (numFloat < 1)
	{
		return result;
	}

	for (int i = 0; i < (numFloat - 1); i++)
	{
		result << String(fData[i], 2) << ",";//Use juce::String initializer for each value
	}

	result << String(fData[numFloat - 1], 2);

	return result;
}