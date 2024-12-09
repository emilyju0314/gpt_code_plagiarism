bool TessdataManager::GetComponent(TessdataType type, TFile *fp) {
  if (!is_loaded_ && !Init(data_file_name_.c_str())) {
    return false;
  }
  const TessdataManager *const_this = this;
  return const_this->GetComponent(type, fp);
}