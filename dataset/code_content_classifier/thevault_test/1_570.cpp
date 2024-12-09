explicit strand_service(boost::asio::io_service& io_service)
    : boost::asio::detail::service_base<strand_service>(io_service),
      mutex_(),
      impl_list_(0)
  {
  }