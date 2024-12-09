float round_f(float num) 
{
	float NumAbs = fabs(num);
	int NumAbsI = (int)(NumAbs + 0.5f);
	float sign = num > 0 ? 1.0f : -1.0f;
	return sign * NumAbsI;
}