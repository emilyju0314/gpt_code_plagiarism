void DumpVariableInfo(const ProcessSymbols* process_symbols, const Variable* variable,
                      OutputBuffer* out) {
  out->Append(Syntax::kHeading, "Variable: ");
  out->Append(Syntax::kVariable, variable->GetAssignedName());
  out->Append("\n");
  DumpTypeDescription(variable->type(), out);
  out->Append(fxl::StringPrintf("  DWARF tag: 0x%02x\n", static_cast<unsigned>(variable->tag())));

  DumpVariableLocation(variable->GetSymbolContext(process_symbols), variable->location(), out);
}