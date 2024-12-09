std::vector<NodeColumnView> partitionData(Context * context,
											const BlazingTableView & table,
											const BlazingTableView & pivots,
											const std::vector<int> & searchColIndices,
											std::vector<cudf::order> sortOrderTypes) {

	RAL_EXPECTS(pivots.view().num_columns() == searchColIndices.size(), "Mismatched pivots num_columns and searchColIndices");

	cudf::size_type num_rows = table.view().num_rows();
	if(num_rows == 0) {
		std::vector<NodeColumnView> array_node_columns;
		auto nodes = context->getAllNodes();
		for(std::size_t i = 0; i < nodes.size(); ++i) {
			array_node_columns.emplace_back(nodes[i], BlazingTableView(table.view(), table.names()));
		}
		return array_node_columns;
	}

	if(sortOrderTypes.size() == 0) {
		sortOrderTypes.assign(searchColIndices.size(), cudf::order::ASCENDING);
	}

	// TODO this is just a default setting. Will want to be able to properly set null_order
	std::vector<cudf::null_order> null_orders(sortOrderTypes.size(), cudf::null_order::AFTER);

	CudfTableView columns_to_search = table.view().select(searchColIndices);

	std::unique_ptr<cudf::column> pivot_indexes = cudf::upper_bound(columns_to_search,
                                    pivots.view(),
                                    sortOrderTypes,
                                    null_orders);

	std::vector<cudf::size_type> host_data(pivot_indexes->view().size());
	CUDA_TRY(cudaMemcpy(host_data.data(), pivot_indexes->view().data<cudf::size_type>(), pivot_indexes->view().size() * sizeof(cudf::size_type), cudaMemcpyDeviceToHost));

	std::vector<CudfTableView> partitioned_data = cudf::split(table.view(), host_data);

	std::vector<Node> all_nodes = context->getAllNodes();

	RAL_EXPECTS(all_nodes.size() <= partitioned_data.size(), "Number of table partitions is smalled than total nodes");

	int step = static_cast<int>(partitioned_data.size() / all_nodes.size());
	std::vector<NodeColumnView> partitioned_node_column_views;
	for (int i = 0; i < partitioned_data.size(); i++){
		int node_idx = std::min(i / step, static_cast<int>(all_nodes.size() - 1));
		partitioned_node_column_views.push_back(std::make_pair(all_nodes[node_idx], BlazingTableView(partitioned_data[i], table.names())));
	}

	return partitioned_node_column_views;
}