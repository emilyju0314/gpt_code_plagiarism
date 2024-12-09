void DrawingDemo::Update() {
  unsigned int i;
  agg::rendering_buffer rbuf((unsigned char *)ps_context_->data,
                             ps_context_->width,
                             ps_context_->height,
                             ps_context_->stride);
  // Setup agg and clear the framebuffer.
  // Use Native Client's bgra pixel format.
  agg::pixfmt_bgra32 pixf(rbuf);
  typedef agg::renderer_base<agg::pixfmt_bgra32> ren_base;
  ren_base ren(pixf);
  ren.clear(agg::rgba(0, 0, 0));
  agg::rasterizer_scanline_aa<> ras;
  agg::scanline_u8 sl;
  ras.reset();
  ras.gamma(agg::gamma_none());

  // Draw an array of filled circles with a cycling color spectrum.
  const double spectrum_violet = 380.0;
  const double spectrum_red = 780.0;
  static double outer_cycle = spectrum_violet;
  static double delta_outer_cycle = 0.4;
  double inner_cycle = outer_cycle;
  double delta_inner_cycle = 0.75;
  for (double y = 0.0; y <= ps_context_->height; y += 32.0) {
    for (double x = 0.0; x <= ps_context_->width; x += 32.0) {
      // Draw a small filled circle at x, y with radius 16
      // using inner_cycle as the fill color.
      agg::rgba color(inner_cycle, 1.0);
      agg::ellipse elp;
      elp.init(x, y, 16, 16, 80);
      ras.add_path(elp);
      agg::render_scanlines_aa_solid(ras, sl, ren, color);
      // Bounce color cycle between red & violet.
      inner_cycle += delta_inner_cycle;
      if ((inner_cycle > spectrum_red) || (inner_cycle < spectrum_violet)) {
        delta_inner_cycle = -delta_inner_cycle;
        inner_cycle += delta_inner_cycle;
      }
    }
  }
  // Bounce outer starting color between red & violet.
  outer_cycle += delta_outer_cycle;
  if ((outer_cycle > spectrum_red) || (outer_cycle < spectrum_violet)) {
    delta_outer_cycle = -delta_outer_cycle;
    outer_cycle += delta_outer_cycle;
  }

  // Draw a semi-translucent triangle over the background.
  // The triangle is drawn as an outline, using a pen width
  // of 24 pixels.  The call to close_polygon() ensures that
  // all three corners are cleanly mitered.
  agg::path_storage ps;
  agg::conv_stroke<agg::path_storage> pg(ps);
  pg.width(24.0);
  ps.remove_all();
  ps.move_to(96, 160);
  ps.line_to(384, 256);
  ps.line_to(192, 352);
  ps.line_to(96, 160);
  ps.close_polygon();
  ras.add_path(pg);
  agg::render_scanlines_aa_solid(ras, sl, ren, agg::rgba8(255, 255, 255, 160));
}