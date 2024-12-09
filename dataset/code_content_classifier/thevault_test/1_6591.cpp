double TcpAgent::linear(double x, double x_1, double y_1, double x_2, double y_2)
{
	// The y coordinate factor ranges from y_1 to y_2
	//  as the x coordinate ranges from x_1 to x_2.
	double y = y_1 + ((y_2 - y_1) * ((x - x_1)/(x_2-x_1)));
	return y;
}