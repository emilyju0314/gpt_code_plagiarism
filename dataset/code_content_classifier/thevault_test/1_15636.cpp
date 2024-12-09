void print_on_exit(caf::scheduled_actor* self, const std::string& name)
{
	self->attach_functor(
		[=](const caf::error& reason)
	{
		WriteLog(self, name + " exited : " + caf::to_string(reason));
	}
	);
}