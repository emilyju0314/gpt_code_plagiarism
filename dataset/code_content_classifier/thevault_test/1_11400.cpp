void ResetAchievements_f()
{
	if (steamapicontext && steamapicontext->SteamUserStats())
		steamapicontext->SteamUserStats()->ResetAllStats( true );
	else
		DevMsg("Missing Steam API context, failed to execute: maplab_resetachievement\n");
}