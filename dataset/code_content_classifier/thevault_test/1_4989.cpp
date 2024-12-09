static int pipes_child(int argc, char **argv) {
  char buffer[200];
  for (;;) {
    int len = read(0, buffer, sizeof(buffer));
    if (len <= 0) {
      break;
    }
    write(1, buffer, len);
  }
  close(1);
  close(0);
  return 0;
}