bool CControlJump::is_on_the_ground()
{
	if (m_time_started == 0) return false;
	if (m_time_started + (m_jump_time*1000) > time()) return false;

	Fvector direction;
	direction.set(0.f, -1.f, 0.f);
	Fvector trace_from;
	m_object->Center(trace_from);

	collide::rq_result		l_rq;

	bool on_the_ground = false;
	if (Level().ObjectSpace.RayPick(trace_from, direction, m_trace_ground_range, collide::rqtStatic, l_rq, m_object)) {
		if (l_rq.range < m_trace_ground_range) on_the_ground = true;
	}
	return (on_the_ground);
}