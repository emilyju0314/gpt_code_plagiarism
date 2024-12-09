TLObjectPtr FrontendServerHandler::On_TL_destroy_session(TLObjectPtr msg) {
  LOG(INFO) << "On_TL_destroy_session - " << msg->ToString();
  // r = On_TL_destroy_session(ctx, msg);
  auto destroy_session = std::static_pointer_cast<TL_destroy_session>(msg);
  auto destroy_session_ok = std::make_shared<TL_destroy_session_ok>();
  destroy_session_ok->set_session_id(destroy_session->session_id());
  return destroy_session_ok;
}