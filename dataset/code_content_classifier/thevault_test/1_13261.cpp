AppActivity::AppActivity(extensions::ShellAppWindow* app_window)
    : app_window_(app_window),
      web_view_(NULL),
      current_state_(ACTIVITY_UNLOADED),
      app_activity_registry_(NULL) {
}