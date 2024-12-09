BOOST_FOREACH(const I3Particle* primary, primaries)
    {
        if ((primary->GetShape() != I3Particle::Primary) && (primary->GetShape() != I3Particle::Null) && (primary->GetShape() != I3Particle::Dark))
            log_warn("Input tree contains a particle with shape!=(Primary or Null or Dark) at its root. (shape=%s, type=%s)",
                      primary->GetShapeString().c_str(), primary->GetTypeString().c_str());
        
        outputMCTree->insert(*primary);

        I3MCTree::const_iterator primary_in_input_tree(*inputMCTree,  *primary);
        I3MCTree::iterator primary_in_output_tree(*outputMCTree, *primary);

        SliceMuonOrCopySubtree(*inputMCTree,
                               *MMCTrackList,
                               MMCTrackListIndex,
                               *outputMCTree,
                               primary_in_input_tree,
                               primary_in_output_tree);
    }