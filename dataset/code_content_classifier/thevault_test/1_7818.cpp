void RTreeSearchRect(struct Rect *Search, struct Rect *Data)
{
	register struct Rect *search = Search, *data = Data;
	register int i, j;
	register RectReal size, center;

	assert(search);
	assert(data);

	for (i=0; i<NUMDIMS; i++)
	{
		j = i + NUMDIMS;  // index for high side boundary
		if (data->boundary[i] > -BIG_NUM &&
		    data->boundary[j] < BIG_NUM)
		{
			size = (drand48() * (data->boundary[j] -
					 data->boundary[i] + 1)) / 2;
			center = data->boundary[i] + drand48() *
				(data->boundary[j] - data->boundary[i] + 1);
			search->boundary[i] = center - size/2;
			search->boundary[j] = center + size/2;
		}
		else  // some open boundary, search entire dimension
		{
			search->boundary[i] = -BIG_NUM;
			search->boundary[j] = BIG_NUM;
		}
	}
}