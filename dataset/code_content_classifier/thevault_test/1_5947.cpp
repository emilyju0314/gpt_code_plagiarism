static
      void
      warn_hard(const std::string& msg)
      {
        runner::Job& r = ::kernel::runner();
        eval::send_message(r, "warning", libport::format("!!! %s", msg));
        eval::show_backtrace(r, "warning");
      }