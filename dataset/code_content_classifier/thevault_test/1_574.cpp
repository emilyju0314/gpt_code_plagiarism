basic_random_access_handle(boost::asio::io_service& io_service,
      const native_type& native_handle)
    : basic_handle<RandomAccessHandleService>(io_service, native_handle)
  {
  }