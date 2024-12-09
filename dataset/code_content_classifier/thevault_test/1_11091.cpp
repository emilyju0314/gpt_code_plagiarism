void EvaluateParagraphDetection(const TextAndModel *correct, int n,
                                const std::vector<PARA *> &detector_output) {
  int incorrect_breaks = 0;
  int missed_breaks = 0;
  int poorly_matched_models = 0;
  int bad_crowns = 0;
  int bad_list_items = 0;
  ASSERT_EQ(detector_output.size(), n);
  for (int i = 1; i < n; i++) {
    bool has_break = correct[i].model_type != PCONT;
    bool detected_break = (detector_output[i - 1] != detector_output[i]);
    if (has_break && !detected_break) {
      missed_breaks++;
    }
    if (detected_break && !has_break) {
      incorrect_breaks++;
    }
    if (has_break) {
      if (correct[i].model_type == PNONE) {
        if (detector_output[i]->model != nullptr) {
          poorly_matched_models++;
        }
      } else {
        if (correct[i].model.justification() != kUnknown &&
            (detector_output[i]->model == nullptr ||
             !correct[i].model.Comparable(*detector_output[i]->model))) {
          poorly_matched_models++;
        }
      }
      if (correct[i].is_very_first_or_continuation ^
          detector_output[i]->is_very_first_or_continuation) {
        bad_crowns++;
      }
      if (correct[i].is_list_item ^ detector_output[i]->is_list_item) {
        bad_list_items++;
      }
    }
  }
  EXPECT_EQ(incorrect_breaks, 0);
  EXPECT_EQ(missed_breaks, 0);
  EXPECT_EQ(poorly_matched_models, 0);
  EXPECT_EQ(bad_list_items, 0);
  EXPECT_EQ(bad_crowns, 0);
  if (incorrect_breaks || missed_breaks || poorly_matched_models || bad_list_items || bad_crowns) {
    std::vector<std::string> dbg_lines;
    dbg_lines.emplace_back("# ==========================");
    dbg_lines.emplace_back("# Correct paragraph breaks:");
    dbg_lines.emplace_back("# ==========================");
    for (int i = 0; i < n; i++) {
      if (correct[i].model_type != PCONT) {
        std::string s = std::string(correct[i].ascii) + "  #  " +
                        correct[i].model.ToString() +
                        (correct[i].is_very_first_or_continuation ? " crown" : "") +
                        (correct[i].is_list_item ? " li" : "");
        dbg_lines.push_back(s);
      } else {
        dbg_lines.emplace_back(correct[i].ascii);
      }
    }
    dbg_lines.emplace_back("");
    dbg_lines.emplace_back("# ==========================");
    dbg_lines.emplace_back("# Paragraph detector output:");
    dbg_lines.emplace_back("# ==========================");
    for (int i = 0; i < n; i++) {
      std::string annotation;
      if (i == 0 || (detector_output[i - 1] != detector_output[i])) {
        if (detector_output[i] && detector_output[i]->model) {
          annotation +=
              "  #  " + detector_output[i]->model->ToString() +
              (detector_output[i]->is_very_first_or_continuation ? " crown" : "") +
              (detector_output[i]->is_list_item ? " li" : "");
        } else {
          annotation = "  #  Unmodeled paragraph.";
        }
      }
      std::string s = correct[i].ascii + annotation;
      dbg_lines.push_back(s);
    }
    std::string s;
    for (auto &dbg_line : dbg_lines) {
      s += dbg_line + "\n";
    }
    LOG(INFO) << "Discrepancy!\n" << s;
  }
}