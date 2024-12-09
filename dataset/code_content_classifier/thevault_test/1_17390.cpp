Cube::Cube(int id) : ShapeBase(id) {
  auto& shapes_list = *shapes_list_ptr_;
  auto& shape = shapes_list[0];

  // Type of marker we want to display
  shape.type = visualization_msgs::msg::Marker::CUBE;
}