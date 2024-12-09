MemoryPriority MemoryPriority::FromVkMemoryPriority(
    float value)
{
    static_assert(
        (static_cast<uint32_t>(Pal::GpuMemPriority::Unused) == 0) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::VeryLow) == 1) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Low) == 2) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Normal) == 3) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::High) == 4) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::VeryHigh) == 5) &&
        (static_cast<uint32_t>(Pal::GpuMemPriority::Count) == 6) &&
        (static_cast<uint32_t>(Pal::GpuMemPriorityOffset::Count) == 8),
        "PAL GpuMemPriority or GpuMemPriorityOffset values changed. Consider to update strategy to convert"
        "VkMemoryPriority to compatible PAL priority/offset pair");

    // From Vulkan Spec, 0.0 <= value <= 1.0, and the granularity of the priorities is implementation-dependent.
    // One thing Spec forced is that if VkMemoryPriority not specified as default behavior, it is as if the
    // priority value is 0.5. Our strategy is that map 0.5 to GpuMemPriority::Normal-GpuMemPriorityOffset::Offset0,
    // which is consistent to MemoryPriorityDefault. We adopts GpuMemPriority::VeryLow, GpuMemPriority::Low,
    // GpuMemPriority::Normal, GpuMemPriority::High, 4 priority grades, each of which contains 8 steps of offests.
    // This maps [0.0-1.0) to totally 32 steps. Finally, 1.0 maps to GpuMemPriority::VeryHigh.
    VK_ASSERT((value >= 0.0f) && (value <= 1.0f));
    static constexpr uint32_t TotalMemoryPrioritySteps = 32;
    uint32_t uintValue = static_cast<uint32_t>(value * TotalMemoryPrioritySteps);

    MemoryPriority priority = {};
    priority.priority = ((uintValue / 8) + 1);
    priority.offset   = (uintValue % 8);
    return priority;
}