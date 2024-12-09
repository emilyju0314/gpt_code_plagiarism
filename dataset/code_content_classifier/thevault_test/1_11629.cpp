void IRGenModule::emitProtocolDecl(ProtocolDecl *protocol) {
  // Emit remote reflection metadata for the protocol.
  emitFieldMetadataRecord(protocol);

  // If the protocol is Objective-C-compatible, go through the path that
  // produces an ObjC-compatible protocol_t.
  if (protocol->isObjC()) {
    // In JIT mode, we need to create protocol descriptors using the ObjC
    // runtime in JITted code.
    if (IRGen.Opts.UseJIT)
      return;
    
    // Native ObjC protocols are emitted on-demand in ObjC and uniqued by the
    // runtime; we don't need to try to emit a unique descriptor symbol for them.
    if (protocol->hasClangNode())
      return;
    
    getObjCProtocolGlobalVars(protocol);
    return;
  }

  SILDefaultWitnessTable *defaultWitnesses = nullptr;
  if (!protocol->hasFixedLayout())
    defaultWitnesses = getSILModule().lookUpDefaultWitnessTable(protocol);

  ConstantInitBuilder initBuilder(*this);
  auto init = initBuilder.beginStruct();
  ProtocolDescriptorBuilder builder(*this, protocol, init, defaultWitnesses);
  builder.layout();

  auto var = cast<llvm::GlobalVariable>(
          getAddrOfProtocolDescriptor(protocol, init.finishAndCreateFuture()));
  var->setConstant(true);
}