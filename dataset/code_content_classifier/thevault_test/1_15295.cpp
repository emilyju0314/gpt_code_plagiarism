surface::TensorSurfaceDesc *
engine_ast::Graph::nodeTensorSurface(const engine_ast::Node *n, size_t i,
                                    const vector<surface::SurfaceCategory> &types,
                                    ast::EdgeSideEnum dir)
{
    size_t matched = 0;
    surface::TensorSurfaceDesc* matched_tsd = NULL;
    vector<engine_ast::Edge *> test_edges = nodeEdges(n, dir);
    for ( size_t tei = 0, TEI = test_edges.size(); tei != TEI; ++tei )
    {
        if ( !test_edges[tei]->isDataEdge() )
        {
            continue;
        }
        surface::TensorSurfaceDesc * e_tsd = test_edges[tei]->tensorSurfaceDesc();
        surface::SurfaceCategoryEnum sc = e_tsd->surfaceFormat().category().e();
        for ( size_t tt = 0, TT = types.size(); tt != TT; ++tt)
        {
            if ( sc == types[tt].e() )
            {
                if ( matched == i )
                {
                    matched_tsd = e_tsd;
                    goto done;
                }
                matched++;
            }
        }
    }

done:
    return matched_tsd;
}