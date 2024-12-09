flexible_type decode_image(const flexible_type& image) {
  if (image.get<flex_image>().is_decoded()) {
    return image;
  }
  flexible_type ret = image;
  flex_image& img = ret.mutable_get<flex_image>();
  image_util_detail::decode_image_impl(img);
  return ret;
}