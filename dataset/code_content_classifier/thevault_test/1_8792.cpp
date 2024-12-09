void bbox_overlaps_parrots(CudaContext& ctx, const SSElement& attr,
                           const OperatorBase::in_list_t& ins,
                           OperatorBase::out_list_t& outs) {
  int mode, offset;
  bool aligned;
  SSAttrs(attr)
      .get<int>("mode", mode)
      .get<bool>("aligned", aligned)
      .get<int>("offset", offset)
      .done();

  const auto& bboxes1 = buildATensor(ctx, ins[0]);
  const auto& bboxes2 = buildATensor(ctx, ins[1]);
  auto ious = buildATensor(ctx, outs[0]);
  bbox_overlaps_cuda(bboxes1, bboxes2, ious, mode, aligned, offset);
}