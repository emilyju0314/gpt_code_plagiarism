void SVMenuNode::BuildMenu(ScrollView *sv, bool menu_bar) {
  if ((parent_ != nullptr) && (menu_bar)) {
    if (is_check_box_entry_) {
      sv->MenuItem(parent_->text_.c_str(), text_.c_str(), cmd_event_, toggle_value_);
    } else {
      sv->MenuItem(parent_->text_.c_str(), text_.c_str(), cmd_event_);
    }
  } else if ((parent_ != nullptr) && (!menu_bar)) {
    if (description_.length() > 0) {
      sv->PopupItem(parent_->text_.c_str(), text_.c_str(), cmd_event_, value_.c_str(),
                    description_.c_str());
    } else {
      sv->PopupItem(parent_->text_.c_str(), text_.c_str());
    }
  }
  if (child_ != nullptr) {
    child_->BuildMenu(sv, menu_bar);
    delete child_;
  }
  if (next_ != nullptr) {
    next_->BuildMenu(sv, menu_bar);
    delete next_;
  }
}