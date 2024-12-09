std::shared_ptr<unity_sarray> resize_image_sarray(
    std::shared_ptr<unity_sarray> image_sarray, 
    size_t resized_width, 
    size_t resized_height, 
    size_t resized_channels,
    bool decode) {
  log_func_entry();
  auto fn = [=](const flexible_type& f)->flexible_type {
      return flexible_type(resize_image(f, resized_width, resized_height, resized_channels, decode));
    };
  auto ret = image_sarray->transform_lambda(fn, flex_type_enum::IMAGE, true, 0);
  return std::static_pointer_cast<unity_sarray>(ret);
}