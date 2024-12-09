static void CalcSphereBounds(const XMFLOAT3 center, float r, const float zoom[2], 
                             float minb[2], float maxb[2])
{
    // By default, assume that the full screen is covered
    minb[0] = minb[1] = -1.0f;
    maxb[0] = maxb[1] =  1.0f;

    // Once for x, once for y
    for (int i=0; i<2; i++)
    {
		float x;
		if (i == 0)
			x = center.x;
		else
			x = center.y;

        float z = center.z;
        float ds = x*x + z*z;
        float l = ds - r * r;

        if (l > 0.0f)
        {
            float s,c;
            l = sqrt(l);

            s = x * l - z * r;  // ds*sin(alpha)
            c = x * r + z * l;  // ds*cos(alpha)
            if (z*ds > -r*s)    // left/top intersection has positive z
                minb[i] = MAX(-1.0f, s*zoom[i]/c);

            s = z * r + x * l;  // ds*sin(beta)
            c = z * l - x * r;  // ds*cos(beta)
            if (z*ds > r*s)     // right/bottom intersection has positive z
                maxb[i] = MIN(1.0f, s*zoom[i]/c);
        }
    }
}