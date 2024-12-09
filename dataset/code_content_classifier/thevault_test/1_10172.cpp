std::string Shape_serializer::to_string (P_Shape* shape)
{
    return std::to_string(shape->length_) + delimeter_ +
           std::to_string(shape->width_)  + delimeter_ +
           std::to_string(shape->depth_)  + delimeter_ +
           Shapes::to_string(shape->shape_);
}