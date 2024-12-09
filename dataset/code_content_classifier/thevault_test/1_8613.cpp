int SdkClass::EndPost()
{
	while(SdkClass::TheDataFieldsList.size() >= 0)
	{
		SendBlock();

		// clear the send buffer for next set
		try {
			// clear the buffer
			SdkClass::TheDataFieldsList.clear();
		}
		catch(...)
		{
			std::wcout << L"EXCEPTION on SdkClass::TheDataFieldsList.clear();";
			return -1;
		}

	}
	return 0;
}