inline void init(int& argc, char**& argv) {
#ifdef HAS_MPI
      const int required(MPI_THREAD_SINGLE);
      int provided(-1);
      int error = MPI_Init_thread(&argc, &argv, required, &provided);
      assert(provided >= required);
      assert(error == MPI_SUCCESS);
#else
      logstream(LOG_EMPH) << "MPI Support was not compiled." << std::endl;
#endif
    }