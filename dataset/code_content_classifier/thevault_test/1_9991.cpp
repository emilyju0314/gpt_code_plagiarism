BOOL cImageCapturingModuleId3d11Impl::GetAllAvailableMonitors()
{

	try
	{
		ReleaseAdapters();

		std::vector <IDXGIAdapter1*> vAdapters = EnumerateAdapters();

		UINT adapterCount = 1;

		for (std::vector <IDXGIAdapter1*>::iterator i = vAdapters.begin(); i != vAdapters.end(); i++)
		{

			IDXGIAdapter1* _padapter = *i;

			std::vector <IDXGIOutput*> vOutputs = EnumMonitors(_padapter);

			UINT outputCount = 0;

			for (std::vector <IDXGIOutput*>::iterator j = vOutputs.begin(); j != vOutputs.end(); j++)
			{
				IDXGIOutput *out = *j;

				if (out)
				{
					DXGI_OUTPUT_DESC desktopDesc;
					out->GetDesc(&desktopDesc);

					MONITOR *s_mon = new MONITOR;
					s_mon->hMon = desktopDesc.Monitor;
					s_mon->hDC = NULL;
					s_mon->scrRect = new RECT();
					s_mon->pRect = new RECT();
					//Physical Monitor border
					s_mon->scrRect->left = s_mon->pRect->left = desktopDesc.DesktopCoordinates.left;
					s_mon->scrRect->top = s_mon->pRect->top = desktopDesc.DesktopCoordinates.top;
					s_mon->scrRect->right = s_mon->pRect->right = desktopDesc.DesktopCoordinates.right;
					s_mon->scrRect->bottom = s_mon->pRect->bottom = desktopDesc.DesktopCoordinates.bottom;
					s_mon->data = NULL;

					_padapter->AddRef();
					vAdapters_map.push_back(std::make_pair(std::make_pair(std::make_pair(_padapter, out), s_mon), outputCount));

					outputCount++;

					//out->Release();  // Do not release outputs, we would be using them to init the device corresponding to a particular monitor
					//out = NULL;
				}

				adapterCount++;
			}

			//(*i)->Release(); // Do not release adapters, we would be using them to init the device corresponding to a particular monitor
		}

		UINT num_of_monitors = vAdapters_map.size();

		return (num_of_monitors > 0);
	}
	catch (...)
	{
		
	}

	return FALSE;
}