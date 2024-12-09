Operand TurboAssembler::ExternalReferenceAddressAsOperand(
    ExternalReference reference) {
  DCHECK(root_array_available());
  DCHECK(options().isolate_independent_code);
  return Operand(
      kRootRegister,
      RootRegisterOffsetForExternalReferenceTableEntry(isolate(), reference));
}