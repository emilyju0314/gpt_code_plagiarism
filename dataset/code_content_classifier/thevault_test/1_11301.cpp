void cancel_handler(int param) {
  console_cancel_handler::get_instance().set_cancel_flag(true);
  auto &c = get_cancelled_command();
  auto &r = get_running_command();
  c.store(r.load());
}