void RenderScene(HDC surface) {
	//render the stats
	//string s = "Generation:          123";
	//TextOut(surface, 5, 0, s.c_str(), s.size());

	//do not render if running at accelerated speed
	if (!g_fastRender) {
		//keep a record of the old pen
		g_oldPen = (HPEN)SelectObject(surface, g_greenPen);
		
		for (int i = 0; i < g_agentCount; i++) {
				
			Ellipse(surface, g_agents[i].x, g_agents[i].y, g_agents[i].x+10,g_agents[i].y+10);

	    	//put the old pen back
		    SelectObject(surface, g_oldPen);

		}
  	}
}