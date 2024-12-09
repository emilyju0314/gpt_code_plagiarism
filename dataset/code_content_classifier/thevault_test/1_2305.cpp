Err GetMemberType(const fxl::RefPtr<EvalContext>& context, const Collection* coll,
                  const DataMember* member, fxl::RefPtr<Type>* member_type, uint32_t* member_size) {
  if (!member)
    return GetErrorForInvalidMemberOf(coll);

  *member_type = RefPtrTo(member->type().Get()->AsType());
  if (!*member_type) {
    return Err("Bad type information for '%s.%s'.", coll->GetFullName().c_str(),
               member->GetAssignedName().c_str());
  }

  return Err();
}