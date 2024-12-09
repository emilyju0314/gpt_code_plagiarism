void *read_jpeg(const char* jpgbuffer, size_t jpgbuffer_size, bool RGB,
                    size_t& output_size, size_t& w, size_t& h)
    {
      struct jpeg_decompress_struct cinfo;
      struct urbi_jpeg_error_mgr jerr;
      cinfo.err = jpeg_std_error(&jerr.pub);
      jerr.pub.error_exit = urbi_jpeg_error_exit;
      if (setjmp(jerr.setjmp_buffer))
      {
        /* If we get here, the JPEG code has signaled an error.  We
         * need to clean up the JPEG object, close the input file, and
         * return.
         */
        jpeg_destroy_decompress(&cinfo);
        GD_ERROR("JPEG error!");
        return 0;
      }
      jpeg_create_decompress(&cinfo);
      mem_source_mgr *source = (struct mem_source_mgr *)
        (*cinfo.mem->alloc_small) ((j_common_ptr) & cinfo, JPOOL_PERMANENT,
                                   sizeof (mem_source_mgr));

      cinfo.src = (jpeg_source_mgr *) source;
      source->pub.skip_input_data = skip_input_data;
      source->pub.term_source = term_source;
      source->pub.init_source = init_source;
      source->pub.fill_input_buffer = fill_input_buffer;
      source->pub.resync_to_restart = jpeg_resync_to_restart;
      source->pub.bytes_in_buffer = jpgbuffer_size;
      source->pub.next_input_byte = (JOCTET *) jpgbuffer;
      cinfo.out_color_space = (RGB ? JCS_RGB : JCS_YCbCr);
      jpeg_read_header(&cinfo, TRUE);
      cinfo.out_color_space = (RGB ? JCS_RGB : JCS_YCbCr);
      jpeg_start_decompress(&cinfo);
      w = cinfo.output_width;
      h = cinfo.output_height;
      output_size =
        cinfo.output_width * cinfo.output_components * cinfo.output_height;
      void *buffer = malloc(output_size);

      while (cinfo.output_scanline < cinfo.output_height)
      {
        /* jpeg_read_scanlines expects an array of pointers to scanlines.
         * Here the array is only one element long, but you could ask for
         * more than one scanline at a time if that's more convenient.
         */
        JSAMPLE* row =
          (JSAMPLE *) &((char*) buffer)[cinfo.output_scanline
                                        * cinfo.output_components
                                        * cinfo.output_width];
        jpeg_read_scanlines(&cinfo, &row, 1);
      }
      jpeg_finish_decompress(&cinfo);
      jpeg_destroy_decompress(&cinfo);

      return buffer;
    }