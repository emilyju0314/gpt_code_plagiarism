void Batcher::AddShadedTrapezium(const Vec3& top_left, const Vec3& bottom_left,
                                 const Vec3& bottom_right, const Vec3& top_right,
                                 const Color& color, std::unique_ptr<PickingUserData> user_data,
                                 ShadingDirection shading_direction) {
  std::array<Color, 4> colors;  // top_left, bottom_left, bottom_right, top_right.
  GetBoxGradientColors(color, &colors, shading_direction);
  Color picking_color = PickingId::ToColor(PickingType::kTriangle, user_data_.size(), batcher_id_);
  Triangle triangle_1{top_left, bottom_left, top_right};
  std::array<Color, 3> colors_1{colors[0], colors[1], colors[2]};
  AddTriangle(triangle_1, colors_1, picking_color, std::make_unique<PickingUserData>(*user_data));
  Triangle triangle_2{bottom_left, bottom_right, top_right};
  std::array<Color, 3> colors_2{colors[1], colors[2], colors[3]};
  AddTriangle(triangle_2, colors_2, picking_color, std::move(user_data));
}