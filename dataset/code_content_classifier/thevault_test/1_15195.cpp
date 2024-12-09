bool ChainAddEdgesProcessorLocal::checkTerm(const cpp2::AddEdgesRequest& req) {
  auto space = req.get_space_id();
  auto partId = req.get_parts().begin()->first;

  auto part = env_->kvstore_->part(space, partId);
  if (!nebula::ok(part)) {
    pushResultCode(nebula::error(part), localPartId_);
    return false;
  }
  auto curTerm = (nebula::value(part))->termId();
  if (restrictTerm_ != curTerm) {
    VLOG(1) << folly::sformat(
        "check term failed, restrictTerm_={}, currTerm={}", restrictTerm_, curTerm);
    return false;
  }
  return true;
}