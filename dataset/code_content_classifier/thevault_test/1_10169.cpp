void Location_service::create_location (std::string name) const
{
    auto new_location = new Location;
    new_location->name = std::move(name);
    
    repository_.add(new_location);
}