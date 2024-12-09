Anvil::Buffer::~Buffer()
{
    /* Unregister the object */
    Anvil::ObjectTracker::get()->unregister_object(Anvil::ObjectType::BUFFER,
                                                   this);

    if (m_buffer                                   != VK_NULL_HANDLE &&
        m_create_info_ptr->get_parent_buffer_ptr() == nullptr)
    {
        lock();
        {
            Anvil::Vulkan::vkDestroyBuffer(m_device_ptr->get_device_vk(),
                                           m_buffer,
                                           nullptr /* pAllocator */);
        }
        unlock();

        m_buffer = VK_NULL_HANDLE;
    }
}