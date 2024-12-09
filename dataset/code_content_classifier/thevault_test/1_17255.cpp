CacheAccessor::CacheAccessor(Context *context, MetroHash::Hash &cacheHash, CachePair internalCaches) {
  assert(context);
  if (context->isGraphics()) {
    const auto *pipelineInfo = reinterpret_cast<const GraphicsPipelineBuildInfo *>(context->getPipelineBuildInfo());
    initializeUsingBuildInfo(pipelineInfo, cacheHash, internalCaches);
  } else {
    const auto *pipelineInfo = reinterpret_cast<const ComputePipelineBuildInfo *>(context->getPipelineBuildInfo());
    initializeUsingBuildInfo(pipelineInfo, cacheHash, internalCaches);
  }
}