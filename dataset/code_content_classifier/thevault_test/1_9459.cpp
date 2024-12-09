static bool removeThreadById(Process* process,
							 emabi::pthread_t threadId,
							 IntrusiveSharedPtr<Thread>& outThread)
{
	Platform::Mutex::Lock threadsLock(process->threadsMutex);
	if(!validateThreadId(process, threadId)) { return false; }
	outThread = std::move(process->threads[threadId]);
	process->threads.removeOrFail(threadId);

	WAVM_ASSERT(outThread->id == threadId);
	outThread->id = 0;

	return true;
}