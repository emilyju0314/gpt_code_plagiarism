void RecodeBeamSearch::Decode(const NetworkIO &output, double dict_ratio,
                              double cert_offset, double worst_dict_cert,
                              const UNICHARSET *charset, int lstm_choice_mode) {
  beam_size_ = 0;
  int width = output.Width();
  if (lstm_choice_mode) {
    timesteps.clear();
  }
  for (int t = 0; t < width; ++t) {
    ComputeTopN(output.f(t), output.NumFeatures(), kBeamWidths[0]);
    DecodeStep(output.f(t), t, dict_ratio, cert_offset, worst_dict_cert,
               charset);
    if (lstm_choice_mode) {
      SaveMostCertainChoices(output.f(t), output.NumFeatures(), charset, t);
    }
  }
}