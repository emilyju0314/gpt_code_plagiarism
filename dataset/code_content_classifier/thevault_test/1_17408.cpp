bool select_by_motion(
            std::size_t caller_self_id,
            core::Background& bg,
            core::FuncFinder& ff,
            core::FuncFinder& parent_ff,
            core::NTypeLogger& parent_lgr) {

        using core::Mode ;
        using core::ModeFlags ;
        ff.reset_parser_states() ;
        parent_ff.reset_parser_states() ;
        parent_ff.transition_parser_states_in_batch(parent_lgr) ;

        core::NTypeLogger lgr ;

        core::InstantKeyAbsorber ika ;

        while(true) {
            bg.update() ;

            auto log = core::InputGate::get_instance().pop_log() ;
            auto result = lgr.logging_state(log) ;
            auto parent_result = parent_lgr.logging_state(log) ;
            if(NTYPE_EMPTY(result) && NTYPE_EMPTY(parent_result)) {
                continue ;
            }
            if(NTYPE_HEAD_NUM(result)) {
                opt::VCmdLine::print(
                        opt::StaticMessage(std::to_string(lgr.get_head_num()))) ;
                parent_lgr.remove_from_back(1) ;
                continue ;
            }

            auto parser_1 = parent_ff.find_parser_with_transition(lgr.latest(), caller_self_id) ;
            if(parser_1) {
                if(parser_1->get_func()->id() == caller_self_id) {
                    parser_1 = nullptr ;
                }
                else if(parser_1->is_accepted()) {
                    opt::VCmdLine::reset() ;
                    parser_1->get_func()->process(parent_lgr) ;
                    return false ;
                }
            }

            auto parser_2 = ff.find_parser_with_transition(lgr.latest(), caller_self_id) ;
            if(parser_2) {
                if(parser_2->is_accepted() && std::dynamic_pointer_cast<MoveBase>(parser_2->get_func())) {
                    core::set_global_mode(Mode::EDI_VISUAL, ModeFlags::VISUAL_LINE) ;
                    safe_for(parent_lgr.get_head_num(), [f = parser_2->get_func(), &lgr] {
                        f->process(lgr) ;
                    }) ;
                    return true ;
                }
            }
            else if(!parser_1) { //reject
                break ;
            }

            if((parser_1 && parser_1->is_rejected_with_ready()) \
                    || (parser_2 && parser_2->is_rejected_with_ready())) {
                ff.backward_parser_states(1) ;
                lgr.remove_from_back(1) ;
                parent_ff.backward_parser_states(1) ;
                parent_lgr.remove_from_back(1) ;
            }
        }
        return false ;
    }