std::unique_ptr<IFunction> create_batch_normalization_layer(BatchNormalizationLayerNode &node)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE("Creating GC BatchNormalization node with ID : " << node.id() << " and Name: " << node.name() << std::endl);

    ARM_COMPUTE_ERROR_ON(node.num_inputs() != 5);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Extract IO and info
    IGCTensor                *input     = get_backing_tensor(node.input(0));
    IGCTensor                *mean      = get_backing_tensor(node.input(1));
    IGCTensor                *var       = get_backing_tensor(node.input(2));
    IGCTensor                *beta      = get_backing_tensor(node.input(3));
    IGCTensor                *gamma     = get_backing_tensor(node.input(4));
    IGCTensor                *output    = get_backing_tensor(node.output(0));
    const float               epsilon   = node.epsilon();
    const ActivationLayerInfo fused_act = node.fused_activation();

    // Create and configure function
    auto func = support::cpp14::make_unique<GCBatchNormalizationLayer>();
    func->configure(input, output, mean, var, beta, gamma, epsilon, fused_act);

    // Log info
    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated GCBatchNormalizationLayer"
                               << " Data Type: " << input->info()->data_type()
                               << " Shape: " << input->info()->tensor_shape()
                               << " Epsilon: " << epsilon << " "
                               << (fused_act.enabled() ? to_string(fused_act.activation()) : "")
                               << " InPlace : " << is_in_place_operation(input, output)
                               << std::endl);

    return std::move(func);
}