NvDlaError memory::MemoryResolver::resolveHazards(engine_ast::Node *op, vector< SurfacePair > &collisions)
{
    NvDlaError e = NvDlaSuccess;
    engine_ast::Graph *graph = op->graph();

    for ( size_t ci = 0, CI = collisions.size(); ci != CI; ++ci )
    {
        surface::TensorSurfaceDesc *newer = collisions[ci].first;
        surface::TensorSurfaceDesc *older = collisions[ci].second;

        // create a hazard dependency between the nodes at which
        // the operations occur. such that the op(s?) involved in
        // the newer use of the surface wait for the older ones
        // to complete.  i.e: older +++> newer

        for ( unordered_set<Node *>::const_iterator readi = older->consumers().begin();
              readi != older->consumers().end(); ++readi )
        {
            for ( unordered_set<Node *>::const_iterator writej = newer->producers().begin();
                  writej != newer->producers().end(); ++writej )
            {
                if ( readi == writej )
                {
                    // continue as it makes no sense to wait on yourself.
                    // shouldn't happen but at least don't freak anything out.
                    gLogInfo << "warning: hazard waiting on ourselves? " << (*readi)->id() << " vs. " << (*writej)->id() << endl;
                    continue;
                }

                if ( (*writej)->dependsOn(*readi, engine_ast::viaComputeHazard, engine_ast::allowDataCompute ) )
                {
                    // already there.
                    if ( graph->debugMemHazards() )
                    {
                        gLogInfo << "info: hazard avoided: " << (*writej)->id() << " already depends on " << (*readi)->id() << endl;
                    }
                    continue;
                }
                else if ( (*readi)->dependsOn(*writej, engine_ast::viaComputeHazard, engine_ast::allowDataCompute) )
                {
                    // adding a hazard here would cause a cycle.  uh?
                    //ORIGINATE_ERROR_FAIL( NvDlaError_InvalidState, "failed due to memory hazard induced compute dependency cycle");
                    if ( graph->debugMemHazards() )
                    {
                        gLogInfo << "warning: hazard cycle?" << (*readi)->id() << " depends on " << (*writej)->id() << " ???" << endl;
                    }
                }
                else
                {
                    Edge *hazardEdge = graph->addHazardEdge(*readi, *writej);
                    if ( graph->debugMemHazards() )
                    {
                        gLogInfo << "\tinserted hazard edge=" << hazardEdge->id() << " between nodes " <<
                            (*readi)->name() << " and " << (*writej)->name() <<
                            " to resolve memory reuse hazard" << endl;
                    }
                }
            }
        }
    }

    // fail:
    return e;
}