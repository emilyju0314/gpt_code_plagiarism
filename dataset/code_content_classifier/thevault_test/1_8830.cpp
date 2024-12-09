void SWIG_merge_envopt(const char *env, int oargc, char *oargv[], int *nargc, char ***nargv) {
  if (!env) {
    *nargc = oargc;
    *nargv = oargv;
    return;
  }

  int argc = 1;
  int arge = oargc + 1024;
  char **argv = (char **) malloc(sizeof(char *) * (arge));
  char *buffer = (char *) malloc(2048);
  char *b = buffer;
  char *be = b + 1023;
  const char *c = env;
  while ((b != be) && *c && (argc < arge)) {
    while (isspace(*c) && *c)
      ++c;
    if (*c) {
      argv[argc] = b;
      ++argc;
    }
    while ((b != be) && *c && !isspace(*c)) {
      *(b++) = *(c++);
    }
    *b++ = 0;
  }

  argv[0] = oargv[0];
  for (int i = 1; (i < oargc) && (argc < arge); ++i, ++argc) {
    argv[argc] = oargv[i];
  }

  *nargc = argc;
  *nargv = argv;
}