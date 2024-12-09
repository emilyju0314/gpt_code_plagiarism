static bool KillPersonInVehicle(SOLDIERTYPE& s)
{
	if (s.bLife == 0) return false; // Guy is dead, leave
	// Otherwise hurt him
	SoldierTakeDamage(&s, 100, 100, TAKE_DAMAGE_BLOODLOSS, 0);
	return true;
}