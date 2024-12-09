Anvil::CommandBufferBase::CommandBufferBase(const Anvil::BaseDevice* in_device_ptr,
                                            Anvil::CommandPool*      in_parent_command_pool_ptr,
                                            Anvil::CommandBufferType in_type,
                                            bool                     in_mt_safe)
    :MTSafetySupportProvider        (in_mt_safe),
     DebugMarkerSupportProvider     (in_device_ptr,
                                     Anvil::ObjectType::COMMAND_BUFFER),
     CallbacksSupportProvider       (COMMAND_BUFFER_CALLBACK_ID_COUNT),
     m_command_buffer               (VK_NULL_HANDLE),
     m_device_mask                  (0),
     m_device_ptr                   (in_device_ptr),
     m_is_renderpass_active         (false),
     m_n_debug_label_regions_started(0),
     m_parent_command_pool_ptr      (in_parent_command_pool_ptr),
     m_recording_in_progress        (false),
     m_renderpass_device_mask       (0),
     m_type                         (in_type)
{
    anvil_assert(in_parent_command_pool_ptr != nullptr);
}