std::unique_ptr<IFunction> create_eltwise_layer(EltwiseLayerNode &node)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE(
        "Creating GC EltwiseLayer node with ID : " << node.id() << " and Name: " << node.name() << std::endl);
    ARM_COMPUTE_ERROR_ON(node.num_inputs() != 2);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Extract IO and info
    IGCTensor             *input1         = get_backing_tensor(node.input(0));
    IGCTensor             *input2         = get_backing_tensor(node.input(1));
    IGCTensor             *output         = get_backing_tensor(node.output(0));
    const EltwiseOperation eltwise_op     = node.eltwise_operation();
    const ConvertPolicy    convert_policy = node.convert_policy();
    ARM_COMPUTE_ERROR_ON(input1 == nullptr);
    ARM_COMPUTE_ERROR_ON(input2 == nullptr);
    ARM_COMPUTE_ERROR_ON(output == nullptr);

    std::unique_ptr<IFunction> func = nullptr;
    std::string                func_name;
    if(eltwise_op == EltwiseOperation::ADD)
    {
        std::tie(func, func_name) = create_named_function<GCArithmeticAddition>(std::string("GCArithmeticAddition"),
                                                                                input1, input2, output,
                                                                                convert_policy);
    }
    else if(eltwise_op == EltwiseOperation::SUB)
    {
        ARM_COMPUTE_ERROR("Arithmetic subtraction is not supported in GLES backend");
    }
    else if(eltwise_op == EltwiseOperation::MUL)
    {
        std::tie(func, func_name) = create_named_function<GCPixelWiseMultiplication>(
                                        std::string("GCPixelWiseMultiplication"), input1, input2, output, 1.f);
    }
    else
    {
        ARM_COMPUTE_ERROR("Unsupported element-wise operation!");
    }

    // Log info
    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated " << func_name
                               << " Data Type: " << input1->info()->data_type()
                               << " Shape : " << input1->info()->tensor_shape()
                               << std::endl);

    return func;
}