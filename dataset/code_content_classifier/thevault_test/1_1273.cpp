std::size_t ExcaliburProcessPlugin::reordered_image_size(int asic_counter_depth) {

    std::size_t slice_size = 0;

    switch (asic_counter_depth)
    {
      case DEPTH_1_BIT:
      case DEPTH_6_BIT:
        slice_size = image_width_ * image_height_ * sizeof(unsigned char);
        break;

      case DEPTH_12_BIT:
        slice_size = image_width_ * image_height_ * sizeof(unsigned short);
        break;

      case DEPTH_24_BIT:
        slice_size = image_width_ * image_height_ * sizeof(unsigned int);
        break;

      default:
      {
        std::stringstream msg;
        msg << "Invalid bit depth specified for reordered slice size: " << asic_counter_depth;
        throw std::runtime_error(msg.str());
      }
      break;
    }

    return slice_size;

  }