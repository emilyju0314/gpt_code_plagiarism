void generateDialogueArgStart(ostringstream& oss_reaction_mirror, int ing_iso_opt, int egr_iso_opt) {

    // Shared tmp variables
    oss_reaction_mirror << "  int __mantis__reg_flags=1;\n"
                       << "  int __mantis__value_count;\n"
                       << "  int __mantis__num_actually_read;\n"
                       << "  int __mantis__i;\n";
    // Take snapshots of ing/egr metrics
    if(((unsigned int)ing_iso_opt) & 0b1) {
        oss_reaction_mirror << "  __mantis__mbl_updated_ing=1;\n"
                           // Update data plane working copy
                           << "\n  __mantis__flip_mv_ing;\n"
                           << "\n  __mantis__mod_vars_ing;\n"
                           << "\n  __mantis__flip_mv_ing;\n"
                           << "\n  __mantis__mbl_updated_ing=0;\n";  
    }
    if(((unsigned int)egr_iso_opt) & 0b1) {
        oss_reaction_mirror << "  __mantis__mbl_updated_egr=1;\n"
                           // Update data plane working copy
                           << "\n  __mantis__flip_mv_egr;\n"
                           << "\n  __mantis__mod_vars_egr;\n"
                           << "\n  __mantis__flip_mv_egr;\n"
                           << "\n  __mantis__mbl_updated_egr=0;\n";  
    }    

}