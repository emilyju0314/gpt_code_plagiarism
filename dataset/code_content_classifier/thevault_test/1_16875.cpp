std::pair<torch::Tensor, torch::optional<torch::Tensor>>
ComputeTransducerLossCpu(torch::Tensor &logits,  // NOLINT
                         const torch::Tensor &targets,
                         const torch::Tensor &logit_lengths,
                         const torch::Tensor &target_lengths, int32_t blank) {
  // The denominator for the log-softmax.
  // Note that it is positive at present.
  torch::Tensor denominator = logits.logsumexp(/*dim*/ 1, /*keepdim*/ false);

  torch::Tensor log_probs = ComputeLogProbs(
      logits, denominator, targets, logit_lengths, target_lengths, blank);

  torch::Tensor alpha;
  torch::Tensor total_scores;
  std::tie(alpha, total_scores) =
      ComputeAlpha(log_probs, logit_lengths, target_lengths);

  torch::Tensor beta =
      ComputeBeta(log_probs, logit_lengths, target_lengths).first;

  bool requires_grad = logits.requires_grad();
  if (requires_grad) {
    torch::Tensor &gradient = logits;
    ComputeGradient(logits, logit_lengths, targets, target_lengths, denominator,
                    alpha, beta, blank, &gradient);
  }

  return {total_scores, requires_grad ? logits : torch::Tensor()};
}