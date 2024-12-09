void Memory::Unmap(void)
{
    Pal::Result palResult = Pal::Result::Success;

    VK_ASSERT(m_multiInstance == false);

    palResult = PalMemory(m_primaryDeviceIndex)->Unmap();
    VK_ASSERT(palResult == Pal::Result::Success);
}