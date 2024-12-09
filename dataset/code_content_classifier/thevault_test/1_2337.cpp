uint32_t UnsafeInlineSize(const fidl_type_t* type, WireFormat wire_format) {
  assert(type);

  switch (type->type_tag) {
    case kFidlTypePrimitive:
      return PrimitiveSize(type->coded_primitive);
    case kFidlTypeEnum:
      return PrimitiveSize(type->coded_enum.underlying_type);
    case kFidlTypeBits:
      return PrimitiveSize(type->coded_bits.underlying_type);
    case kFidlTypeStructPointer:
      return 8;
    case kFidlTypeUnionPointer:
      assert(wire_format == WireFormat::kOld);
      return 8;
    case kFidlTypeVector:
    case kFidlTypeString:
      return 16;
    case kFidlTypeStruct:
      return type->coded_struct.size;
    case kFidlTypeUnion:
      assert(wire_format == WireFormat::kOld);
      return type->coded_union.size;
    case kFidlTypeArray:
      return type->coded_array.array_size;
    case kFidlTypeXUnion:
      return 24;
    case kFidlTypeHandle:
      return 4;
    case kFidlTypeTable:
      return 16;
  }

  // This is needed to suppress a GCC warning "control reaches end of non-void function", since GCC
  // treats switch() on enums as non-exhaustive without a default case.
  assert(false && "unexpected non-exhaustive switch on FidlTypeTag");
  return 0;
}