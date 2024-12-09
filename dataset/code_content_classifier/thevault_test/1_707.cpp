void NyxCmdOutput::finalizeOutput(ostringstream &output)
{
	if (printOutputEnabled)
	{
		cout << output.str();
	}
}