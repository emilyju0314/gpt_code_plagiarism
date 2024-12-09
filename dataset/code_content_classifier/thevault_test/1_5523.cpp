common::Status CopyOutputsAcrossDevices(const SessionState& session_state,
                                        std::vector<MLValue>& fetches,
                                        std::vector<MLValue>& user_fetches) {
  auto& execution_providers = session_state.GetExecutionProviders();

  for (size_t idx = 0, end = fetches.size(); idx < end; ++idx) {
    auto& fetched_mlvalue = fetches[idx];
    if (!fetched_mlvalue.IsTensor()) {
      user_fetches[idx] = fetched_mlvalue;
      continue;
    }

    auto& fetched_tensor = fetched_mlvalue.Get<Tensor>();
    auto& fetched_tensor_location = fetched_tensor.Location();
    auto* p_fetched_provider = execution_providers.Get(fetched_tensor_location);
    if (!p_fetched_provider) {
      p_fetched_provider = execution_providers.Get(onnxruntime::kCpuExecutionProvider);
      ORT_ENFORCE(p_fetched_provider);
    }

    auto fetched_provider_type = p_fetched_provider->Type();
    auto& output_mlvalue = user_fetches[idx];

    if (!output_mlvalue.IsAllocated()) {
      if (fetched_provider_type != onnxruntime::kCpuExecutionProvider) {
        ORT_RETURN_IF_ERROR(utils::AllocateHelper(*execution_providers.Get(onnxruntime::kCpuExecutionProvider),
                                                  0,
                                                  fetched_tensor,
                                                  output_mlvalue));
      } else {
        user_fetches[idx] = fetched_mlvalue;
        continue;
      }
    }

    Tensor* p_output_tensor = output_mlvalue.GetMutable<Tensor>();
    auto& output_tensor_loc = p_output_tensor->Location();
    auto* p_output_provider = execution_providers.Get(output_tensor_loc);
    if (!p_output_provider) {
      p_output_provider = execution_providers.Get(onnxruntime::kCpuExecutionProvider);
      ORT_ENFORCE(p_output_provider);
    }

    auto output_provider_type = p_output_provider->Type();

    if (output_provider_type == fetched_provider_type || fetched_tensor_location.mem_type == OrtMemTypeCPUOutput) {
      user_fetches[idx] = fetched_mlvalue;
      continue;
    }

    // our CPU exec provider doesn't support copy from GPU->CPU
    if (fetched_provider_type != onnxruntime::kCpuExecutionProvider) {
      ORT_RETURN_IF_ERROR(p_fetched_provider->CopyTensor(fetched_tensor, *p_output_tensor));
    } else if (output_provider_type != onnxruntime::kCpuExecutionProvider) {
      ORT_RETURN_IF_ERROR(p_output_provider->CopyTensor(fetched_tensor, *p_output_tensor));
    } else {
      //both tensors are on CPU.
      return Status(common::ONNXRUNTIME, common::FAIL, "can't copy a tensor from CPU to CPU");
    }
  }

  return Status::OK();
}