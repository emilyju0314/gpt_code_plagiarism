ExcaliburProcessPlugin::ExcaliburProcessPlugin() :
      asic_counter_depth_(DEPTH_12_BIT),
      image_width_(2048),
      image_height_(256),
      image_pixels_(image_width_ * image_height_)
  {
    // Setup logging for the class
    logger_ = Logger::getLogger("FW.ExcaliburProcessPlugin");
    logger_->setLevel(Level::getAll());
    LOG4CXX_TRACE(logger_, "ExcaliburProcessPlugin constructor.");
  }