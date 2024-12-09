std::unique_ptr<arm_compute::IFunction> create_depth_concatenate_layer(DepthConcatenateLayerNode &node)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE("Creating GC DepthConcatenate node with ID : " << node.id() << " and Name: " << node.name() << std::endl);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Return nullptr if depth concatenate is switched off
    if(!node.is_enabled())
    {
        return nullptr;
    }

    // Extract IO and info
    std::vector<arm_compute::IGCTensor *> inputs;
    for(unsigned int i = 0; i < node.num_inputs(); ++i)
    {
        inputs.push_back(get_backing_tensor(node.input(i)));
    }
    IGCTensor *output = get_backing_tensor(node.output(0));

    // Create and configure function
    auto func = support::cpp14::make_unique<GCDepthConcatenateLayer>();
    func->configure(inputs, output);

    // Log info
    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated GCDepthConcatenateLayer"
                               << " Data Type: " << output->info()->data_type()
                               << " Shape: " << output->info()->tensor_shape()
                               << " Num Inputs: " << inputs.size()
                               << std::endl);

    return std::move(func);
}