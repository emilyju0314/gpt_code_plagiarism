IKNaChannel::IKNaChannel() {
  params_ = NULL;

  state_.set_g(0);
  state_.set_na(0);
  state_.set_output(0);

  type_ = NU_TYPE_CHANNEL;
}