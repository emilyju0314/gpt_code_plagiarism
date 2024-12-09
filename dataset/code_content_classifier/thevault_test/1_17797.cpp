std::unique_ptr<IFunction> create_fully_connected_layer(FullyConnectedLayerNode &node, GraphContext &ctx)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE(
        "Creating GC FullyConnectedLayer node with ID : " << node.id() << " and Name: " << node.name()
        << std::endl);
    ARM_COMPUTE_ERROR_ON(node.num_inputs() != 3);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Extract IO and info
    IGCTensor *input   = get_backing_tensor(node.input(0));
    IGCTensor *weights = get_backing_tensor(node.input(1));
    IGCTensor *biases  = get_backing_tensor(node.input(2));
    IGCTensor *output  = get_backing_tensor(node.output(0));

    // Create and configure function
    auto func = support::cpp14::make_unique<GCFullyConnectedLayer>(get_memory_manager(ctx, Target::GC));
    func->configure(input, weights, biases, output);
    ARM_COMPUTE_ERROR_ON(input == nullptr);
    ARM_COMPUTE_ERROR_ON(weights == nullptr);
    ARM_COMPUTE_ERROR_ON(output == nullptr);

    // Log info
    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated GCFullyConnectedLayer"
                               << " Data Type: " << input->info()->data_type()
                               << " Input shape: " << input->info()->tensor_shape()
                               << " Weights shape: " << weights->info()->tensor_shape()
                               << " Biases Shape: " << biases->info()->tensor_shape()
                               << " Output shape: " << output->info()->tensor_shape()
                               << std::endl);

    return std::move(func);
}