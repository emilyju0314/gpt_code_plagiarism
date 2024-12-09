int HandleCommandLineFlags(webrtc::test::TestConfig* config) {
  // Validate the mandatory flags:
  if (FLAGS_input_filename.empty() || FLAGS_width == -1 || FLAGS_height == -1) {
    printf("%s\n", google::ProgramUsage());
    return 1;
  }
  config->name = FLAGS_test_name;
  config->description = FLAGS_test_description;

  // Verify the input file exists and is readable.
  FILE* test_file;
  test_file = fopen(FLAGS_input_filename.c_str(), "rb");
  if (test_file == NULL) {
    fprintf(stderr, "Cannot read the specified input file: %s\n",
            FLAGS_input_filename.c_str());
    return 2;
  }
  fclose(test_file);
  config->input_filename = FLAGS_input_filename;

  // Verify the output dir exists.
  struct stat dir_info;
  if (!(stat(FLAGS_output_dir.c_str(), &dir_info) == 0 &&
        S_ISDIR(dir_info.st_mode))) {
    fprintf(stderr, "Cannot find output directory: %s\n",
            FLAGS_output_dir.c_str());
    return 3;
  }
  config->output_dir = FLAGS_output_dir;

  // Manufacture an output filename if none was given.
  if (FLAGS_output_filename.empty()) {
    // Cut out the filename without extension from the given input file
    // (which may include a path)
    int startIndex = FLAGS_input_filename.find_last_of("/") + 1;
    if (startIndex == 0) {
      startIndex = 0;
    }
    FLAGS_output_filename =
        FLAGS_input_filename.substr(
            startIndex, FLAGS_input_filename.find_last_of(".") - startIndex) +
        "_out.yuv";
  }

  // Verify output file can be written.
  if (FLAGS_output_dir == ".") {
    config->output_filename = FLAGS_output_filename;
  } else {
    config->output_filename = FLAGS_output_dir + "/" + FLAGS_output_filename;
  }
  test_file = fopen(config->output_filename.c_str(), "wb");
  if (test_file == NULL) {
    fprintf(stderr, "Cannot write output file: %s\n",
            config->output_filename.c_str());
    return 4;
  }
  fclose(test_file);

  // Check single core flag.
  config->use_single_core = FLAGS_use_single_core;

  // Get codec specific configuration.
  webrtc::VideoCodingModule::Codec(webrtc::kVideoCodecVP8,
                                   config->codec_settings);

  // Check the temporal layers.
  if (FLAGS_temporal_layers < 0 ||
      FLAGS_temporal_layers > webrtc::kMaxTemporalStreams) {
    fprintf(stderr, "Temporal layers number must be 0-4, was: %d\n",
            FLAGS_temporal_layers);
    return 13;
  }
  config->codec_settings->codecSpecific.VP8.numberOfTemporalLayers =
      FLAGS_temporal_layers;

  // Check the bit rate.
  if (FLAGS_bitrate <= 0) {
    fprintf(stderr, "Bit rate must be >0 kbps, was: %d\n", FLAGS_bitrate);
    return 5;
  }
  config->codec_settings->startBitrate = FLAGS_bitrate;

  // Check the keyframe interval.
  if (FLAGS_keyframe_interval < 0) {
    fprintf(stderr, "Keyframe interval must be >=0, was: %d\n",
            FLAGS_keyframe_interval);
    return 6;
  }
  config->keyframe_interval = FLAGS_keyframe_interval;

  // Check packet size and max payload size.
  if (FLAGS_packet_size <= 0) {
    fprintf(stderr, "Packet size must be >0 bytes, was: %d\n",
            FLAGS_packet_size);
    return 7;
  }
  config->networking_config.packet_size_in_bytes =
      static_cast<size_t>(FLAGS_packet_size);

  if (FLAGS_max_payload_size <= 0) {
    fprintf(stderr, "Max payload size must be >0 bytes, was: %d\n",
            FLAGS_max_payload_size);
    return 8;
  }
  config->networking_config.max_payload_size_in_bytes =
      static_cast<size_t>(FLAGS_max_payload_size);

  // Check the width and height
  if (FLAGS_width <= 0 || FLAGS_height <= 0) {
    fprintf(stderr, "Width and height must be >0.");
    return 9;
  }
  config->codec_settings->width = FLAGS_width;
  config->codec_settings->height = FLAGS_height;
  config->codec_settings->maxFramerate = FLAGS_framerate;

  // Calculate the size of each frame to read (according to YUV spec).
  config->frame_length_in_bytes =
      3 * config->codec_settings->width * config->codec_settings->height / 2;

  // Check packet loss settings
  if (FLAGS_packet_loss_mode != "uniform" &&
      FLAGS_packet_loss_mode != "burst") {
    fprintf(stderr,
            "Unsupported packet loss mode, must be 'uniform' or "
            "'burst'\n.");
    return 10;
  }
  config->networking_config.packet_loss_mode = webrtc::test::kUniform;
  if (FLAGS_packet_loss_mode == "burst") {
    config->networking_config.packet_loss_mode = webrtc::test::kBurst;
  }

  if (FLAGS_packet_loss_probability < 0.0 ||
      FLAGS_packet_loss_probability > 1.0) {
    fprintf(stderr,
            "Invalid packet loss probability. Must be 0.0 - 1.0, "
            "was: %f\n",
            FLAGS_packet_loss_probability);
    return 11;
  }
  config->networking_config.packet_loss_probability =
      FLAGS_packet_loss_probability;

  if (FLAGS_packet_loss_burst_length < 1) {
    fprintf(stderr,
            "Invalid packet loss burst length, must be >=1, "
            "was: %d\n",
            FLAGS_packet_loss_burst_length);
    return 12;
  }
  config->networking_config.packet_loss_burst_length =
      FLAGS_packet_loss_burst_length;
  config->verbose = FLAGS_verbose;
  return 0;
}