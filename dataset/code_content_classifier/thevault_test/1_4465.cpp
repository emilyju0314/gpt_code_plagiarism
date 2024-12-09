static bool try_recursive_mkdir(TCHAR* path) {
  TCHAR* p = strrchr(path, *DIR_SEP);
  if(!p || p == path) return false;
  *p = 0;
  bool ret = false;
#ifdef __WIN32__
	if(CreateDirectory(path, NULL)) ret = true;
	else if(GetLastError() == ERROR_PATH_NOT_FOUND && try_recursive_mkdir(path)
			&& CreateDirectory(path, NULL)) ret = true;
/* # error Implement for Windows */
#else
  if(mkdir(path, 0755) == 0) ret = true;
  else if(errno == ENOENT && try_recursive_mkdir(path)
          && mkdir(path, 0755) == 0) ret = true;
#endif
  *p = *DIR_SEP;
  return ret;
}