void Interpolation::Compute_Steffen_Coefficients(std::vector<std::vector<double>>& data, std::vector<double> &a,std::vector<double> &b,std::vector<double> &c,std::vector<double> &d)
		{
			unsigned int N= data.size();
			//Compute the Steffen coefficients for the interpolation
				//1. h and s.
					double h[N-1],s[N-1];
					for(unsigned int i=0;i<N-1;i++)
					{
						double x_i = data[i][0];
						double x_ip1 = data[i+1][0];
						
						double y_i = data[i][1];
						double y_ip1 = data[i+1][1];
						h[i] = x_ip1-x_i;
						s[i]= (y_ip1-y_i)/h[i];
					}
				//2. p and dy
					double dy[N],p[N];
					for(unsigned int i=0;i<N;i++)
					{
						//First point
							if(i==0)
							{
								p[i] = s[i]*(1.0+h[i]/(h[i]+h[i+1]))-s[i+1]*h[i]/(h[i]+h[i+1]);
								dy[i] = (Sign(p[i])+Sign(s[i]))*std::min(1.0*abs(s[i]),0.5*abs(p[i]));
							}
						//Last point
							else if(i==N-1)
							{
								p[i] = s[i-1]*(1.0+h[i-1]/(h[i-1]+h[i-2]))-s[i-2]*h[i-1]/(h[i-1]+h[i-2]);
								dy[i] = (Sign(p[i])+Sign(s[i-1]))*std::min(1.0*abs(s[i-1]),0.5*abs(p[i]));
							}
						//Points in the middle
							else
							{
								p[i] = (s[i-1]*h[i]+s[i]*h[i-1])/(h[i-1]+h[i]);
								dy[i] = (Sign(s[i-1])+Sign(s[i]))*std::min(1.0*abs(p[i])/2.0 ,std::min(1.0*abs(s[i]) ,1.0*abs(s[i-1]) ) );
							}
					}
				//3. a,b,c, and d
					for(unsigned int i=0;i<N-1;i++)
					{
						a.push_back((dy[i]+dy[i+1]-2.0*s[i])/pow(h[i],2.0));
						b.push_back((3.0*s[i]-2.0*dy[i]-dy[i+1])/h[i]);
						c.push_back(dy[i]);
						d.push_back(data[i][1]);
						if(std::isnan(a.back())||std::isnan(b.back())||std::isnan(c.back())||std::isnan(d.back())) 
						{
							std::cout <<"Warning: Steffen coefficients in interpolation are NAN."<<std::endl;
						}
					}
		}