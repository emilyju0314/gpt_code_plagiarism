kaldi::BaseFloat precondition_directions(kaldi::nnet3::OnlineNaturalGradient &state, torch::Tensor &grad) {
    kaldi::BaseFloat scale_;
    auto grad_cumat = TensorToKaldiCuSubMatrix(grad);
    state.PreconditionDirections(&grad_cumat, &scale_);
    return scale_;
}