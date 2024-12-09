void Memory::Free(
    Device*                         pDevice,
    const VkAllocationCallbacks*    pAllocator)
{
    if (m_pExternalPalImage != nullptr)
    {
        m_pExternalPalImage->Destroy();
        m_pExternalPalImage = nullptr;
    }

    for (uint32_t i = 0; i < m_pDevice->NumPalDevices(); ++i)
    {
        for (uint32_t j = 0; j < m_pDevice->NumPalDevices(); ++j)
        {
            // Free the child memory first
            if (i != j)
            {
                Pal::IGpuMemory* pGpuMemory = m_pPalMemory[i][j];
                if (pGpuMemory != nullptr)
                {
                    Pal::IDevice* pPalDevice = pDevice->PalDevice(i);
                    pDevice->RemoveMemReference(pPalDevice, pGpuMemory);

                    Pal::ResourceDestroyEventData data = {};
                    data.pObj = pGpuMemory;

                    pDevice->VkInstance()->PalPlatform()->LogEvent(
                        Pal::PalEvent::GpuMemoryResourceDestroy,
                        &data,
                        sizeof(Pal::ResourceDestroyEventData));

                    // Destroy PAL memory object
                    pGpuMemory->Destroy();

                    // the GpuMemory in [i,j] where i != j need to be freed explicitly.
                    pDevice->VkPhysicalDevice(DefaultDeviceIndex)->VkInstance()->FreeMem(pGpuMemory);
                }
            }
        }
    }

    // Free the parent memory
    for (uint32_t i = 0; i < m_pDevice->NumPalDevices(); ++i)
    {
        Pal::IGpuMemory* pGpuMemory = m_pPalMemory[i][i];
        if (pGpuMemory != nullptr)
        {
            Pal::IDevice* pPalDevice = pDevice->PalDevice(i);
            pDevice->RemoveMemReference(pPalDevice, pGpuMemory);

            // Destroy PAL memory object
            pGpuMemory->Destroy();
        }
    }

    // Decrease the allocation count
    if (m_allocationCounted)
    {
        m_pDevice->DecreaseAllocationCount();
    }

    // Decrease the allocation size
    if (m_sizeAccountedForDeviceMask != 0)
    {
        m_pDevice->DecreaseAllocatedMemorySize(m_info.size, m_sizeAccountedForDeviceMask, m_info.heaps[0]);
    }

    // Call destructor
    Util::Destructor(this);

    // Free outer container
    pAllocator->pfnFree(pAllocator->pUserData, this);
}