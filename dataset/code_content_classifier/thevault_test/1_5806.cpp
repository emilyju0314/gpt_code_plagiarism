VkResult Memory::CreateGpuMemory(
    Device*                         pDevice,
    const VkAllocationCallbacks*    pAllocator,
    const Pal::GpuMemoryCreateInfo& createInfo,
    const Pal::GpuMemoryExportInfo& exportInfo,
    uint32_t                        allocationMask,
    bool                            multiInstanceHeap,
    Memory**                        ppMemory)
{
    Pal::IGpuMemory* pGpuMemory[MaxPalDevices] = {};
    VK_ASSERT(allocationMask != 0);

    size_t   gpuMemorySize = 0;
    uint8_t *pSystemMem = nullptr;

    uint32_t primaryIndex = 0;
    bool multiInstance    = false;

    GetPrimaryDeviceIndex(pDevice->NumPalDevices(), allocationMask, &primaryIndex, &multiInstance);

    Pal::Result palResult;
    VkResult    vkResult = VK_SUCCESS;

    VK_ASSERT(ppMemory != nullptr);

    if (createInfo.size != 0)
    {
        gpuMemorySize = pDevice->PalDevice(DefaultDeviceIndex)->GetGpuMemorySize(createInfo, &palResult);
        VK_ASSERT(palResult == Pal::Result::Success);

        const size_t apiSize = sizeof(Memory);
        const size_t palSize = gpuMemorySize * pDevice->NumPalDevices();

        // Allocate enough for the PAL memory object and our own dispatchable memory
        pSystemMem = static_cast<uint8_t*>(
            pAllocator->pfnAllocation(
                pAllocator->pUserData,
                apiSize + palSize,
                VK_DEFAULT_MEM_ALIGN,
                VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));

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
                    palResult = pPalDevice->CreateGpuMemory(
                        createInfo, Util::VoidPtrInc(pSystemMem, palMemOffset), &pGpuMemory[deviceIdx]);

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
                Pal::OsExternalHandle handle = 0;

                // Initialize dispatchable memory object and return to application
                *ppMemory = VK_PLACEMENT_NEW(pSystemMem) Memory(pDevice,
                                                                pGpuMemory,
                                                                handle,
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

                if (palResult == Pal::Result::ErrorOutOfGpuMemory)
                {
                    vkResult = VK_ERROR_OUT_OF_DEVICE_MEMORY;
                }
                else
                {
                    vkResult = VK_ERROR_OUT_OF_HOST_MEMORY;
                }
            }
        }
        else
        {
            vkResult = VK_ERROR_OUT_OF_HOST_MEMORY;
        }
    }
    else
    {
        // Allocate memory only for the dispatchable object
        pSystemMem = static_cast<uint8_t*>(
            pAllocator->pfnAllocation(
                pAllocator->pUserData,
                sizeof(Memory),
                VK_DEFAULT_MEM_ALIGN,
                VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));

        if (pSystemMem != nullptr)
        {
            // Initialize dispatchable memory object and return to application
            Pal::IGpuMemory* pDummyPalGpuMemory[MaxPalDevices] = {};
            *ppMemory = VK_PLACEMENT_NEW(pSystemMem) Memory(pDevice,
                                                            pDummyPalGpuMemory,
                                                            0,
                                                            createInfo,
                                                            false,
                                                            DefaultDeviceIndex);
        }
        else
        {
            vkResult = VK_ERROR_OUT_OF_HOST_MEMORY;
        }
    }

    return vkResult;
}