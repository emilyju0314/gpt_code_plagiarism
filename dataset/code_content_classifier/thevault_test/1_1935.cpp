void PopulateCacheFriendlyBVH(
    const Triangle *pFirstTriangle,
    BVHNode *root,
    unsigned& idxBoxes,
    unsigned &idxTriList)
{
    unsigned currIdxBoxes = idxBoxes;
    g_pCFBVH[currIdxBoxes]._bottom = root->_bottom;
    g_pCFBVH[currIdxBoxes]._top    = root->_top;
    if (!root->IsLeaf()) {
	BVHInner *p = dynamic_cast<BVHInner*>(root);
	int idxLeft = ++idxBoxes;
	PopulateCacheFriendlyBVH(pFirstTriangle, p->_left, idxBoxes, idxTriList);
	int idxRight = ++idxBoxes;
	PopulateCacheFriendlyBVH(pFirstTriangle, p->_right, idxBoxes, idxTriList);
	g_pCFBVH[currIdxBoxes].u.inner._idxLeft  = idxLeft;
	g_pCFBVH[currIdxBoxes].u.inner._idxRight = idxRight;
    } else {
	BVHLeaf *p = dynamic_cast<BVHLeaf*>(root);
	unsigned count = (unsigned) p->_triangles.size();
	g_pCFBVH[currIdxBoxes].u.leaf._count = 0x80000000 | count;
	g_pCFBVH[currIdxBoxes].u.leaf._startIndexInTriIndexList = idxTriList;
	for(std::list<const Triangle*>::iterator it=p->_triangles.begin();
	    it != p->_triangles.end();
	    it++)
	{
	    g_triIndexList[idxTriList++] = *it - pFirstTriangle;
	}
    }
}