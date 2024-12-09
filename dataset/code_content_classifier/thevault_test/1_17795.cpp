std::unique_ptr<IFunction> create_depthwise_convolution_layer(DepthwiseConvolutionLayerNode &node)
{
    ARM_COMPUTE_LOG_GRAPH_VERBOSE(
        "Creating GC DepthwiseConvolutionLayer node with ID : " << node.id() << " and Name: " << node.name()
        << std::endl);
    ARM_COMPUTE_ERROR_ON(node.num_inputs() != 3);
    ARM_COMPUTE_ERROR_ON(node.num_outputs() != 1);

    // Extract IO and info
    IGCTensor *input   = get_backing_tensor(node.input(0));
    IGCTensor *weights = get_backing_tensor(node.input(1));
    IGCTensor *biases  = get_backing_tensor(node.input(2));
    IGCTensor *output  = get_backing_tensor(node.output(0));

    if(is_data_type_quantized_asymmetric(input->info()->data_type()))
    {
        biases->info()->set_data_type(DataType::S32);
    }

    const PadStrideInfo              conv_info     = node.convolution_info();
    const DepthwiseConvolutionMethod dwc_algorithm = node.depthwise_convolution_method();

    // Create and configure function (we assume that functions have been validated before creation)
    std::unique_ptr<IFunction> func;
    std::string                func_name;
    if(dwc_algorithm == DepthwiseConvolutionMethod::OPTIMIZED_3x3)
    {
        std::tie(func, func_name) = create_named_function<GCDepthwiseConvolutionLayer3x3>(
                                        std::string("GCDepthwiseConvolutionLayer3x3"), input, weights, biases, output, conv_info);
    }
    else
    {
        ARM_COMPUTE_ERROR("Generic DepthwiseConvolutionLayer is not supported in GLES backend");
    }

    // Log info
    ARM_COMPUTE_LOG_GRAPH_INFO("Instantiated " << func_name
                               << " Data Type: " << input->info()->data_type()
                               << " Input QuantInfo: " << input->info()->quantization_info()
                               << " Weights QuantInfo: " << weights->info()->quantization_info()
                               << " Input shape: " << input->info()->tensor_shape()
                               << " Weights shape: " << weights->info()->tensor_shape()
                               << " Output shape: " << output->info()->tensor_shape()
                               << std::endl);
    return func;
}