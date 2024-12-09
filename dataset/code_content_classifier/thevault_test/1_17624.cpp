double Integrate(std::function<double(double)> func, double a,double b, double epsilon,int maxRecursionDepth)
		{
			int sign = +1;
			if(a==b) return 0.0;
			else if(a>b)
			{
				double aux = a;
				a = b;
				b=aux;
				sign = -1;
			}
			double c = (a + b)/2;
			double h = b - a;                                                                  
				double fa = func(a);
				double fb = func(b);
				double fc = func(c); 
				double S = (h/6)*(fa + 4*fc + fb);
				bool warning = false;
				double result =   auxAdaptiveSimpson(func, a, b, fabs(epsilon), S, fa, fb, fc, maxRecursionDepth,warning); 
				if(warning)   
				{
					std::cout <<"Warning in Integrate(): Numerical integration on the interval ("<<a<<","<<b<<") did not converge to the desired precision." <<std::endl;
					std::cout <<"\tDesired precision: " <<fabs(epsilon) <<" Result: " <<result<<std::endl;
				}
			if(std::isnan(result)) std::cout <<"Warning in Integrate(): Result is nan."<<std::endl;
			else if(std::isinf(result)) std::cout <<"Warning in Integrate(): Result is inf."<<std::endl;
			return sign*result;
		}