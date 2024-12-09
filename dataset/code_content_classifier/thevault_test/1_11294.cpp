flexible_type resize_image(const flexible_type& image, size_t resized_width, size_t resized_height, size_t resized_channels, bool decode) {
  if (image.get_type() != flex_type_enum::IMAGE){
    std::string error = "Cannot resize non-image type";
    log_and_throw(error);
  }
  const flex_image& src_image = image.get<flex_image>();
  char* resized_data;
  if (src_image.is_decoded()) {
    // skip decoding
    image_util_detail::resize_image_impl((const char*)src_image.get_image_data(),
        src_image.m_width, src_image.m_height, src_image.m_channels, resized_width,
        resized_height, resized_channels, &resized_data);
  } else {
    // make a copy and decode
    flexible_type tmp = image;
    flex_image& decoded_image = tmp.mutable_get<flex_image>();
    image_util_detail::decode_image_impl(decoded_image);
    image_util_detail::resize_image_impl((const char*)decoded_image.get_image_data(),
        decoded_image.m_width, decoded_image.m_height, decoded_image.m_channels, resized_width,
        resized_height, resized_channels, &resized_data);
  }
  flex_image dst_img;
  dst_img.m_width = resized_width;
  dst_img.m_height = resized_height;
  dst_img.m_channels = resized_channels;
  dst_img.m_format = Format::RAW_ARRAY;
  dst_img.m_image_data_size = resized_height * resized_width * resized_channels;
  dst_img.m_image_data.reset(resized_data);
  if (!decode) {
    image_util_detail::encode_image_impl(dst_img);
  }
  return dst_img;
}