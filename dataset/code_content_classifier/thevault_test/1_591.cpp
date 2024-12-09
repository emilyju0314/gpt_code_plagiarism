void BindingSection::finalizeContents() {
  raw_svector_ostream os{contents};
  Binding lastBinding;
  int16_t lastOrdinal = 0;

  for (auto &p : sortBindings(bindingsMap)) {
    const DylibSymbol *sym = p.first;
    std::vector<BindingEntry> &bindings = p.second;
    uint8_t flags = BIND_OPCODE_SET_SYMBOL_TRAILING_FLAGS_IMM;
    if (sym->isWeakRef())
      flags |= BIND_SYMBOL_FLAGS_WEAK_IMPORT;
    os << flags << sym->getName() << '\0'
       << static_cast<uint8_t>(BIND_OPCODE_SET_TYPE_IMM | BIND_TYPE_POINTER);
    int16_t ordinal = ordinalForDylibSymbol(*sym);
    if (ordinal != lastOrdinal) {
      encodeDylibOrdinal(ordinal, os);
      lastOrdinal = ordinal;
    }
    std::vector<BindIR> opcodes;
    for (const BindingEntry &b : bindings)
      encodeBinding(b.target.isec->parent,
                    b.target.isec->getOffset(b.target.offset), b.addend,
                    lastBinding, opcodes);
    if (config->optimize > 1)
      optimizeOpcodes(opcodes);
    for (const auto &op : opcodes)
      flushOpcodes(op, os);
  }
  if (!bindingsMap.empty())
    os << static_cast<uint8_t>(BIND_OPCODE_DONE);
}