ErrOr<FoundMember> FindMemberWithErr(const fxl::RefPtr<EvalContext>& context, const ExprValue& base,
                                     const ParsedIdentifier& identifier) {
  fxl::RefPtr<Type> concrete_base = base.GetConcreteType(context.get());
  if (!concrete_base)
    return Err("No type information for collection.");
  return FindMemberWithErr(concrete_base->AsCollection(), identifier);
}