void MLUTensorImpl::insert_views_op_info(const VIEWOPNAME& name,
            const typename MLUTensorImpl::TupleRecordOpInfo& input,
            const bool input_contiguous) {
  if (is_compare_size_stride_info(input) == true) {
    return;
  }
  if (using_shared_op_info_ == false) {
    graph_seg_record_.clear();
    shared_op_info_.clear();
  }

  typename MLUTensorImpl::TupleRecordOpInfo output = std::make_tuple(sizes().vec(),
                                                                     strides().vec(),
                                                                     storage_offset());
  auto op_info = std::make_tuple(name, input, output);
  // add new op to shared_ops
  check_add_op_into_shared_ops(op_info);
  auto it = std::find(shared_op_info_.begin(), shared_op_info_.end(), op_info);
  int op_index = std::distance(shared_op_info_.begin(), it);

  if (input_contiguous == true) {
    graph_seg_record_.push_back(std::vector<int>({op_index}));
  } else {
    // find start node in each graph, and copy index list.
    int index_of_graph = 0;
    int index_of_inner_graph = 0;
    std::tie(index_of_graph, index_of_inner_graph) = search_op_segm_index(input);
    if (index_of_graph == -1 && index_of_inner_graph == -1) {
      // can't find op info in graph, so add a graph seg to graph_seg_record_;
      // Specially this func is for non-contiguous input of graph.
      graph_seg_record_.push_back(std::vector<int>({op_index}));
      using_shared_op_info_ = true;
      return;
    }
    TORCH_CHECK(index_of_graph < graph_seg_record_.size(),
      "index out of graph_seg_record_ range.");
    TORCH_CHECK(index_of_inner_graph < graph_seg_record_[index_of_graph].size(),
      "index out of graph_seg_record_ inner graph seg range.");
    const int graph_len = graph_seg_record_[index_of_graph].size() - 1;
    if (index_of_inner_graph == graph_len) {
      // a new node push to old graph.
      graph_seg_record_[index_of_graph].push_back(op_index);
    } else {
      // copy a new graph for push op node
      std::vector<int> new_graph_seg(graph_seg_record_[index_of_graph].begin(),
        graph_seg_record_[index_of_graph].begin()+index_of_inner_graph);
      new_graph_seg.push_back(op_index);
      // if graph already in graph_seg_record_, pass;
      // else push to graph_seg_record_.
      check_and_add_new_graph(new_graph_seg);
    }
  }
  using_shared_op_info_ = true;
  }