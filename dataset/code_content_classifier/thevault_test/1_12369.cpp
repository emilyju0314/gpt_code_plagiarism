void* AZ::OperatorNewArray([[maybe_unused]] std::size_t size, [[maybe_unused]] std::align_val_t align)
{
#if defined(AZ_NEW_DELETE_SUPPORT_ARRAYS)
    //AZ_Warning("Memory",false,"You should use aznew instead of new! It has better tracking and guarantees you will call the SystemAllocator always!");
    return AllocatorInstance<SystemAllocator>::Get().Allocate(size, static_cast<size_t>(align), 0, "global operator new[]", nullptr, 0);
#else
    AZ_Assert(false, "We DO NOT support array operators, because it's really hard/impossible to handle alignment without proper tracking!\n"
                    "new[] inserts a header (platform dependent) to keep track of the array size!\n"
                    "Use AZStd::vector,AZStd::array,AZStd::fixed_vector or placement new and it's your responsibility!");
    return AZ_INVALID_POINTER;
#endif
}