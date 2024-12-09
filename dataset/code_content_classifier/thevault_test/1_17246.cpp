Error ComputePipelineBuilder::build() {
  CompileInfo &compileInfo = getCompileInfo();

  Expected<BinaryData> pipelineOrErr = buildComputePipeline();
  if (Error err = pipelineOrErr.takeError())
    return err;

  Result result = decodePipelineBinary(&*pipelineOrErr, &compileInfo);
  if (result != Result::Success)
    return createResultError(result, "Failed to decode pipeline");

  return Error::success();
}