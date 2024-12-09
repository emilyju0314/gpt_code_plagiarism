void usage(const char* cmd) {
  // Purely aesthetic, but create a buffer of space characters so multiline subtask
  // descriptions can be justified with the preceeding line.
  const size_t kCmdLen = strlen(cmd) + 1;
  const auto spaces_cleanup = std::make_unique<char[]>(kCmdLen);
  char* spaces = spaces_cleanup.get();
  memset(spaces, ' ', kCmdLen);  // Fill buffer with spaces.
  spaces[kCmdLen - 1] = '\0';    // Null terminate.

  fprintf(stderr, "\nInteract with the CPU\n");
  fprintf(stderr, "\t%s help               Print this message and quit.\n", cmd);
  fprintf(stderr, "\t%s list               List this system's performance domains\n", cmd);
  fprintf(stderr,
          "\t%s describe [domain]  Describes a given performance domain's performance states\n",
          cmd);
  fprintf(stderr, "\t%s                    describes all domains if `domain` is omitted.\n",
          spaces);
}