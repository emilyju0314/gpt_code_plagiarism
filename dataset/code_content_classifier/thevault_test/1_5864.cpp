String GetResourcePath(String path)
{
    assert(path.size() > 0);
    
    if(path.front() != L'/' && path.front() != L'\\') {
        path = L'/' + path;
    }
    
#if defined(_MSC_VER)
	auto exe_path = wxFileName::DirName(wxStandardPaths::Get().GetExecutablePath());
	exe_path.RemoveLastDir();
	return exe_path.GetFullPath().ToStdWstring() + L"\\Resource" + path;
#else
    return wxStandardPaths::Get().GetResourcesDir() + path;
#endif
}