static std::tuple<CanType, CanGenericSignature, SubstitutionMap>
mapTypeOutOfOpenedExistentialContext(CanType t) {
  SmallVector<OpenedArchetypeType *, 4> openedTypes;
  t->getOpenedExistentials(openedTypes);

  ArrayRef<Type> openedTypesAsTypes(
    reinterpret_cast<const Type *>(openedTypes.data()),
    openedTypes.size());

  SmallVector<GenericTypeParamType *, 4> params;
  for (unsigned i : indices(openedTypes)) {
    params.push_back(GenericTypeParamType::get(0, i, t->getASTContext()));
  }
  
  auto mappedSig = GenericSignature::get(params, {});
  auto mappedSubs = SubstitutionMap::get(mappedSig, openedTypesAsTypes, {});

  auto mappedTy = t.subst(
    [&](SubstitutableType *t) -> Type {
      auto index = std::find(openedTypes.begin(), openedTypes.end(), t)
        - openedTypes.begin();
      assert(index != openedTypes.end() - openedTypes.begin());
      return params[index];
    },
    MakeAbstractConformanceForGenericType());

  return std::make_tuple(mappedTy->getCanonicalType(mappedSig),
                         mappedSig.getCanonicalSignature(), mappedSubs);
}