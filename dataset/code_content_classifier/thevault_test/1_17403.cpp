Mat generate_city(int x, int y, int* houses, int cnt_H, int* city_centres, int cnt_CC)
{
	Mat grid(x,y,CV_8UC3,Scalar(255,255,255));
	for (int i=0;i<cnt_H;i++)
	{
		grid.at<Vec3b>(((houses[i]/y)),((houses[i]%x)))[0] = 0;

	}
	for (int i=0;i<cnt_CC;i++)
	{
		grid.at<Vec3b>(city_centres[i]/y,city_centres[i]%x)[1] = 0;
	}
	

	Mat city(5*x,5*y,CV_8UC3,Scalar(255,255,255));
    for (int i=0;i<x;i++)
    {
    	for (int j=0;j<y;j++)
    	{
    		city.at<Vec3b>(5*i+2,5*j+2) = grid.at<Vec3b>(i,j);
    	}
    }

	return city;
}