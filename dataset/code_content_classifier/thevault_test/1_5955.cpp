SPOptions(int argc, const char* const argv[]) : argc_(argc), argv_(argv) {
      hss_opts_.set_verbose(false);
      blr_opts_.set_verbose(false);
      hodlr_opts_.set_verbose(false);
    }