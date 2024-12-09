bool Tesseract::word_display(PAGE_RES_IT *pr_it) {
  WERD_RES *word_res = pr_it->word();
  WERD *word = word_res->word;
  TBOX word_bb;    // word bounding box
  int word_height; // ht of word BB
  bool displayed_something = false;
  float shift; // from bot left

  if (color_mode != CM_RAINBOW && word_res->box_word != nullptr) {
#  ifndef DISABLED_LEGACY_ENGINE
    BoxWord *box_word = word_res->box_word;
    WERD_CHOICE *best_choice = word_res->best_choice;
    int length = box_word->length();
    if (word_res->fontinfo == nullptr) {
      return false;
    }
    const FontInfo &font_info = *word_res->fontinfo;
    for (int i = 0; i < length; ++i) {
      ScrollView::Color color = ScrollView::GREEN;
      switch (color_mode) {
        case CM_SUBSCRIPT:
          if (best_choice->BlobPosition(i) == SP_SUBSCRIPT) {
            color = ScrollView::RED;
          }
          break;
        case CM_SUPERSCRIPT:
          if (best_choice->BlobPosition(i) == SP_SUPERSCRIPT) {
            color = ScrollView::RED;
          }
          break;
        case CM_ITALIC:
          if (font_info.is_italic()) {
            color = ScrollView::RED;
          }
          break;
        case CM_BOLD:
          if (font_info.is_bold()) {
            color = ScrollView::RED;
          }
          break;
        case CM_FIXEDPITCH:
          if (font_info.is_fixed_pitch()) {
            color = ScrollView::RED;
          }
          break;
        case CM_SERIF:
          if (font_info.is_serif()) {
            color = ScrollView::RED;
          }
          break;
        case CM_SMALLCAPS:
          if (word_res->small_caps) {
            color = ScrollView::RED;
          }
          break;
        case CM_DROPCAPS:
          if (best_choice->BlobPosition(i) == SP_DROPCAP) {
            color = ScrollView::RED;
          }
          break;
          // TODO(rays) underline is currently completely unsupported.
        case CM_UNDERLINE:
        default:
          break;
      }
      image_win->Pen(color);
      TBOX box = box_word->BlobBox(i);
      image_win->Rectangle(box.left(), box.bottom(), box.right(), box.top());
    }
    return true;
#  else
    return false;
#  endif // ndef DISABLED_LEGACY_ENGINE
  }
  /*
  Note the double coercions of(COLOUR)((int32_t)editor_image_word_bb_color)
  etc. are to keep the compiler happy.
*/
  // display bounding box
  if (word->display_flag(DF_BOX)) {
    word->bounding_box().plot(image_win,
                              static_cast<ScrollView::Color>((int32_t)editor_image_word_bb_color),
                              static_cast<ScrollView::Color>((int32_t)editor_image_word_bb_color));

    auto c = static_cast<ScrollView::Color>((int32_t)editor_image_blob_bb_color);
    image_win->Pen(c);
    // cblob iterator
    C_BLOB_IT c_it(word->cblob_list());
    for (c_it.mark_cycle_pt(); !c_it.cycled_list(); c_it.forward()) {
      c_it.data()->bounding_box().plot(image_win);
    }
    displayed_something = true;
  }

  // display edge steps
  if (word->display_flag(DF_EDGE_STEP)) { // edgesteps available
    word->plot(image_win);                // rainbow colors
    displayed_something = true;
  }

  // display poly approx
  if (word->display_flag(DF_POLYGONAL)) {
    // need to convert
    TWERD *tword = TWERD::PolygonalCopy(poly_allow_detailed_fx, word);
    tword->plot(image_win);
    delete tword;
    displayed_something = true;
  }

  // Display correct text and blamer information.
  std::string text;
  std::string blame;
  if (word->display_flag(DF_TEXT) && word->text() != nullptr) {
    text = word->text();
  }
  if (word->display_flag(DF_BLAMER) &&
      !(word_res->blamer_bundle != nullptr &&
        word_res->blamer_bundle->incorrect_result_reason() == IRR_CORRECT)) {
    text = "";
    const BlamerBundle *blamer_bundle = word_res->blamer_bundle;
    if (blamer_bundle == nullptr) {
      text += "NULL";
    } else {
      text = blamer_bundle->TruthString();
    }
    text += " -> ";
    std::string best_choice_str;
    if (word_res->best_choice == nullptr) {
      best_choice_str = "NULL";
    } else {
      word_res->best_choice->string_and_lengths(&best_choice_str, nullptr);
    }
    text += best_choice_str;
    IncorrectResultReason reason =
        (blamer_bundle == nullptr) ? IRR_PAGE_LAYOUT : blamer_bundle->incorrect_result_reason();
    ASSERT_HOST(reason < IRR_NUM_REASONS);
    blame += " [";
    blame += BlamerBundle::IncorrectReasonName(reason);
    blame += "]";
  }
  if (text.length() > 0) {
    word_bb = word->bounding_box();
    image_win->Pen(ScrollView::RED);
    word_height = word_bb.height();
    int text_height = 0.50 * word_height;
    if (text_height > 20) {
      text_height = 20;
    }
    image_win->TextAttributes("Arial", text_height, false, false, false);
    shift = (word_height < word_bb.width()) ? 0.25 * word_height : 0.0f;
    image_win->Text(word_bb.left() + shift, word_bb.bottom() + 0.25 * word_height, text.c_str());
    if (blame.length() > 0) {
      image_win->Text(word_bb.left() + shift, word_bb.bottom() + 0.25 * word_height - text_height,
                      blame.c_str());
    }

    displayed_something = true;
  }

  if (!displayed_something) { // display BBox anyway
    word->bounding_box().plot(image_win,
                              static_cast<ScrollView::Color>((int32_t)editor_image_word_bb_color),
                              static_cast<ScrollView::Color>((int32_t)editor_image_word_bb_color));
  }
  return true;
}