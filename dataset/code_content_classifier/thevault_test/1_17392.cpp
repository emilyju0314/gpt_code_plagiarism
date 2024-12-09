auto ShapeBase::move_to_imple(XAxis const x, YAxis const y, ZAxis const z)
    -> void {
  shapes_list_ptr_->at(0).pose.position.x = x.get_value();
  shapes_list_ptr_->at(0).pose.position.y = y.get_value();
  shapes_list_ptr_->at(0).pose.position.z = z.get_value();
}