std::unique_ptr<IFunction> create_activation_layer(ActivationLayerNode &node)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE(
        "Creating GC ActivationLayerNode node with ID : " << node.id() << " and Name: " << node.name()
        << std::endl);
    ARM_COMPUTE_ERROR_ON(node.num_inputs() != 1);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Extract IO and info
    IGCTensor                *input    = get_backing_tensor(node.input(0));
    IGCTensor                *output   = get_backing_tensor(node.output(0));
    const ActivationLayerInfo act_info = node.activation_info();

    // Create function
    auto func = support::cpp14::make_unique<GCActivationLayer>();
    func->configure(input, output, act_info);

    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated GCActivationLayer"
                               << " Data Type: " << input->info()->data_type()
                               << " Shape: " << input->info()->tensor_shape()
                               << " Activation function: " << act_info.activation()
                               << " a: " << act_info.a()
                               << " b: " << act_info.b()
                               << " InPlace : " << is_in_place_operation(input, output)
                               << std::endl);

    return std::move(func);
}