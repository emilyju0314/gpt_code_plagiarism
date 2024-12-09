void ExcaliburProcessPlugin::process_frame(boost::shared_ptr<Frame> frame)
  {
    LOG4CXX_TRACE(logger_, "Reordering frame.");
    LOG4CXX_TRACE(logger_, "Frame size: " << frame->get_data_size());

    const Excalibur::FrameHeader* hdr_ptr =
        static_cast<const Excalibur::FrameHeader*>(frame->get_data());

    LOG4CXX_TRACE(logger_, "Raw frame number: " << hdr_ptr->frame_number);
    LOG4CXX_TRACE(logger_, "Frame state: " << hdr_ptr->frame_state);
    LOG4CXX_TRACE(logger_, "Packets received: " << hdr_ptr->total_packets_received
        << " SOF markers: "<< (int)hdr_ptr->total_sof_marker_count
        << " EOF markers: "<< (int)hdr_ptr->total_eof_marker_count);

    // Loop over the active FEM list to determine the maximum active FEM index

    unsigned int max_active_fem_idx = 0;
    {
      std::stringstream msg;
      msg << "Number of active FEMs: " << static_cast<int>(hdr_ptr->num_active_fems) << " ids:";
      for (uint8_t idx = 0; idx < hdr_ptr->num_active_fems; idx++)
      {
        if (hdr_ptr->active_fem_idx[idx] > max_active_fem_idx)
        {
          max_active_fem_idx = hdr_ptr->active_fem_idx[idx];
        }
        msg << " " << static_cast<int>(hdr_ptr->active_fem_idx[idx]);
      }
      LOG4CXX_TRACE(logger_, msg.str());
    }

    // Determine the size of the output reordered image based on current bit depth
    const std::size_t output_image_size = reordered_image_size(asic_counter_depth_);
    LOG4CXX_TRACE(logger_, "Output image size: " << output_image_size);

    // Obtain a pointer to the start of the data in the frame
    const void* data_ptr = static_cast<const void*>(
        static_cast<const char*>(frame->get_data()) + sizeof(Excalibur::FrameHeader)
    );

    // Pointers to reordered image buffer - will be allocated on demand
    void* reordered_image = NULL;

    try
    {

      // Check that the pixels from all active FEMs are contained within the dimensions of the
      // specified output image, otherwise throw an error
      if (((max_active_fem_idx +1) * FEM_TOTAL_PIXELS) > image_pixels_)
      {
        std::stringstream msg;
        msg << "Pixel count inferred from active FEMs ("
            << ((max_active_fem_idx + 1) * FEM_TOTAL_PIXELS)
            << ", max FEM idx: " << max_active_fem_idx
            << ") will exceed dimensions of output image (" << image_pixels_ << ")";
        throw std::runtime_error(msg.str());
      }

      // Allocate buffer to receive reordered image.
      reordered_image = (void*)malloc(output_image_size);
      if (reordered_image == NULL)
      {
        throw std::runtime_error("Failed to allocate temporary buffer for reordered image");
      }

      // Calculate the FEM frame size once so it can be used in the following loop
      // repeatedly
      std::size_t fem_frame_size = (
          Excalibur::num_subframes[asic_counter_depth_] *
          Excalibur::subframe_size(static_cast<Excalibur::AsicCounterBitDepth>(asic_counter_depth_))
      );

      // Loop over active FEMs in the input frame image data, reordering pixels into the output
      // images

      for (uint8_t idx = 0; idx < hdr_ptr->num_active_fems; idx++)
      {
        uint8_t fem_idx = hdr_ptr->active_fem_idx[idx];

        // Calculate pointer into the input image data based on loop index
        void* input_ptr = static_cast<void *>(
            static_cast<char *>(const_cast<void *>(data_ptr)) + (fem_frame_size * idx)
        );

        // Calculate output image pixel offset based on active FEM index
        std::size_t output_offset = fem_idx * FEM_TOTAL_PIXELS;

        // Determine stripe orientation based on FEM index
        bool stripe_is_even = ((fem_idx & 1) == 0);
        LOG4CXX_TRACE(logger_, "Active FEM idx=" << static_cast<int>(fem_idx)
            << ": stripe orientation is " << (stripe_is_even ? "even" : "odd"));

        // Reorder strip according to counter depth
        switch (asic_counter_depth_)
        {
          case DEPTH_1_BIT: // 1-bit counter depth
            reorder_1bit_stripe(static_cast<unsigned int *>(input_ptr),
                                static_cast<unsigned char *>(reordered_image) + output_offset,
                                stripe_is_even);
            break;

          case DEPTH_6_BIT: // 6-bit counter depth
            reorder_6bit_stripe(static_cast<unsigned char *>(input_ptr),
                                static_cast<unsigned char *>(reordered_image) + output_offset,
                                stripe_is_even);
            break;

          case DEPTH_12_BIT: // 12-bit counter depth
            reorder_12bit_stripe(static_cast<unsigned short *>(input_ptr),
                                 static_cast<unsigned short *>(reordered_image) + output_offset,
                                 stripe_is_even);
            break;

          case DEPTH_24_BIT: // 24-bit counter depth needs special handling to merge two counters

            void* c1_input_ptr = input_ptr;
            void* c0_input_ptr =  static_cast<void *>(static_cast<char *>(input_ptr) + fem_frame_size / 2);

            reorder_24bit_stripe(
                static_cast<unsigned short *>(c0_input_ptr),
                static_cast<unsigned short *>(c1_input_ptr),
                static_cast<unsigned int *>(reordered_image) + output_offset,
                stripe_is_even);

            break;
        }
      }

      // Set the frame image to the reordered image buffer if appropriate
      if (reordered_image)
      {
        // Setup the frame dimensions
        dimensions_t dims(2);
        dims[0] = image_height_;
        dims[1] = image_width_;

        boost::shared_ptr<Frame> data_frame;
        data_frame = boost::shared_ptr<Frame>(new Frame("data"));

        if (asic_counter_depth_ == DEPTH_24_BIT)
        {
          // Only every other incoming frame results in a new frame
          data_frame->set_frame_number(hdr_ptr->frame_number/2);
        }
        else
        {
          data_frame->set_frame_number(hdr_ptr->frame_number);
        }
        data_frame->set_dimensions("data", dims);
        data_frame->copy_data(reordered_image, output_image_size);

        LOG4CXX_TRACE(logger_, "Pushing data frame.");
        this->push(data_frame);

        free(reordered_image);
        reordered_image = NULL;
      }
    }
    catch (const std::exception& e)
    {
      LOG4CXX_ERROR(logger_, "EXCALIBUR frame decode failed: " << e.what());
    }
  }