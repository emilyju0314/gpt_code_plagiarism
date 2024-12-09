int
Rtree::RTreeSearch(struct Node *N, struct Rect *R,
                   long *diskacc, vector<uintptr_t> &answers)
{
    struct Node *n = N;
    struct Rect *r = R;
    int hitCount = 0, i;
    struct Point querypoint/*, centroid*/;
    float maxradius = 0.0;

    assert(n);
    assert(n->level >= 0);
    assert(r);

    maxradius = (r->boundary[NUMDIMS] - r->boundary[0]) * RANGEFACTOR;
    for (i = 0; i < NUMDIMS; i++)
        querypoint.position[i] = (r->boundary[i] + r->boundary[i + NUMDIMS]) / 2;

    if (n->level > 0) { /* this is an internal node in the tree */
        for (i = 0; i < NODECARD; i++) {
            if (spheres_exist && n->level == 1) { // use both conditions
                if (n->branch[i].child && RTreeOverlap(&querypoint, &n->branch[i].rect, maxradius, DIST_METRIC)) {
                    /* centroid=Center(&n->branch[i].rect);
                       if (Distance(&querypoint, &centroid, DIST_METRIC) <= (n->branch[i].radius + maxradius)) */
                    //printf("Accessing a node at level %d \n", n->level);
                    diskacc[n->level]++;
                    hitCount += RTreeSearch(n->branch[i].child, R, diskacc, answers);
                }
            } else {
                if (n->branch[i].child && RTreeOverlap(&querypoint, &n->branch[i].rect, maxradius, DIST_METRIC)) {
                    //printf("Accessing a node at level %d \n", n->level);
                    diskacc[n->level]++;
                    hitCount += RTreeSearch(n->branch[i].child, R, diskacc, answers);
                }
            }
        }
    } else { /* this is a leaf node */
        for (i = 0; i < NODECARD; i++) {
            /* if (n->branch[i].child && RTreeOverlap(r,&n->branch[i].rect)) */
            if (n->branch[i].child && RTreeOverlap(&querypoint, &n->branch[i].rect, maxradius, DIST_METRIC)) {
                // printf("Accessing a node at level %d \n", n->level);
                diskacc[n->level]++;
                hitCount++;

                answers.push_back(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(n->branch[i].child))); // Added by Chen Li
            }
        }
    }
    return hitCount;
}