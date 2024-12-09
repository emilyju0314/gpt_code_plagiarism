static int bb_ui_draw_measure(UIState *s, const char* value, const char* label, int bb_x, int bb_y,
                              NVGcolor valueColor, NVGcolor labelColor, int valueFontSize, int labelFontSize) {
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);

  //print value
  nvgFontFace(s->vg, "sans-semibold");
  nvgFontSize(s->vg, valueFontSize);
  nvgFillColor(s->vg, valueColor);
  nvgText(s->vg, bb_x, bb_y + (int)(valueFontSize), value, NULL);

  //print label
  nvgFontFace(s->vg, "sans-regular");
  nvgFontSize(s->vg, labelFontSize);
  nvgFillColor(s->vg, labelColor);
  nvgText(s->vg, bb_x, bb_y + (int)(valueFontSize) + (int)(labelFontSize), label, NULL);

  return (int)((valueFontSize + labelFontSize));
}