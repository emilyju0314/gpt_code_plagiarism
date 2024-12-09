void
IntTcpAgent::send_much(int force, int reason, int /*maxburst*/)
{
	if (!session_)
		createTcpSession();
	if (!force && delsnd_timer_.status() == TIMER_PENDING)
		return;
	if (overhead_ && !force) {
		delsnd_timer_.resched(Random::uniform(overhead_));
		return;
	}
	session_->send_much(this, force,reason);
}