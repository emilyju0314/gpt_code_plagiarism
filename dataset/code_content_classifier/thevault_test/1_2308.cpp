void DoResolveMember(const fxl::RefPtr<EvalContext>& context, const ExprValue& base,
                     const FoundMember& member, EvalCallback cb) {
  FXL_DCHECK(member.data_member());
  if (member.data_member()->is_external()) {
    // A forward-declared static member. In C++ static members can't be bitfields so we don't handle
    // them.
    return context->GetVariableValue(RefPtrTo(member.data_member()), std::move(cb));
  }

  // Normal nonstatic resolution is synchronous.
  cb(DoResolveNonstaticMember(context, base, member));
}