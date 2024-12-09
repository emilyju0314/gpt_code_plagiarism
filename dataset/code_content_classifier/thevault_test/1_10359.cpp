CvImagePtr toCvCopyImpl(const cv::Mat& source,
                        const roslib::Header& src_header,
                        const std::string& src_encoding,
                        const std::string& dst_encoding)
{
  /// @todo Handle endianness - e.g. 16-bit dc1394 camera images are big-endian
  
  // Copy metadata
  CvImagePtr ptr = boost::make_shared<CvImage>();
  ptr->header = src_header;
  
  // Copy to new buffer if same encoding requested
  if (dst_encoding.empty() || dst_encoding == src_encoding)
  {
    ptr->encoding = src_encoding;
    source.copyTo(ptr->image);
  }
  else
  {
    // Convert the source data to the desired encoding
    Format src_format = getFormat(src_encoding);
    Format dst_format = getFormat(dst_encoding);
    if (src_format == INVALID || dst_format == INVALID)
      throw Exception("Unsupported conversion from [" + src_encoding +
                      "] to [" + dst_encoding + "]");

    int conversion_code = getConversionCode(src_format, dst_format);
    if (conversion_code == SAME_FORMAT)
    {
      // Same number of channels, but different bit depth
      double alpha = 1.0;
      int src_depth = enc::bitDepth(src_encoding);
      int dst_depth = enc::bitDepth(dst_encoding);
      // Do scaling between CV_8U [0,255] and CV_16U [0,65535] images.
      if (src_depth == 8 && dst_depth == 16)
        alpha = 65535. / 255.;
      else if (src_depth == 16 && dst_depth == 8)
        alpha = 255. / 65535.;
      source.convertTo(ptr->image, getCvType(dst_encoding), alpha);
    }
    else
    {
      // Perform color conversion
      cv::cvtColor(source, ptr->image, conversion_code);
    }
    ptr->encoding = dst_encoding;
  }

  return ptr;
}