void Memory::ElevatePriority(
    MemoryPriority priority)
{
    // Update PAL memory object's priority using a double-checked lock if the current priority is lower than
    // the new given priority.
    if (m_priority < priority)
    {
        Util::MutexAuto lock(m_pDevice->GetMemoryMutex());

        if (m_priority < priority)
        {
            for (uint32_t deviceIdx = 0; deviceIdx < m_pDevice->NumPalDevices(); deviceIdx++)
            {
                if ((PalMemory(deviceIdx) != nullptr) &&
                    (PalMemory(deviceIdx)->SetPriority(priority.PalPriority(), priority.PalOffset()) ==
                        Pal::Result::Success))
                {
                    m_priority = priority;
                }
            }
        }
    }
}