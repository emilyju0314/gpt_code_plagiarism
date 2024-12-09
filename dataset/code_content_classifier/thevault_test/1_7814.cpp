int
Rtree::RTreeSearchSphere(struct Node *N, struct Point *queryPoint, float radius,
                         long *diskacc, vector<int> &answers)
{
    struct Node *n = N;
    int hitCount = 0, i;
    //struct Rect *r = R;
    //struct Point querypoint/*, centroid*/;
    //float maxradius=0.0;

    assert(n);
    assert(n->level >= 0);
    assert(queryPoint);

    //maxradius=(r->boundary[NUMDIMS] - r->boundary[0]) * RANGEFACTOR; //??

    if (n->level > 0) { /* this is an internal node in the tree */
        for (i = 0; i < NODECARD; i++) {
            if (spheres_exist && n->level == 1) { // use both conditions
                if (n->branch[i].child &&
                    RTreeOverlapSphere(&n->branch[i].rect, queryPoint, radius)) {
                    /* centroid=Center(&n->branch[i].rect);
                       if (Distance(&querypoint, &centroid, DIST_METRIC) <= (n->branch[i].radius + maxradius)) */
                    //printf("Accessing a node at level %d \n", n->level);
                    diskacc[n->level]++;
                    hitCount += RTreeSearchSphere(n->branch[i].child, queryPoint, radius, diskacc, answers);
                }
            } else {
                if (n->branch[i].child &&
                    RTreeOverlapSphere(&n->branch[i].rect, queryPoint, radius)) {
                    //printf("Accessing a node at level %d \n", n->level);
                    diskacc[n->level]++;
                    hitCount += RTreeSearchSphere(n->branch[i].child, queryPoint, radius, diskacc, answers);
                }
            }
        }
    } else { /* this is a leaf node */
        for (i = 0; i < NODECARD; i++) {
            /* if (n->branch[i].child && RTreeOverlapSphere(r,&n->branch[i].rect)) */
            if (n->branch[i].child &&
                RTreeOverlapSphere(&n->branch[i].rect, queryPoint, radius)) {
                // printf("Accessing a node at level %d \n", n->level);
                diskacc[n->level]++;
                hitCount++;

                answers.push_back(static_cast<int>(reinterpret_cast<uintptr_t>(n->branch[i].child))); // Added by Chen Li
            }
        }
    }
    return hitCount;
}