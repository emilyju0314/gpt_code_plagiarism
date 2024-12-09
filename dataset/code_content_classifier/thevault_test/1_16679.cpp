DSCC_POINT TransformPoint ( DSCC_POINT p, TRANSPARAM Param )
{
	DSCC_POINT pr ;
	if(Param.Type == 0)
	{
		p.x += Param.dx ;
		p.y += Param.dy ;
		double dx = p.x - Param.Center.x ;
		double dy = p.y - Param.Center.y ;
		double r = sqrt (dx*dx+dy*dy) ;
		double a = atan2 ( -dy, dx ) ;
		pr.x = (int) (Param.Center.x+r*cos(a+Param.Angle)) ;
		pr.y = (int) (Param.Center.y-r*sin(a+Param.Angle)) ;
	}
	else
	{
		pr.x = (long)(Param.a*p.x + Param.b*p.y + Param.x0 + Param.e*p.x*p.y+0.5);
		pr.y = (long)(Param.c*p.x + Param.d*p.y + Param.y0 + Param.f*p.x*p.y+0.5);
	}
	return pr;
}