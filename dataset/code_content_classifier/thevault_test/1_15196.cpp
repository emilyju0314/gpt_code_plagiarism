bool ChainAddEdgesProcessorLocal::checkVersion(const cpp2::AddEdgesRequest& req) {
  auto part = req.get_parts().begin()->first;
  auto sKeys = sEdgeKey(req);
  auto currVer = ConsistUtil::getMultiEdgeVers(env_->kvstore_, spaceId_, part, sKeys);
  for (auto i = 0U; i != currVer.size(); ++i) {
    if (currVer[i] < resumedEdgeVer_) {
      return false;
    }
  }
  return true;
}