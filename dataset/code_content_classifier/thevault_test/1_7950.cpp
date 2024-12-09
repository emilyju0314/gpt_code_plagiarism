static void spiralpath_next(SPIRALPATH *sp)
{
	int tmp;

	ASSERT( sp != NULL );

	if( sp->curlen > 0 ) {
		sp->curlen -= 1;
	} else {
		sp->len += 1;
		sp->curlen = sp->len;

		/*
		 * turn right
		 */
		tmp = sp->dirx;
		sp->dirx = sp->diry * -1;
		sp->diry = tmp;
	}

	sp->x += (sp->dirx * sp->step);
	sp->y += (sp->diry * sp->step);

}