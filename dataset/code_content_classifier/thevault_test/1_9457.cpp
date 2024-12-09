static U32 allocateThreadId(Emscripten::Process* process, Thread* thread)
{
	Platform::Mutex::Lock threadsLock(process->threadsMutex);
	thread->id = process->threads.add(0, thread);
	WAVM_ERROR_UNLESS(thread->id != 0);
	return thread->id;
}