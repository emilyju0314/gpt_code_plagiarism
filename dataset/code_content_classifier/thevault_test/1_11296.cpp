std::shared_ptr<unity_sarray> image_sarray_to_vector_sarray(
    std::shared_ptr<unity_sarray> image_sarray, 
    bool undefined_on_failure) {
  // decoded_image_sarray
  log_func_entry();

  // transform the array with type casting
  auto fn = [=](const flexible_type& f)->flexible_type {
              flexible_type ret(flex_type_enum::VECTOR);
              flex_image tmp_img = f;
              image_util_detail::decode_image_impl(tmp_img); 
              try {
                ret = tmp_img;
              } catch (...) {
                if (undefined_on_failure) {
                  ret = FLEX_UNDEFINED;
                } else {
                  throw;
                }
              }
              return ret;
            };
  auto ret = image_sarray->transform_lambda(fn, flex_type_enum::VECTOR, true, 0);
  return std::static_pointer_cast<unity_sarray>(ret);
}