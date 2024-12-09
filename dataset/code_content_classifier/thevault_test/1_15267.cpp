bool DeathTestImpl::Passed(bool status_ok) {
  if (!spawned())
    return false;

  const String error_message = GetCapturedStderr();

  bool success = false;
  Message buffer;

  buffer << "Death test: " << statement() << "\n";
  switch (outcome()) {
    case LIVED:
      buffer << "    Result: failed to die.\n"
             << " Error msg: " << error_message;
      break;
    case RETURNED:
      buffer << "    Result: illegal return in test statement.\n"
             << " Error msg: " << error_message;
      break;
    case DIED:
      if (status_ok) {
        const bool matched = RE::PartialMatch(error_message.c_str(), *regex());
        if (matched) {
          success = true;
        } else {
          buffer << "    Result: died but not with expected error.\n"
                 << "  Expected: " << regex()->pattern() << "\n"
                 << "Actual msg: " << error_message;
        }
      } else {
        buffer << "    Result: died but not with expected exit code:\n"
               << "            " << ExitSummary(status()) << "\n";
      }
      break;
    case IN_PROGRESS:
    default:
      GTEST_LOG_(FATAL)
          << "DeathTest::Passed somehow called before conclusion of test";
  }

  DeathTest::set_last_death_test_message(buffer.GetString());
  return success;
}