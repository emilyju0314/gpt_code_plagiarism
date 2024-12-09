bool UtilityPointerIsValid(void* Pointer)
{
#if PLATFORM_32BITS
	return (Pointer != nullptr && Pointer != (void*)0xdddddddd);
#else
	return (Pointer != nullptr && Pointer != (void*)0xdddddddddddddddd);
#endif
}