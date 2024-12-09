bool os_detect_blob(BLOBNBOX *bbox, OrientationDetector *o, ScriptDetector *s, OSResults *osr,
                    tesseract::Tesseract *tess) {
  tess->tess_cn_matching.set_value(true); // turn it on
  tess->tess_bn_matching.set_value(false);
  C_BLOB *blob = bbox->cblob();
  TBLOB *tblob = TBLOB::PolygonalCopy(tess->poly_allow_detailed_fx, blob);
  TBOX box = tblob->bounding_box();
  FCOORD current_rotation(1.0f, 0.0f);
  FCOORD rotation90(0.0f, 1.0f);
  BLOB_CHOICE_LIST ratings[4];
  // Test the 4 orientations
  for (int i = 0; i < 4; ++i) {
    // Normalize the blob. Set the origin to the place we want to be the
    // bottom-middle after rotation.
    // Scaling is to make the rotated height the x-height.
    float scaling = static_cast<float>(kBlnXHeight) / box.height();
    float x_origin = (box.left() + box.right()) / 2.0f;
    float y_origin = (box.bottom() + box.top()) / 2.0f;
    if (i == 0 || i == 2) {
      // Rotation is 0 or 180.
      y_origin = i == 0 ? box.bottom() : box.top();
    } else {
      // Rotation is 90 or 270.
      scaling = static_cast<float>(kBlnXHeight) / box.width();
      x_origin = i == 1 ? box.left() : box.right();
    }
    std::unique_ptr<TBLOB> rotated_blob(new TBLOB(*tblob));
    rotated_blob->Normalize(nullptr, &current_rotation, nullptr, x_origin, y_origin, scaling,
                            scaling, 0.0f, static_cast<float>(kBlnBaselineOffset), false, nullptr);
    tess->AdaptiveClassifier(rotated_blob.get(), ratings + i);
    current_rotation.rotate(rotation90);
  }
  delete tblob;

  bool stop = o->detect_blob(ratings);
  s->detect_blob(ratings);
  int orientation = o->get_orientation();
  stop = s->must_stop(orientation) && stop;
  return stop;
}