std::shared_ptr<unity_sarray> decode_image_sarray(std::shared_ptr<unity_sarray> image_sarray) {
  auto fn = [](const flexible_type& f)->flexible_type {
              return decode_image(f);
            };
  auto ret = image_sarray->transform_lambda(fn, flex_type_enum::IMAGE, true, 0);
  return std::static_pointer_cast<unity_sarray>(ret);
}