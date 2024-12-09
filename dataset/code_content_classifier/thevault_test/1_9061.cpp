std::wstring QueryExternalSourceFontPath(const std::wstring& name) {
	if (query_cache == nullptr) {
		std::lock_guard<std::mutex> lg(cache_mutex);
		query_cache = new std::unordered_set<std::wstring>;
	}

	// skip query if it exists
	{
		std::lock_guard<std::mutex> lg(cache_mutex);
		if (query_cache->find(name) != query_cache->end())return std::wstring();
	}

	if (name.empty())return std::wstring();

	static bool b_failure = false;
	if (b_failure)return std::wstring();

	HANDLE h_mutex = NULL;
	HANDLE h_mapping = NULL;
	HANDLE h_event = NULL;
	DWORD mutex_result = 0;
	DWORD event_result = 0;
	void* memptr = nullptr;
	FontPathRequest* req = nullptr;
	std::wstring ret{};

	h_mutex = OpenMutexW(MUTEX_ALL_ACCESS, FALSE, L"FontPathQueryMutex");
	if (h_mutex == NULL)goto ONERROR;
	h_event = OpenEventW(EVENT_ALL_ACCESS, FALSE, L"FontPathQueryEvent");
	if (h_event == NULL)goto ONERROR;
	h_mapping = OpenFileMappingW(FILE_MAP_ALL_ACCESS, FALSE, L"FontPathQueryBuffer");
	if (h_mapping == NULL)goto ONERROR;

	memptr = MapViewOfFile(h_mapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (memptr == nullptr)goto ONERROR;

	mutex_result = WaitForSingleObject(h_mutex, TIMEOUT_MSEC);
	if (mutex_result != WAIT_OBJECT_0)goto ONERROR;

	// Aquired access to query

	req = reinterpret_cast<FontPathRequest*>(memptr);
	req->length = name.size();
	req->done = 0;
	for (size_t i = 0; i < name.size(); ++i) {
		req->data[i] = name[i];
	}

	// Do query
	SetEvent(h_event);
	event_result = WaitForSingleObject(h_event, TIMEOUT_MSEC);
	if (event_result != WAIT_OBJECT_0)goto ONERROR;

	if (req->done & SUCCESS_BIT) {
		std::lock_guard<std::mutex> lg(cache_mutex);
		query_cache->insert(name);
	}
	ret.clear();
	for (size_t i = 0; i < req->length; ++i) {
		ret.push_back(req->data[i]);
	}

	goto CLEANUP;
ONERROR:
	// b_failure = true;
	// MessageBoxW(NULL, L"Unable to make remote font path query.", L"QueryExternalSourceFontPath", MB_OK | MB_ICONERROR);
CLEANUP:
	if (h_mutex) {
		ReleaseMutex(h_mutex);
		CloseHandle(h_mutex);
	}
	if (memptr)UnmapViewOfFile(memptr);
	if (h_mapping)CloseHandle(h_mapping);
	if (h_event)CloseHandle(h_event);
	return ret;
}