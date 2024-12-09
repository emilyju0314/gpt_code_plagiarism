std::string Subscription_serializer::to_string (Subscription* entity) {
    return std::to_string(entity->id_) + entity->name + delimeter_ + entity->type + delimeter_ +
    entity->unit_title + delimeter_ + std::to_string(entity->max_unit_count) + delimeter_ +
    ( entity->effective_from == nullptr ? "" : entity->effective_from->to_string() ) + delimeter_ +
    ( entity->effective_to == nullptr ? "" : entity->effective_to->to_string() ) + delimeter_ +
    std::to_string(entity->hours);
}