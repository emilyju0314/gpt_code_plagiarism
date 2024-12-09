void DoResolveMemberByPointer(const fxl::RefPtr<EvalContext>& context, const ExprValue& base_ptr,
                              const Collection* pointed_to_type, const FoundMember& member,
                              EvalCallback cb) {
  if (Err err = base_ptr.EnsureSizeIs(kTargetPointerSize); err.has_error())
    return cb(err);

  if (member.data_member()->is_bitfield()) {
    // The bitfield case is complicated. Get the full pointed-to collection value and then resolve
    // the member access using "." mode to re-use the non-pointer codepath. This avoids duplicating
    // the bitfield logic. (This is actually valid logic for every case but fetches unnecessary
    // memory which we avoid in the common case below).
    ResolvePointer(context, base_ptr,
                   [context, member, cb = std::move(cb)](ErrOrValue value) mutable {
                     if (value.has_error())
                       return cb(std::move(value));
                     cb(ResolveBitfieldMember(context, value.value(), member));
                   });
  } else {
    // Common case for non-bitfield members. We can avoid fetching the entire structure (which can
    // be very large in some edge cases) and just get fetch the memory for the item we need.
    fxl::RefPtr<Type> member_type;
    uint32_t member_size = 0;
    Err err =
        GetMemberType(context, pointed_to_type, member.data_member(), &member_type, &member_size);
    if (err.has_error())
      return cb(err);

    TargetPointer base_address = base_ptr.GetAs<TargetPointer>();
    ResolvePointer(context, base_address + member.data_member_offset(), std::move(member_type),
                   std::move(cb));
  }
}