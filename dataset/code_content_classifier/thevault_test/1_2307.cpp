void DoResolveMemberNameByPointer(const fxl::RefPtr<EvalContext>& context,
                                  const ExprValue& base_ptr, const ParsedIdentifier& identifier,
                                  fit::callback<void(ErrOrValue, const FoundMember&)> cb) {
  fxl::RefPtr<Collection> coll;
  if (Err err = GetConcretePointedToCollection(context, base_ptr.type(), &coll); err.has_error())
    return cb(err, FoundMember());

  ErrOr<FoundMember> found = FindMemberWithErr(coll.get(), identifier);
  if (found.has_error())
    return cb(found.err(), FoundMember());

  // Dispatch to low-level version now that the member is found by name.
  DoResolveMemberByPointer(context, base_ptr, coll.get(), found.value(),
                           [cb = std::move(cb), found = found.value()](ErrOrValue value) mutable {
                             cb(std::move(value), found);
                           });
}