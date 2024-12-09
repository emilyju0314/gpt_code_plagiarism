float GetStep(float Origin, float Direction)
{
	if (Direction < 0)
		return GetStep(-Origin, -Direction);
	else
	{
		float Rem = Mod(Origin, 1.0f);
		return (1.0f - Rem) / Direction;
	}
}