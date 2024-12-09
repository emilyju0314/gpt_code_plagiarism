void add_edge(int point1_x, int point1_y, int point2_x, int point2_y, Mat* city)
{
	int node1_x = (point1_x*5+2);
	int node1_y = (point1_y*5+2);
	int node2_x = (point2_x*5+2);
	int node2_y = (point2_y*5+2);

	if (node1_x == node2_x)
	{
		if (node1_y < node2_y)
		{
			for (int i=node1_y+1;i<node2_y;i++){
				city->at<Vec3b>(node1_x,i)[2]= 0;
			}
		}
        else{
			for (int i=node2_y+1;i<node1_y;i++){
				city->at<Vec3b>(node1_x,i)[2]= 0;
			}
		}
	}
	if (node1_y == node2_y)
	{
		if (node1_x < node2_x)
		{
			for (int i=node1_x+1;i<node2_x;i++){
				city->at<Vec3b>(i,node1_y)[2]= 0;
			}
		}
        else{
			for (int i=node2_x+1;i<node1_x;i++){
				city->at<Vec3b>(i,node1_y)[2]= 0;
			}
		}
	}
}