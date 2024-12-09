bool UpdateAgents() {
	for (int i=0; i < g_agentCount; ++i) {
		g_agents[i].x += RandInt(-5,5);
		g_agents[i].y += RandInt(-5,5);
	}
	g_agents[0].x += 1;
	return true;
}