Anvil::DescriptorSetGroup::~DescriptorSetGroup()
{
    /* Unregister the object */
    Anvil::ObjectTracker::get()->unregister_object(Anvil::ObjectType::ANVIL_DESCRIPTOR_SET_GROUP,
                                                    this);
}