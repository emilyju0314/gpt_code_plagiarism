static void
addNonMemberVarDeclAddressorComponent(SILGenModule &SGM, VarDecl *var,
                                      CanType formalRValueType,
                                      LValue &lvalue) {
  assert(!lvalue.isValid());
  auto typeData = getPhysicalStorageTypeData(SGM, var, formalRValueType);
  SILType storageType = SGM.Types.getLoweredType(var->getType()).getAddressType();
  lvalue.add<AddressorComponent>(var, /*isSuper=*/ false, /*direct*/ true,
                                 SGM.getNonMemberVarDeclSubstitutions(var),
                                 CanType(), typeData, storageType);
}