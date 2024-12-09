BOOST_FOREACH(const I3MCTree::const_iterator &daughter_it_inputTree, daughterIterators)
        {
            // add the particle to the output tree and get an iterator
            I3MCTree::iterator daughter_it_outputTree =
            outputTree.append_child(particle_it_outputTree, *daughter_it_inputTree);
            
            SliceMuonOrCopySubtree(inputTree,
                                   mmcTrackList,
                                   mmcTrackListIndex,
                                   outputTree,
                                   daughter_it_inputTree,
                                   daughter_it_outputTree);
        }