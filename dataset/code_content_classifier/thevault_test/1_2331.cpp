std::optional<VolumeCurve> SelectVolumeCurve(std::optional<VolumeCurve> curve_a,
                                             std::optional<VolumeCurve> curve_b) {
  FX_DCHECK(!(curve_a.has_value() && curve_b.has_value()))
      << "Two objects with a gain curve cannot be linked.";

  if (curve_a.has_value()) {
    return curve_a;
  }

  return curve_b;
}