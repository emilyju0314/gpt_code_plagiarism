void producer(async_manual_reset_event_setter& signal)
{
	std::this_thread::sleep_for(2s);
	//value = some_long_running_computation();
	value = 42;

	// Publish the value by setting the event.
	signal.set();
}