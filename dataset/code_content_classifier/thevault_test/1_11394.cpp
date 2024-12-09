int CNPC_ShadowWalker::SelectScheduleWander()
{
	m_bWanderToggle = !m_bWanderToggle;
	if (m_bWanderToggle) {
		return SCHED_IDLE_WANDER;
	}
	else {
		return SCHED_NONE;
	}
}