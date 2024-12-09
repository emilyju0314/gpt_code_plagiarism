Termination_Detector::Termination_Detector(int const tag)
    : tag_(tag), number_of_processors_(nodes()), pid_(node()), parent_pid_((pid_ - 1) / 2),
      son_pid_(2 * pid_ + 1), daughter_pid_(son_pid_ + 1), ptype_(), state_(UP), send_count_(0),
      receive_count_(0), work_count_(0), subtree_send_count_(0), subtree_receive_count_(0),
      subtree_work_count_(0), old_global_work_count_(0) {
  if (pid_ == 0) {
    ptype_ = ROOT;
  } else {
    if (son_pid_ >= number_of_processors_ && daughter_pid_ >= number_of_processors_) {
      ptype_ = LEAF;
    } else {
      ptype_ = INTERNAL;
    }
  }
#ifdef PRINTF_DEBUG
  cout << pid_ << " constructed with tag " << tag_ << endl;
#endif
}