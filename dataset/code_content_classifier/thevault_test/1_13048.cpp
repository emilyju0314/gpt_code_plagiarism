static void
sigint_handler(int signum)
{
	time_to_abort = true;
}