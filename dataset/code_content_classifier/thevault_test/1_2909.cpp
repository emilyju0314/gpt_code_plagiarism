Operand TurboAssembler::HeapObjectAsOperand(Handle<HeapObject> object) {
  DCHECK(root_array_available());

  int builtin_index;
  RootIndex root_index;
  if (isolate()->roots_table().IsRootHandle(object, &root_index)) {
    return Operand(kRootRegister, RootRegisterOffsetForRootIndex(root_index));
  } else if (isolate()->builtins()->IsBuiltinHandle(object, &builtin_index)) {
    return Operand(kRootRegister,
                   RootRegisterOffsetForBuiltinIndex(builtin_index));
  } else if (object.is_identical_to(code_object_) &&
             Builtins::IsBuiltinId(maybe_builtin_index_)) {
    return Operand(kRootRegister,
                   RootRegisterOffsetForBuiltinIndex(maybe_builtin_index_));
  } else {
    // Objects in the constants table need an additional indirection, which
    // cannot be represented as a single Operand.
    UNREACHABLE();
  }
}