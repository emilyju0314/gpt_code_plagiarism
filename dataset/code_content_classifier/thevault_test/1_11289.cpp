flexible_type generate_mean(std::shared_ptr<unity_sarray> unity_data) {
  log_func_entry();

  
  std::vector<flexible_type> sample_img = unity_data->_head(1);
  flex_image meta_img;
  meta_img = sample_img[0];
  size_t channels = meta_img.m_channels;
  size_t height = meta_img.m_height;
  size_t width = meta_img.m_width;
  size_t image_size = width * height * channels;
  size_t num_images = unity_data->size(); 

  //Perform sum
  flexible_type mean = sum(unity_data);
  
  //Divide for mean images.
  mean /= num_images;

  flexible_type ret;
  flex_image img;
  char* data_bytes = new char[image_size];
  for(size_t i = 0; i < image_size; ++i){
    data_bytes[i] = static_cast<unsigned char>(mean[i]);
  } 
  img.m_image_data_size = image_size;
  img.m_channels = channels;
  img.m_height = height;
  img.m_width = width;
  img.m_image_data.reset(data_bytes);
  img.m_version = IMAGE_TYPE_CURRENT_VERSION;
  img.m_format = Format::RAW_ARRAY;
  ret = img;
  return ret;
}