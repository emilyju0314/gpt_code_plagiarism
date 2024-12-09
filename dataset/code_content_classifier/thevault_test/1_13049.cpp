int32_t profile::validate(void)
{
        if(m_init)
        {
                return WAFLZ_STATUS_OK;
        }
        if(!m_pb)
        {
                WAFLZ_PERROR(m_err_msg, "pb == NULL");
                return WAFLZ_STATUS_ERROR;
        }
        const waflz_pb::profile &l_pb = *m_pb;
        // -------------------------------------------------
        // id/name
        // -------------------------------------------------
        VERIFY_HAS(l_pb, id);
        VERIFY_HAS(l_pb, name);
        // -------------------------------------------------
        // ruleset info
        // -------------------------------------------------
        VERIFY_HAS(l_pb, ruleset_id);
        VERIFY_HAS(l_pb, ruleset_version);
        // -------------------------------------------------
        // OWASP version detection hack
        // -used for anomaly variable naming
        // OWASP-CRS 3.0.0 + or ECRS
        // TODO not robust!!!
        // -------------------------------------------------
        if(l_pb.has_ruleset_id() &&
           ((l_pb.ruleset_id() == "ECRS")||
            (l_pb.ruleset_id().find("OWASP-CRS-3.") != std::string::npos)))
        {
                m_owasp_ruleset_version = 300;
        }
        m_id = m_pb->id();
        m_name = m_pb->name();
        // -------------------------------------------------
        // general settings
        // -------------------------------------------------
        VERIFY_HAS(l_pb, general_settings);
        const ::waflz_pb::profile_general_settings_t& l_gs = l_pb.general_settings();
        // set paranoia
        if(l_gs.has_paranoia_level())
        {
                m_paranoia_level = l_gs.paranoia_level();
        }
        VERIFY_HAS(l_gs, xml_parser);
        VERIFY_HAS(l_gs, validate_utf8_encoding);
        VERIFY_HAS(l_gs, max_num_args);
        VERIFY_HAS(l_gs, arg_name_length);
        VERIFY_HAS(l_gs, arg_length);
        VERIFY_HAS(l_gs, total_arg_length);
        VERIFY_HAS(l_gs, max_file_size);
        VERIFY_HAS(l_gs, combined_file_sizes);
        // set...
        if(l_gs.has_response_header_name())
        {
                m_resp_header_name = l_gs.response_header_name();
        }
        // -------------------------------------------------
        // access settings
        // -------------------------------------------------
        VERIFY_HAS(l_pb, access_settings);
        const ::waflz_pb::profile_access_settings_t& l_as = l_pb.access_settings();
        VERIFY_HAS(l_as, country);
        VERIFY_HAS(l_as, ip);
        VERIFY_HAS(l_as, url);
        VERIFY_HAS(l_as, referer);
        // -------------------------------------------------
        // anomaly settings
        // -------------------------------------------------
        VERIFY_HAS(l_gs, anomaly_settings);
        const ::waflz_pb::profile_general_settings_t_anomaly_settings_t& l_ax = l_gs.anomaly_settings();
        VERIFY_HAS(l_ax, critical_score);
        VERIFY_HAS(l_ax, error_score);
        VERIFY_HAS(l_ax, warning_score);
        VERIFY_HAS(l_ax, notice_score);
        VERIFY_HAS(l_ax, inbound_threshold);
        VERIFY_HAS(l_ax, outbound_threshold);
        // -------------------------------------------------
        // disabled rules
        // -------------------------------------------------
        if(l_pb.disabled_rules_size())
        {
                for(int32_t i_r = 0;
                    i_r < l_pb.disabled_rules_size();
                    ++i_r)
                {
                        const waflz_pb::profile_disabled_rule_t& l_r = l_pb.disabled_rules(i_r);
                        VERIFY_HAS(l_r, rule_id);
                }
        }
        // -------------------------------------------------
        // custom rules
        // -------------------------------------------------
        // TODO ???
        // -------------------------------------------------
        // rule target updates --optional
        // -------------------------------------------------
        if(l_pb.rule_target_updates_size())
        {
                for(int32_t i_r = 0;
                    i_r < l_pb.rule_target_updates_size();
                    ++i_r)
                {
                        const waflz_pb::profile_rule_target_update_t& l_r = l_pb.rule_target_updates(i_r);
                        VERIFY_HAS(l_r, rule_id);
                        VERIFY_HAS(l_r, target);
                        VERIFY_HAS(l_r, target_match);
                        VERIFY_HAS(l_r, is_regex);
                }
        }
        return WAFLZ_STATUS_OK;
}