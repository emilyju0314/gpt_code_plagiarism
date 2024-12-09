static bool validateThreadId(Emscripten::Process* process, emabi::pthread_t threadId)
{
	WAVM_ASSERT_MUTEX_IS_LOCKED_BY_CURRENT_THREAD(process->threadsMutex);

	return threadId != 0 && process->threads.contains(threadId);
}