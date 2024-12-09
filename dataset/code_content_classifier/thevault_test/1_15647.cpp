ACMGenericCodec::ACMGenericCodec(const CodecInst& codec_inst,
                                 int cng_pt_nb,
                                 int cng_pt_wb,
                                 int cng_pt_swb,
                                 int cng_pt_fb,
                                 bool enable_red,
                                 int red_pt_nb)
    : has_internal_fec_(false),
      copy_red_enabled_(enable_red),
      encoder_(NULL),
      bitrate_bps_(0),
      fec_enabled_(false),
      loss_rate_(0),
      max_playback_rate_hz_(48000),
      max_payload_size_bytes_(-1),
      max_rate_bps_(-1),
      opus_dtx_enabled_(false),
      is_opus_(false),
      is_isac_(false),
      opus_application_set_(false) {
  acm_codec_params_.codec_inst = codec_inst;
  acm_codec_params_.enable_dtx = false;
  acm_codec_params_.enable_vad = false;
  acm_codec_params_.vad_mode = VADNormal;
  SetPtInMap(&red_pt_, 8000, red_pt_nb);
  SetPtInMap(&cng_pt_, 8000, cng_pt_nb);
  SetPtInMap(&cng_pt_, 16000, cng_pt_wb);
  SetPtInMap(&cng_pt_, 32000, cng_pt_swb);
  SetPtInMap(&cng_pt_, 48000, cng_pt_fb);
  ResetAudioEncoder();
  CHECK(encoder_);
}