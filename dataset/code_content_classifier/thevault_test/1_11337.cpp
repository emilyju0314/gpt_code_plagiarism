void __print_back_trace() {
//TODO: Implement this functionality in Windows.
// Available through either StackWalk64 or CaptureStackBackTrace
#ifndef _WIN32
    void    *array[1024];
    size_t  size, i;
    char    **strings;

    try {
      std::lock_guard<graphlab::mutex> guard(back_trace_file_lock);

      if (write_error) {
        return;
      }
      char filename[1024];
      sprintf(filename, "backtrace.%d", backtrace_file_number);

      FILE* ofile = NULL;
      if (write_count == 0) {
        ofile = fopen(filename, "w");
      }
      else {
        ofile = fopen(filename, "a");
      }
      // if unable to open the file for output
      if (ofile == NULL) {
        // print an error, set the error flag so we don't ever print it again
        fprintf(stderr, "Unable to open output backtrace file.\n");
        write_error = 1;
        return;
      }
      ++write_count;

      size = backtrace(array, 1024);
      strings = backtrace_symbols(array, size);

      fprintf(ofile, "Pointers\n");
      fprintf(ofile, "------------\n");
      for (i = 0; i < size; ++i) {
          fprintf(ofile, "%p\n", array[i]);
      }


      fprintf(ofile, "Raw\n");
      fprintf(ofile, "------------\n");
      for (i = 0; i < size; ++i) {
          fprintf(ofile, "%s\n", strings[i]);
      }
      fprintf(ofile, "\nDemangled\n");
      fprintf(ofile, "------------\n");

      for (i = 0; i < size; ++i) {
          std::string ret = demangle(strings[i]);
          fprintf(ofile, "%s\n", ret.c_str());
      }
      free(strings);

      fprintf(ofile, "-------------------------------------------------------\n");
      fprintf(ofile, "\n\n");

      fclose(ofile);
    } catch (...) {
      std::cerr << "Unable to print back trace on termination" << std::endl;
    }
#endif
}