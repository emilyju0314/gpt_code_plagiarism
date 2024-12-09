Anvil::CommandBufferBase::~CommandBufferBase()
{
    anvil_assert(!m_recording_in_progress);

    if (m_command_buffer          != VK_NULL_HANDLE &&
        m_parent_command_pool_ptr != nullptr)
    {
        /* Physically free the command buffer we own */
        m_parent_command_pool_ptr->lock();
        lock();
        {
            Anvil::Vulkan::vkFreeCommandBuffers(m_device_ptr->get_device_vk(),
                                                m_parent_command_pool_ptr->get_command_pool(),
                                                1, /* commandBufferCount */
                                               &m_command_buffer);
        }
        unlock();
        m_parent_command_pool_ptr->unlock();

        m_command_buffer = VK_NULL_HANDLE;
    }

    #ifdef STORE_COMMAND_BUFFER_COMMANDS
    {
        clear_commands();
    }
    #endif
}