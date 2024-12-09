void ClampVelocity(Ship *s) {
	if (s->vx > g_max_velocity) s->vx = g_max_velocity;
	if (s->vy > g_max_velocity) s->vy = g_max_velocity;
			
	if (s->vx < -g_max_velocity) s->vx = -g_max_velocity;
	if (s->vy < -g_max_velocity) s->vy = -g_max_velocity;
}