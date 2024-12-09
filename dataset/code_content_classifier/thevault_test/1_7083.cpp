int fl_filename_list(const char *d, dirent ***list,
                     Fl_File_Sort_F *sort) {
#ifndef HAVE_SCANDIR
  int n = scandir(d, list, 0, sort);
#elif defined(HAVE_SCANDIR_POSIX) && !defined(__APPLE__)
  // POSIX (2008) defines the comparison function like this:
  int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
#elif defined(__osf__)
  // OSF, DU 4.0x
  int n = scandir(d, list, 0, (int(*)(dirent **, dirent **))sort);
#elif defined(_AIX)
  // AIX is almost standard...
  int n = scandir(d, list, 0, (int(*)(void*, void*))sort);
#elif !defined(__sgi)
  // The vast majority of UNIX systems want the sort function to have this
  // prototype, most likely so that it can be passed to qsort without any
  // changes:
  int n = scandir(d, list, 0, (int(*)(const void*,const void*))sort);
#else
  // This version is when we define our own scandir (WIN32 and perhaps
  // some Unix systems) and apparently on IRIX:
  int n = scandir(d, list, 0, sort);
#endif

#if defined(WIN32) && !defined(__CYGWIN__)
  // we did this already during fl_scandir/win32
#else
  // append a '/' to all filenames that are directories
  int i, dirlen = strlen(d);
  char *fullname = (char*)malloc(dirlen+FL_PATH_MAX+3); // Add enough extra for two /'s and a nul
  // Use memcpy for speed since we already know the length of the string...
  memcpy(fullname, d, dirlen+1);
  char *name = fullname + dirlen;
  if (name!=fullname && name[-1]!='/') *name++ = '/';
  for (i=0; i<n; i++) {
    dirent *de = (*list)[i];
    int len = strlen(de->d_name);
    if (de->d_name[len-1]=='/' || len>FL_PATH_MAX) continue;
    // Use memcpy for speed since we already know the length of the string...
    memcpy(name, de->d_name, len+1);
    if (fl_filename_isdir(fullname)) {
      (*list)[i] = de = (dirent*)realloc(de, de->d_name - (char*)de + len + 2);
      char *dst = de->d_name + len;
      *dst++ = '/';
      *dst = 0;
    }
  }
  free(fullname);
#endif
  return n;
}