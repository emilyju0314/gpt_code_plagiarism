VkResult Memory::OpenExternalMemory(
    Device*                 pDevice,
    const ImportMemoryInfo& importInfo,
    Memory**                ppMemory)
{
    Pal::ExternalGpuMemoryOpenInfo openInfo = {};
    Pal::GpuMemoryCreateInfo createInfo = {};
    Pal::IGpuMemory* pGpuMemory[MaxPalDevices] = {};
    Pal::Result palResult;
    size_t gpuMemorySize;
    uint8_t *pSystemMem;

    VK_ASSERT(pDevice  != nullptr);
    VK_ASSERT(ppMemory != nullptr);

    const uint32_t allocationMask = (1 << DefaultMemoryInstanceIdx);
    const bool openedViaName      = (importInfo.handle == 0);

    if (openedViaName)
    {
    }
    else
    {
        openInfo.resourceInfo.hExternalResource = importInfo.handle;
    }

    openInfo.resourceInfo.flags.ntHandle    = importInfo.isNtHandle;
    // Get CPU memory requirements for PAL
    gpuMemorySize = pDevice->PalDevice(DefaultDeviceIndex)->GetExternalSharedGpuMemorySize(&palResult);
    VK_ASSERT(palResult == Pal::Result::Success);

    // Allocate enough for the PAL memory object and our own dispatchable memory
    pSystemMem = static_cast<uint8_t*>(pDevice->VkPhysicalDevice(DefaultDeviceIndex)->VkInstance()->AllocMem(
        gpuMemorySize + sizeof(Memory),
        VK_DEFAULT_MEM_ALIGN,
        VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));

    // Check for out of memory
    if (pSystemMem == nullptr)
    {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    // Allocate the PAL memory object
    palResult = pDevice->PalDevice(DefaultDeviceIndex)->OpenExternalSharedGpuMemory(openInfo,
                                                                  pSystemMem + sizeof(Memory),
                                                                  &createInfo,
                                                                  &pGpuMemory[DefaultDeviceIndex]);

    // On success...
    if (palResult == Pal::Result::Success)
    {
        // Add the GPU memory object to the residency list
        palResult = pDevice->AddMemReference(pDevice->PalDevice(DefaultDeviceIndex), pGpuMemory[DefaultDeviceIndex]);

        if (palResult == Pal::Result::Success)
        {
            // Initialize dispatchable memory object and return to application
            *ppMemory = VK_PLACEMENT_NEW(pSystemMem) Memory(pDevice,
                                                           pGpuMemory,
                                                           openInfo.resourceInfo.hExternalResource,
                                                           createInfo,
                                                           false,
                                                           DefaultDeviceIndex);
        }
        else
        {
            pGpuMemory[DefaultDeviceIndex]->Destroy();
        }
    }

    if (palResult != Pal::Result::Success)
    {
        // Construction of PAL memory object failed. Free the memory before returning to application.
        pDevice->VkPhysicalDevice(DefaultDeviceIndex)->VkInstance()->FreeMem(pSystemMem);
    }

    return PalToVkResult(palResult);
}