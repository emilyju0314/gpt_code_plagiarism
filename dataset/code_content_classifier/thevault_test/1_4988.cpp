static int exit_child(int argc, char **argv) {
  if (strcmp(argv[3], getenv("FOO")) != 0) {
    return 55;
  }
  _exit(atoi(argv[2]));
  // Shouldn't get here.
  return 55;
}