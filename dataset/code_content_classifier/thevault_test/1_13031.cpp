so_type::weak_pointer so_type_repo::addType(const so_type::shared_pointer& aTypeID) {
  so_type::weak_pointer r = findType(aTypeID);
  if((r.lock()) && (r.lock()->TypeVersion() > aTypeID->TypeVersion()))
    return r;

  return mTypeMap->addDescendant( aTypeID );
}