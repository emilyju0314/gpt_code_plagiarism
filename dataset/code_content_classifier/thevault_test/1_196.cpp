void Lock::Eject(EjectedReason reason) {
  if (owner_ != nullptr) {
    owner_->lock_ = nullptr;
    owner_->reason_ = reason;
    owner_ = nullptr;
  }
}