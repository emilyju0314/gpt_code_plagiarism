std::shared_ptr<unity_sarray> vector_sarray_to_image_sarray(
    std::shared_ptr<unity_sarray> image_sarray,
    size_t width, size_t height, size_t channels,
    bool undefined_on_failure) {
  log_func_entry();
  size_t expected_array_size = height * width * channels;
  auto transformfn = 
      [height,width,channels,
      expected_array_size,undefined_on_failure](const flex_vec& vec)->flexible_type {
        try {
          if (expected_array_size != vec.size()) { 
            logprogress_stream << "Dimensions do not match vec size" << std::endl;
            log_and_throw("Dimensions do not match vec size");
          }
          flexible_type ret;
          flex_image img;
          size_t data_size = vec.size();
          char* data = new char[data_size];
          for (size_t i = 0; i < data_size; ++i){
            data[i] = static_cast<char>(vec[i]);
          }
          img.m_image_data_size = data_size;
          img.m_image_data.reset(data);
          img.m_height = height;
          img.m_width = width; 
          img.m_channels = channels;
          img.m_format = Format::RAW_ARRAY;
          img.m_version = 0;
          ret = img;
          return ret;
        } catch (...) {
          if (undefined_on_failure) {
            return FLEX_UNDEFINED;
          } else {
            throw;
          }
        }
      };

  auto ret = image_sarray->transform_lambda(transformfn, 
                                            flex_type_enum::IMAGE, true, 0);
  return std::static_pointer_cast<unity_sarray>(ret);
}