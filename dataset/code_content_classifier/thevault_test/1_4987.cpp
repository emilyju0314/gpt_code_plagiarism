static int return_child(int argc, char **argv) {
  if (strcmp(argv[3], getenv("FOO")) != 0) {
    return 55;
  }
  return atoi(argv[2]);
}