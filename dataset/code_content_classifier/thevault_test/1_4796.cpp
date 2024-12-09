static int loading_thread_proc(void *user_data) {
	ThreadParams *params = (ThreadParams *)user_data;
	Task *task = new Task();
	task->script_instance = params->script_instance;
	task->ref = params->ref;
	task->listener = params->listener;
	task->width = 0;
	task->height = 0;
	task->channels = 0;
	task->desired_channels = params->desired_channels;
	task->buffer = 0;

	load_image(params->contents, params->content_length, params->filename, &task->width, &task->height, &task->channels, params->desired_channels, params->info, params->no_vertical_flip, &task->buffer);
	delete params;

	tasks.push(task);
	return 0;
}