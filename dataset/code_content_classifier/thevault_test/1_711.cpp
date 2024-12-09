void NyxCmdOutputJson::finalizeOutput(ostringstream &output)
{
	if (printOutputEnabled)
	{
		//remove final ','
		string tempCpy = output.str();
		tempCpy.erase(tempCpy.rfind(","));
		cout << tempCpy;

		cout << endl << "}" << endl;
	}
}