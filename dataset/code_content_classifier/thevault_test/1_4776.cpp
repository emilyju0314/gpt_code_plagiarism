MemRefDescriptor
MemRefDescriptor::fromStaticShape(OpBuilder &builder, Location loc,
                                  LLVMTypeConverter &typeConverter,
                                  MemRefType type, Value memory) {
  assert(type.hasStaticShape() && "unexpected dynamic shape");
  assert(type.getAffineMaps().empty() && "unexpected layout map");

  auto convertedType = typeConverter.convertType(type);
  assert(convertedType && "unexpected failure in memref type conversion");

  auto descr = MemRefDescriptor::undef(builder, loc, convertedType);
  descr.setAllocatedPtr(builder, loc, memory);
  descr.setAlignedPtr(builder, loc, memory);
  descr.setConstantOffset(builder, loc, 0);

  // Fill in sizes and strides, in reverse order to simplify stride
  // calculation.
  uint64_t runningStride = 1;
  for (unsigned i = type.getRank(); i > 0; --i) {
    unsigned dim = i - 1;
    descr.setConstantSize(builder, loc, dim, type.getDimSize(dim));
    descr.setConstantStride(builder, loc, dim, runningStride);
    runningStride *= type.getDimSize(dim);
  }
  return descr;
}