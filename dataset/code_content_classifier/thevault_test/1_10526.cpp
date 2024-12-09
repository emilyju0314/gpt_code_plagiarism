void Tesseract::blob_feature_display(PAGE_RES *page_res, const TBOX &selection_box) {
#  ifndef DISABLED_LEGACY_ENGINE
  PAGE_RES_IT *it = make_pseudo_word(page_res, selection_box);
  if (it != nullptr) {
    WERD_RES *word_res = it->word();
    word_res->x_height = it->row()->row->x_height();
    word_res->SetupForRecognition(unicharset, this, BestPix(), tessedit_ocr_engine_mode, nullptr,
                                  classify_bln_numeric_mode, textord_use_cjk_fp_model,
                                  poly_allow_detailed_fx, it->row()->row, it->block()->block);
    TWERD *bln_word = word_res->chopped_word;
    TBLOB *bln_blob = bln_word->blobs[0];
    INT_FX_RESULT_STRUCT fx_info;
    std::vector<INT_FEATURE_STRUCT> bl_features;
    std::vector<INT_FEATURE_STRUCT> cn_features;
    Classify::ExtractFeatures(*bln_blob, classify_nonlinear_norm, &bl_features, &cn_features,
                              &fx_info, nullptr);
    // Display baseline features.
    ScrollView *bl_win = CreateFeatureSpaceWindow("BL Features", 512, 0);
    ClearFeatureSpaceWindow(baseline, bl_win);
    for (auto &bl_feature : bl_features) {
      RenderIntFeature(bl_win, &bl_feature, ScrollView::GREEN);
    }
    bl_win->Update();
    // Display cn features.
    ScrollView *cn_win = CreateFeatureSpaceWindow("CN Features", 512, 0);
    ClearFeatureSpaceWindow(character, cn_win);
    for (auto &cn_feature : cn_features) {
      RenderIntFeature(cn_win, &cn_feature, ScrollView::GREEN);
    }
    cn_win->Update();

    it->DeleteCurrentWord();
    delete it;
  }
#  endif // ndef DISABLED_LEGACY_ENGINE
}