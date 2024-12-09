Pal::OsExternalHandle Memory::GetShareHandle(
    VkExternalMemoryHandleTypeFlagBits handleType)
{
#if DEBUG
    bool condition = m_pDevice->IsExtensionEnabled(DeviceExtensions::KHR_EXTERNAL_MEMORY_FD);

    condition |= m_pDevice->VkPhysicalDevice(DefaultDeviceIndex)->GetEnabledAPIVersion() >= VK_MAKE_VERSION(1, 1, 0);
    VK_ASSERT(condition);
#endif

    Pal::OsExternalHandle handle = 0;

    Pal::GpuMemoryExportInfo exportInfo = {};
    handle = PalMemory(DefaultDeviceIndex)->ExportExternalHandle(exportInfo);

    return handle;
}