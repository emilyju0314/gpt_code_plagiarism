ShapeBase::ShapeBase(int id)
    : heading_{ZAxis{0.0}},
      parent_frame_name_{helper::local_frame_name("z0000000")},
      shapes_list_ptr_{
          std::make_shared<std::vector<visualization_msgs::msg::Marker>>()} {
  // Get a ref to the vector of marker for ease of use
  auto& shapes_list = *shapes_list_ptr_;
  // create a new marker
  shapes_list.emplace_back();
  // get a ref to the new marker.
  auto& shape = shapes_list[0];

  shape = create_shape_base(id, visualization_msgs::msg::Marker::CUBE);
}