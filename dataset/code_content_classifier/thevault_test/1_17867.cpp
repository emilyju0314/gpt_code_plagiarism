void Graph::add_tensor_object(std::unique_ptr<ITensorObject> tensor)
{
    // If it's the first Tensor added then it will be the input of the Graph.
    if(_pimpl->_graph_input == nullptr)
    {
        ARM_COMPUTE_ERROR_ON(_pimpl->_graph_output != nullptr);
        ARM_COMPUTE_ERROR_ON(_pimpl->_current_node != nullptr);
        _pimpl->_graph_input = std::move(tensor);
    }
    else
    {
        // Else it will be the output of the Graph
        ARM_COMPUTE_ERROR_ON(_pimpl->_graph_output != nullptr);
        ARM_COMPUTE_ERROR_ON(_pimpl->_current_node == nullptr);
        _pimpl->_graph_output   = std::move(tensor);
        _pimpl->_current_output = _pimpl->_graph_output.get();

        // Finalize the graph by configuring the last Node of the graph:
        _pimpl->configure(_pimpl->_current_hints); // Ignore _next_hint as this is the last node, and just use the same hint as before this node.
        _pimpl->_graph_output->allocate();
    }
}