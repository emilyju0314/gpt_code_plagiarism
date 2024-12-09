static void RTreeMethodZero(struct PartitionVars *p)
{
	register int i;
	RectReal biggestDiff;
	register int group, chosen, betterGroup;
	assert(p);

	RTreeInitPVars(p);
	RTreePickSeeds(p);

	while (p->count[0] + p->count[1] < NODECARD + 1
		&& p->count[0] < NODECARD + 1 - MinFill
		&& p->count[1] < NODECARD + 1 - MinFill)
	{
		biggestDiff = (RectReal)-1.;
		for (i=0; i<NODECARD+1; i++)
		{
			if (!p->taken[i])
			{
				struct Rect *r, rect_0, rect_1;
				RectReal growth0, growth1, diff;

				r = &BranchBuf[i].rect;
				rect_0 = RTreeCombineRect(r, &p->cover[0]);
				rect_1 = RTreeCombineRect(r, &p->cover[1]);
				growth0 = RTreeRectSphericalVolume(
						&rect_0)-p->area[0];
				growth1 = RTreeRectSphericalVolume(
						&rect_1)-p->area[1];
				diff = growth1 - growth0;
				if (diff >= 0)
					group = 0;
				else
				{
					group = 1;
					diff = -diff;
				}

				if (diff > biggestDiff)
				{
					biggestDiff = diff;
					chosen = i;
					betterGroup = group;
				}
				else if (diff==biggestDiff &&
					 p->count[group]<p->count[betterGroup])
				{
					chosen = i;
					betterGroup = group;
				}
			}
		}
		RTreeClassify(chosen, betterGroup, p);
	}

	/* if one group too full, put remaining rects in the other */
	if (p->count[0] + p->count[1] < NODECARD + 1)
	{
		if (p->count[0] >= NODECARD + 1 - MinFill)
			group = 1;
		else
			group = 0;
		for (i=0; i<NODECARD+1; i++)
		{
			if (!p->taken[i])
				RTreeClassify(i, group, p);
		}
	}

	assert(p->count[0] + p->count[1] == NODECARD+1);
	assert(p->count[0] >= MinFill && p->count[1] >= MinFill);
}