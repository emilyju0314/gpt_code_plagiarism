void Universe_CellVisionData(CELL *cell, CELL_VISION_DATA *cvd)
{
	ORGANISM *o;
	UNIVERSE *u;

	ASSERT( cell != NULL );
	ASSERT( cvd != NULL );

	o = cell->organism;
	u = o->universe;

	look_along_line(u, cell,  0, -1, &cvd->what[0], &cvd->where[0]);
	look_along_line(u, cell,  1, -1, &cvd->what[1], &cvd->where[1]);
	look_along_line(u, cell,  1,  0, &cvd->what[2], &cvd->where[2]);
	look_along_line(u, cell,  1,  1, &cvd->what[3], &cvd->where[3]);
	look_along_line(u, cell,  0,  1, &cvd->what[4], &cvd->where[4]);
	look_along_line(u, cell, -1,  1, &cvd->what[5], &cvd->where[5]);
	look_along_line(u, cell, -1,  0, &cvd->what[6], &cvd->where[6]);
	look_along_line(u, cell, -1, -1, &cvd->what[7], &cvd->where[7]);
}