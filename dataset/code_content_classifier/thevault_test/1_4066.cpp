std::vector<typename MLUTensorImpl::SharedOpInfo> MLUTensorImpl::get_views_op_info(
                        const typename MLUTensorImpl::TupleRecordOpInfo& input) {
  if (using_shared_op_info_ == false) {
    return std::vector<typename MLUTensorImpl::SharedOpInfo>();
  }
  const int graph_size_len = graph_seg_record_.size();
  const int shared_op_len = shared_op_info_.size();
  TORCH_CHECK(graph_size_len != 0,
      "graph_seg_record_ is null.");
  TORCH_CHECK(shared_op_len != 0,
      "shared_op_info_ is null.");
  int seg_index = 0;
  bool find_seg = false;
  for (int i = 0; i < graph_size_len; ++i) {
    const int index = graph_seg_record_[i].back();
    TORCH_CHECK(index < shared_op_len,
      "Index is bigger than shared_op_len.");
    if (std::get<2>(shared_op_info_[index]) == input) {
      seg_index = i;
      find_seg = true;
      break;
    }
  }
  if (find_seg == false) {
    return std::vector<typename MLUTensorImpl::SharedOpInfo>();
  }
  TORCH_CHECK(seg_index < graph_size_len,
      "Index out of graph_size_len range.");
  std::vector<typename MLUTensorImpl::SharedOpInfo> graph_seg;
  for (const auto& index : graph_seg_record_[seg_index]) {
    TORCH_CHECK(index < shared_op_len,
      "Index out of shared_op_len range.");
    graph_seg.push_back(shared_op_info_[index]);
  }
  return graph_seg;
}