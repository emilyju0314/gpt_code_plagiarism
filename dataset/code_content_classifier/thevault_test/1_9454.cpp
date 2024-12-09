static IntrusiveSharedPtr<Thread> removeThreadById(Uptr threadId)
{
	IntrusiveSharedPtr<Thread> thread;

	Platform::Mutex::Lock threadsLock(threadsMutex);
	validateThreadId(threadId);
	thread = std::move(threads[threadId]);
	threads.removeOrFail(threadId);

	WAVM_ASSERT(thread->id == Uptr(threadId));
	thread->id = UINTPTR_MAX;

	return thread;
}