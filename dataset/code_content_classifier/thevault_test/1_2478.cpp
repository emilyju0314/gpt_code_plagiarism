std::vector<EOS_INTEGER> SesameTables::returnTypes(unsigned const tableIndex) const {
  size_t const found = rtMap.count(tableIndex);
  std::vector<EOS_INTEGER> result;
  // note: map::operator[] is non-const only.
  if (found > 0)
    result = rtMap.find(tableIndex)->second;
  else {
    std::ostringstream msg;
    msg << "Requested tableIndex = " << tableIndex
        << ", does not not exist in the SesameTables object.  You must"
        << " assign a table index before attempting to access it." << std::endl;
    Insist(found > 0, msg.str());
  }
  return result;
}