MemoryPriority MemoryPriority::FromSetting(
    uint32_t value)
{
    static_assert(
        (static_cast<uint32_t>(Pal::GpuMemPriority::Unused)      == 0) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::VeryLow)     == 1) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Low)         == 2) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Normal)      == 3) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::High)        == 4) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::VeryHigh)    == 5) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Count)       == 6) &&
        (static_cast<uint32_t>(Pal::GpuMemPriorityOffset::Count) == 8),
        "PAL GpuMemPriority or GpuMemPriorityOffset values changed.  Update the panel setting description in "
        "settings.cfg for MemoryPriorityDefault");

    MemoryPriority priority = {};

    priority.priority = (value / 16);
    priority.offset   = (value % 16);

    return priority;
}