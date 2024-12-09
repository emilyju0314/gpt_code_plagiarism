deferred_float_array wrap_float_array(shared_float_array params) {
  std::vector<size_t> shape(params.shape(), params.shape() + params.dim());

  std::promise<shared_float_array> promise;
  promise.set_value(std::move(params));
  return deferred_float_array(promise.get_future(), std::move(shape));
}