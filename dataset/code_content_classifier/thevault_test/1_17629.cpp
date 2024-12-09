double DM_Particle::FormFactor_A(double q,int Z) const
		{
			if(!screening) return 1.0;
			else
			{
				double a2q2 = pow(q*Thomas_Fermi_Radius(Z),2.0);
				return a2q2/(1.0+a2q2);
			}
		}