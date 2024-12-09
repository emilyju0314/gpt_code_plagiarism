void Fl::display(const char *d) {
#if defined(__APPLE__) || defined(WIN32)
  (void)d;
#else
  static char e[1024];
  strcpy(e,"DISPLAY=");
  strlcat(e,d,sizeof(e));
  for (char *c = e+8; *c!=':'; c++) {
    if (!*c) {
      strlcat(e,":0.0",sizeof(e));
      break;
    }
  }
  putenv(e);
#endif // __APPLE__
}