void Graph::Private::configure(GraphHints _next_hints)
{
    ARM_COMPUTE_ERROR_ON(_current_node == nullptr);
    ARM_COMPUTE_ERROR_ON(_graph_input == nullptr);

    // Is it the first node of the graph ?
    if(_current_input == nullptr)
    {
        _graph_input->set_target(_current_hints.target_hint());
        _current_input  = _graph_input.get();
        _previous_hints = _current_hints; // For the first node just assume the previous node was of the same type as this one
    }

    //Automatic output configuration ?
    if(_current_output == nullptr)
    {
        _tensors.push_back(arm_compute::support::cpp14::make_unique<Tensor>(TensorInfo()));
        _current_output = _tensors.back().get();
    }

    // If either the writer or reader node needs OpenCL then use OpenCL memory:
    if((_next_hints.target_hint() == TargetHint::OPENCL || _current_hints.target_hint() == TargetHint::OPENCL))
    {
        _current_output->set_target(TargetHint::OPENCL);
    }
    else
    {
        _current_output->set_target(TargetHint::NEON);
    }

    // Instantiate Node
    _ctx.hints()                                 = _current_hints;
    std::unique_ptr<arm_compute::IFunction> func = _current_node->instantiate_node(_ctx, _current_input, _current_output);

    // Allocate current input
    _current_input->allocate();

    // Map input if needed
    if(_current_input->target() == TargetHint::OPENCL)
    {
        if(_previous_hints.target_hint() == TargetHint::NEON)
        {
            ARM_COMPUTE_ERROR_ON(_current_hints.target_hint() == TargetHint::NEON);
            _pipeline.push_back({ _current_input, _current_input, arm_compute::support::cpp14::make_unique<CLUnmap>(_current_input) });
        }
        if(_current_hints.target_hint() == TargetHint::NEON)
        {
            ARM_COMPUTE_ERROR_ON(_previous_hints.target_hint() == TargetHint::NEON);
            _pipeline.push_back({ _current_input, _current_input, arm_compute::support::cpp14::make_unique<CLMap>(_current_input, true) });
        }
    }

    _pipeline.push_back({ _current_input, _current_output, std::move(func) });

    _current_input  = _current_output;
    _current_output = nullptr;
    std::swap(_previous_hints, _current_hints);
    std::swap(_current_hints, _next_hints);
}