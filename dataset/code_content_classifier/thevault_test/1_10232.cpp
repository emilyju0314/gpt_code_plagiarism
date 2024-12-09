void MessageListener(string* s, bool* changed) {
  if (!FLAGS_redaction_rules_file.empty()) {
    impala::Redact(s, changed);
  }
  PrependFragment(s, changed);
}