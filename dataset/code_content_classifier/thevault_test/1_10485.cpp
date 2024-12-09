static const char *ScrollViewProg() {
#  ifdef _WIN32
  const char *prog = "java -Xms512m -Xmx1024m";
#  else
  const char *prog = "sh";
#  endif
  return prog;
}