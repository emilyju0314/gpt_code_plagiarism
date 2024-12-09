queue::queue(const async_handler &asyncHandler,
             const property_list &propList)
  : detail::property_carrying_object{propList},
    _device{device{}},
    _handler{asyncHandler}
{
  this->init();
}