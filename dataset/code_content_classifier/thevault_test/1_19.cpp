static void
_bound_fp(struct db_full_path *path, mat_t *curr_mat, void *client_data)
{
    struct directory *dp;
    struct draw_data_t *dd = (struct draw_data_t *)client_data;
    RT_CK_FULL_PATH(path);
    RT_CK_DBI(dd->dbip);

    dp = DB_FULL_PATH_CUR_DIR(path);
    if (!dp)
	return;
    if (dp->d_flags & RT_DIR_COMB) {
	// Have a comb - keep going
	struct rt_db_internal in;
	struct rt_comb_internal *comb;
	if (rt_db_get_internal(&in, dp, dd->dbip, NULL, &rt_uniresource) < 0)
	    return;
	comb = (struct rt_comb_internal *)in.idb_ptr;
	draw_walk_tree(path, comb->tree, curr_mat, _bound_fp, client_data);
	rt_db_free_internal(&in);
	// Use bbox to update sizing
	if (dd->have_bbox) {
	    dd->g->s_size = dd->g->bmax[X] - dd->g->bmin[X];
	    V_MAX(dd->g->s_size, dd->g->bmax[Y] - dd->g->bmin[Y]);
	    V_MAX(dd->g->s_size, dd->g->bmax[Z] - dd->g->bmin[Z]);
	}
    } else {
	// If we're skipping subtractions there's no
	// point in going further.
	if (dd->skip_subtractions && dd->bool_op == 4) {
	    return;
	}

	// On initialization we don't have any wireframes to establish sizes, and if
	// we're adaptive we need some idea of object size to get a reasonable result.
	// Try for a bounding box, if the method is available.  Otherwise try the
	// bounding the default plot.
	point_t bmin, bmax;
	fastf_t s_size;
	int bbret = _fp_bbox(&s_size, &bmin, &bmax, path, dd->dbip, dd->ttol, dd->tol, curr_mat, dd->res, dd->v);
	if (bbret >= 0) {
	    // Got bounding box, use it to update sizing
	    (*dd->s_size)[dp] = s_size;
	    VMINMAX(dd->min, dd->max, bmin);
	    VMINMAX(dd->min, dd->max, bmax);
	    VMINMAX(dd->g->bmin, dd->g->bmax, bmin);
	    VMINMAX(dd->g->bmin, dd->g->bmax, bmax);
	    dd->g->s_size = s_size;
	    dd->have_bbox = 1;
	}
    }
}