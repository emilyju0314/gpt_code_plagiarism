void TBLOB::Normalize(const BLOCK *block, const FCOORD *rotation, const DENORM *predecessor,
                      float x_origin, float y_origin, float x_scale, float y_scale,
                      float final_xshift, float final_yshift, bool inverse, Image pix) {
  denorm_.SetupNormalization(block, rotation, predecessor, x_origin, y_origin, x_scale, y_scale,
                             final_xshift, final_yshift);
  denorm_.set_inverse(inverse);
  denorm_.set_pix(pix);
  // TODO(rays) outline->Normalize is more accurate, but breaks tests due
  // the changes it makes. Reinstate this code with a retraining.
  // The reason this change is troublesome is that it normalizes for the
  // baseline value computed independently at each x-coord. If the baseline
  // is not horizontal, this introduces shear into the normalized blob, which
  // is useful on the rare occasions that the baseline is really curved, but
  // the baselines need to be stabilized the rest of the time.
#if 0
  for (TESSLINE* outline = outlines; outline != nullptr; outline = outline->next) {
    outline->Normalize(denorm_);
  }
#else
  denorm_.LocalNormBlob(this);
#endif
}