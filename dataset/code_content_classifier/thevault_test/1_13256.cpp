void GetKeyboardLayoutsForResolvedLocale(
    const GetKeyboardLayoutsForLocaleCallback& callback,
    const std::string& resolved_locale) {
  input_method::InputMethodUtil* util =
      input_method::InputMethodManager::Get()->GetInputMethodUtil();
  std::vector<std::string> layouts = util->GetHardwareInputMethodIds();
  std::vector<std::string> layouts_from_locale;
  util->GetInputMethodIdsFromLanguageCode(
      resolved_locale,
      input_method::kKeyboardLayoutsOnly,
      &layouts_from_locale);
  layouts.insert(layouts.end(), layouts_from_locale.begin(),
                 layouts_from_locale.end());

  std::string selected;
  if (!layouts_from_locale.empty()) {
    selected =
        util->GetInputMethodDescriptorFromId(layouts_from_locale[0])->id();
  }

  scoped_ptr<base::ListValue> input_methods_list(new base::ListValue);
  std::set<std::string> input_methods_added;
  for (std::vector<std::string>::const_iterator it = layouts.begin();
       it != layouts.end(); ++it) {
    const input_method::InputMethodDescriptor* ime =
        util->GetInputMethodDescriptorFromId(*it);
    if (!InsertString(ime->id(), input_methods_added))
      continue;
    input_methods_list->Append(
        CreateInputMethodsEntry(*ime, selected).release());
  }

  callback.Run(input_methods_list.Pass());
}