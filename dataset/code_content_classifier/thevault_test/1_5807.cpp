VkResult Memory::CreateGpuPinnedMemory(
    Device*                         pDevice,
    const VkAllocationCallbacks*    pAllocator,
    const Pal::GpuMemoryCreateInfo& createInfo,
    uint32_t                        allocationMask,
    bool                            multiInstanceHeap,
    bool                            isHostMappedForeign,
    void*                           pPinnedHostPtr,
    Memory**                        ppMemory)
{
    Pal::IGpuMemory* pGpuMemory[MaxPalDevices] = {};

    size_t   gpuMemorySize = 0;
    uint8_t *pSystemMem = nullptr;

    Pal::Result palResult;
    VkResult    vkResult = VK_SUCCESS;

    uint32_t primaryIndex  = 0;
    bool     multiInstance = false;

    GetPrimaryDeviceIndex(pDevice->NumPalDevices(), allocationMask, &primaryIndex, &multiInstance);

    // It is really confusing to see multiInstance pinned memory.
    // Assert has been added to catch the unexpected case.
    VK_ASSERT(!multiInstance);

    VK_ASSERT(ppMemory != nullptr);

    // Get CPU memory requirements for PAL
    Pal::PinnedGpuMemoryCreateInfo pinnedInfo = {};

    VK_ASSERT(Util::IsPow2Aligned(reinterpret_cast<uint64_t>(pPinnedHostPtr),
        pDevice->VkPhysicalDevice(DefaultDeviceIndex)->PalProperties().gpuMemoryProperties.realMemAllocGranularity));

    pinnedInfo.size      = static_cast<size_t>(createInfo.size);
    pinnedInfo.pSysMem   = pPinnedHostPtr;
    pinnedInfo.vaRange   = Pal::VaRange::Default;
    pinnedInfo.alignment = createInfo.alignment;
    gpuMemorySize = pDevice->PalDevice(DefaultDeviceIndex)->GetPinnedGpuMemorySize(
        pinnedInfo, &palResult);

    if (palResult != Pal::Result::Success)
    {
        vkResult = VK_ERROR_INVALID_EXTERNAL_HANDLE;
    }

    const size_t apiSize = sizeof(Memory);
    const size_t palSize = gpuMemorySize * pDevice->NumPalDevices();

    if (vkResult == VK_SUCCESS)
    {
        // Allocate enough for the PAL memory object and our own dispatchable memory
        pSystemMem = static_cast<uint8_t*>(
            pAllocator->pfnAllocation(
                pAllocator->pUserData,
                apiSize + palSize,
                VK_DEFAULT_MEM_ALIGN,
                VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));

        // Check for out of memory
        if (pSystemMem != nullptr)
        {
            size_t palMemOffset = apiSize;

            for (uint32_t deviceIdx = 0;
                (deviceIdx < pDevice->NumPalDevices()) && (palResult == Pal::Result::Success);
                 deviceIdx++)
            {
                if (((1 << deviceIdx) & allocationMask) != 0)
                {
                    Pal::IDevice* pPalDevice = pDevice->PalDevice(deviceIdx);

                    // Allocate the PAL memory object
                    palResult = pPalDevice->CreatePinnedGpuMemory(
                        pinnedInfo, Util::VoidPtrInc(pSystemMem, palMemOffset), &pGpuMemory[deviceIdx]);

                    if (palResult == Pal::Result::Success)
                    {
                        // Add the GPU memory object to the residency list
                        palResult = pDevice->AddMemReference(pPalDevice, pGpuMemory[deviceIdx]);

                        if (palResult != Pal::Result::Success)
                        {
                            pGpuMemory[deviceIdx]->Destroy();
                            pGpuMemory[deviceIdx] = nullptr;
                        }
                    }
                }

                palMemOffset += gpuMemorySize;
            }

            if (palResult == Pal::Result::Success)
            {
                // Initialize dispatchable memory object and return to application
                *ppMemory = VK_PLACEMENT_NEW(pSystemMem) Memory(pDevice,
                                                                pGpuMemory,
                                                                0,
                                                                createInfo,
                                                                multiInstance,
                                                                primaryIndex);
            }
            else
            {
                // Something went wrong, clean up
                for (int32_t deviceIdx = pDevice->NumPalDevices() - 1; deviceIdx >= 0; --deviceIdx)
                {
                    if (pGpuMemory[deviceIdx] != nullptr)
                    {
                        Pal::IDevice* pPalDevice = pDevice->PalDevice(deviceIdx);

                        pDevice->RemoveMemReference(pPalDevice, pGpuMemory[deviceIdx]);
                        pGpuMemory[deviceIdx]->Destroy();
                    }
                }

                pAllocator->pfnFree(pAllocator->pUserData, pSystemMem);

                vkResult = VK_ERROR_INVALID_EXTERNAL_HANDLE;
            }
        }
        else
        {
            vkResult = VK_ERROR_OUT_OF_HOST_MEMORY;
        }
    }

    return vkResult;
}