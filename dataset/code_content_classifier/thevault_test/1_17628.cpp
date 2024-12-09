double FormFactor_N(double q,double A,bool ldm)
		{
			if(ldm || q==0.0) return 1.0;
			else
			{
				double a = 0.52*fm;
				double c = (1.23*pow(A,1.0/3.0)-0.6)*fm;
				double s = 0.9*fm;
				double rn = sqrt(c*c+7.0/3.0*pow(M_PI*a,2.0)-5*s*s);
				double qr = q*rn;
				return 3.0*(sin(qr)/pow(qr,3.0)-cos(qr)/pow(qr,2.0))*exp(-q*q*s*s/2.0);
			}
		}