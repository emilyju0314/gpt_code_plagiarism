static void RTreePickSeeds(struct PartitionVars *p)
{
	register int i, j, seed0, seed1;
	RectReal worst, waste, area[NODECARD+1];

	for (i=0; i<NODECARD+1; i++)
		area[i] = RTreeRectSphericalVolume(&BranchBuf[i].rect);

	worst = -CoverSplitArea - 1;
	for (i=0; i<NODECARD; i++)
	{
		for (j=i+1; j<NODECARD+1; j++)
		{
			struct Rect one_rect = RTreeCombineRect(
						&BranchBuf[i].rect,
						&BranchBuf[j].rect);
			waste = RTreeRectSphericalVolume(&one_rect) -
					area[i] - area[j];
			if (waste > worst)
			{
				worst = waste;
				seed0 = i;
				seed1 = j;
			}
		}
	}
	RTreeClassify(seed0, 0, p);
	RTreeClassify(seed1, 1, p);
}