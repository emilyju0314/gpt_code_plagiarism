Pal::IGpuMemory* Memory::PalMemory(uint32_t resourceIndex, uint32_t memoryIndex)
{
    // if it is not m_multiInstance, each PalMemory in peer device is imported from m_primaryDeviceIndex.
    // We could always return the PalMemory with memory index m_primaryDeviceIndex.
    uint32_t index = m_multiInstance ? memoryIndex : m_primaryDeviceIndex;

    if (m_pPalMemory[resourceIndex][index] == nullptr)
    {
        // Instantiate the required PalMemory.
        Pal::IGpuMemory* pBaseMemory = nullptr;
        if (m_multiInstance)
        {
            // we need to import the memory from [memoryIndex][memoryIndex]
            VK_ASSERT(m_pPalMemory[index][index] != nullptr);
            pBaseMemory = m_pPalMemory[index][index];
        }
        else
        {
            // we need to import the memory from [m_primaryDeviceIndex][m_primaryDeviceIndex]
            VK_ASSERT(m_pPalMemory[m_primaryDeviceIndex][m_primaryDeviceIndex] != nullptr);
            pBaseMemory = m_pPalMemory[m_primaryDeviceIndex][m_primaryDeviceIndex];
        }

        Pal::PeerGpuMemoryOpenInfo peerMem   = {};
        Pal::GpuMemoryOpenInfo     sharedMem = {};

        Pal::Result palResult = Pal::Result::Success;

        // Call OpenSharedGpuMemory to construct Pal::GpuMemory for memory in remote heap.
        // Call OpenPeerGpuMemory to construct Pal::GpuMemory for memory in peer device's local heap.
        const bool openSharedMemory = (pBaseMemory->Desc().preferredHeap == Pal::GpuHeap::GpuHeapGartUswc) ||
                                      (pBaseMemory->Desc().preferredHeap == Pal::GpuHeap::GpuHeapGartCacheable);

        size_t gpuMemorySize = 0;
        if (openSharedMemory)
        {
            sharedMem.pSharedMem = pBaseMemory;
            gpuMemorySize        =  m_pDevice->PalDevice(resourceIndex)->GetSharedGpuMemorySize(sharedMem, &palResult);
        }
        else
        {
            peerMem.pOriginalMem = pBaseMemory;
            gpuMemorySize        = m_pDevice->PalDevice(resourceIndex)->GetPeerGpuMemorySize(peerMem, &palResult);
        }

        void* pPalMemory = static_cast<uint8_t*>(m_pDevice->VkPhysicalDevice(DefaultDeviceIndex)->VkInstance()->AllocMem(
                                        gpuMemorySize,
                                        VK_DEFAULT_MEM_ALIGN,
                                        VK_SYSTEM_ALLOCATION_SCOPE_OBJECT));

        VK_ASSERT(pPalMemory != nullptr);

        Pal::IDevice* pPalDevice = m_pDevice->PalDevice(resourceIndex);

        if (openSharedMemory)
        {
            palResult = pPalDevice->OpenSharedGpuMemory(sharedMem, pPalMemory, &m_pPalMemory[resourceIndex][index]);
        }
        else
        {
            palResult = pPalDevice->OpenPeerGpuMemory(peerMem, pPalMemory, &m_pPalMemory[resourceIndex][index]);
        }

        if (palResult == Pal::Result::Success)
        {
            // Add the GPU memory object to the residency list
            palResult =  m_pDevice->AddMemReference(pPalDevice, m_pPalMemory[resourceIndex][index]);

            if (palResult != Pal::Result::Success)
            {
                m_pPalMemory[resourceIndex][index]->Destroy();
                m_pPalMemory[resourceIndex][index] = nullptr;
            }
        }
        else
        {
            m_pDevice->VkPhysicalDevice(DefaultDeviceIndex)->VkInstance()->FreeMem(pPalMemory);
        }
    }

    VK_ASSERT(m_pPalMemory[resourceIndex][index] != nullptr);

    return m_pPalMemory[resourceIndex][index];
}