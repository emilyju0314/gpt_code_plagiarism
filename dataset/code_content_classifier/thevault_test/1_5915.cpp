inline
  const char*
  UAbstractClient::default_host()
  {
    // When using Boost.Asio, "localhost" on OS X is IPv6, and nothing
    // works as expected.  Make sure we run in IPv4.
    // FIXME: Find out why we run in IPv6 by default.
    return "127.0.0.1";
  }