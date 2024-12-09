int RunMain(int argc, char* argv[]) {
  for (int i = 1; i < argc; i++) {
    const char* str = argv[i];
    if (strcmp(str, "--shell") == 0) {
      run_shell = true;
    } else if (strcmp(str, "-f") == 0) {
      // Ignore any -f flags for compatibility with the other stand-
      // alone JavaScript engines.
      continue;
    } else if (strncmp(str, "--", 2) == 0) {
      fprintf(stderr, "Warning: unknown flag %s.\nTry --help for options\n", str);
    } else if (strcmp(str, "-e") == 0 && i + 1 < argc) {
      // Execute argument given to -e option directly.
      v8::Handle<v8::String> file_name = v8::String::New("unnamed");
      v8::Handle<v8::String> source = v8::String::New(argv[++i]);
      if (!ExecuteString(source, file_name, false, true)) return 1;
    } else {
      // Use all other arguments as names of files to load and run.
      v8::Handle<v8::String> file_name = v8::String::New(str);
      v8::Handle<v8::String> source = v8::Handle<v8::String>::Cast(
          ReadFile(str));
      if (source.IsEmpty() || !source->IsString()) {
        fprintf(stderr, "Error reading '%s'\n", str);
        continue;
      }
      if (!ExecuteString(source, file_name, false, true)) return 1;
    }
  }
  return 0;
}