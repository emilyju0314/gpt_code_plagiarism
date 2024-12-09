void mirrorFieldArg(std::vector<AstNode*> nodeArray, ostringstream& oss_reaction_mirror, 
                    ostringstream& oss_preprocessor, vector<ReactionArgBin> bins,
                    string prefix_str, bool forIng) {
    for (int i = 0; i < bins.size(); ++i) {
        // Applies to both cases with/without isolation by indexing __mv
        if(forIng) {
            oss_reaction_mirror << str(boost::format(kIngFieldArgPollT) % std::to_string(bins[i].second) % std::to_string(i) % prefix_str);
        } else {
            oss_reaction_mirror << str(boost::format(kEgrFieldArgPollT) % std::to_string(bins[i].second) % std::to_string(i) % prefix_str);
        }

        // Reverse order
        for (int j = bins[i].first.size()-1; j >= 0; --j) {      
            AstNode* arg_node = bins[i].first[j].first->arg_;
            int width = bins[i].first[j].second;
            std::regex e_dot2underscore ("\\.");
            string field_arg_c = std::regex_replace(arg_node->toString(), e_dot2underscore, "_");

            ostringstream oss_mask_tmp;
            oss_mask_tmp << "0b";
            for (int k = 0; k < width; ++k) {
                oss_mask_tmp << "1";
            }
            if(forIng) {
                oss_reaction_mirror << "\n  uint"
                                    << width
                                    << "_t "
                                    << field_arg_c
                                    << "="
                                    << "__mantis__values_riSetArgs_"
                                    << i
                                    << "[1]&"
                                    << oss_mask_tmp.str()
                                    << ";";    
                oss_reaction_mirror << "\n  __mantis__values_riSetArgs_"
                                    << i
                                    << "[1]>>"
                                    << width
                                    << ";";                   
            } else {
                oss_reaction_mirror << "\n  uint"
                                    << width
                                    << "_t "
                                    << field_arg_c
                                    << "="
                                    << "__mantis__values_reSetArgs_"
                                    << i
                                    << "[1]&"
                                    << oss_mask_tmp.str()
                                    << ";";    
                oss_reaction_mirror << "\n  __mantis__values_reSetArgs_"
                                    << i
                                    << "[1]>>"
                                    << width
                                    << ";";   
            }                                       
        }
    }
}