bool cImageCapturingModuleId3d11Impl::InitimageCapturingModule(CRect &monitorRect, int monitorNum)
{
	bool result = false;

	try
	{
		if (_pPreviousFrameImage)
		{
			_pPreviousFrameImage->Release();
			_pPreviousFrameImage = NULL;
		}

		if (_pCurrentFrameImage)
		{
			_pCurrentFrameImage->Release();
			_pCurrentFrameImage = NULL;
		}

		m_CurrentFrameTexture = NULL;

		m_DuplicationManager.Reset();

		UINT monitor = (monitorNum - 1);

		//auto it = std::find_if( vAdapters_map.begin(), vAdapters_map.end(), [monitor](const std::pair< std::pair<IDXGIAdapter*, IDXGIOutput*> , UINT>& element){ return element.second == monitor;} ); //lambda iterator

		if (vAdapters_map.size() == 0 || vAdapters_map.size() < monitorNum)
		{
			GetAllAvailableMonitors();
		}

		std::pair<std::pair<std::pair<IDXGIAdapter*, IDXGIOutput*>, MONITOR*>, UINT> monitor_map = vAdapters_map.at(monitor);
		monitorRect = monitor_map.first.second->scrRect;

		IDXGIAdapter* _pAdapter = monitor_map.first.first.first;
		IDXGIOutput *_pOutput = monitor_map.first.first.second;

		m_LastErrorCode = initDevice(_pAdapter);

		if (SUCCEEDED(m_LastErrorCode))
		{
			m_LastErrorCode = initDuplicationManager(_pAdapter, _pOutput, monitor_map.second);

			if (SUCCEEDED(m_LastErrorCode))
			{
				result = true;
			}
			else
			{
				ReleaseAdapters();
			}
		}
		else
		{
			ReleaseAdapters();
		}
	}
	catch (std::out_of_range &e)
	{
		
	}
	catch (...)
	{

	}

	return result;
}