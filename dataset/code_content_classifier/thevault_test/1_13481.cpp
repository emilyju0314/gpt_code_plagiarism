void GSTProcessor::processSDT(const GstStructure *structure)
{
    BOOST_ASSERT(structure);
    gboolean actual_ts = FALSE;
    gst_structure_get_boolean (structure,
                               "actual-transport-stream", &actual_ts);
    if (actual_ts)
    {
        GValue services = (*gst_structure_get_value (structure, "services"));
        guint size = gst_value_list_get_size (&services);
        /* Iterate over services*/
        for (guint i = 0; i < size; i++)
        {
            GValue val = (*gst_value_list_get_value (&services, i));
            const GstStructure* service = gst_value_get_structure (&val);
            /* Returns "service-%d"*/
            BOOST_ASSERT(gst_structure_get_name (service));
            std::string srvname = gst_structure_get_name (service);
            klk_log(KLKLOG_DEBUG, "Service name: %s", srvname.c_str());

            guint program_number = 0U;
            sscanf(srvname.c_str(), "service-%u", &program_number);

            gboolean scrambled = FALSE;
            if (gst_structure_has_field (service, "scrambled"))
            {
                gst_structure_get_boolean(service, "scrambled", &scrambled);
            }
            else
            {
                klk_log(KLKLOG_DEBUG,
                        "Service  %s scrambling status is unknown",
                        srvname.c_str());
            }
            if (scrambled)
            {
                klk_log(KLKLOG_DEBUG, "Service  %s is scrambled",
                        srvname.c_str());
            }
            std::string name = "";
            if (gst_structure_has_field (service, "name"))
            {
                name = gst_structure_get_string (service, "name");
                klk_log(KLKLOG_DEBUG, "Name: %s", name.c_str());
            }

            std::string prvname = "";
            if (gst_structure_has_field (service, "provider-name"))
            {
                prvname =
                    gst_structure_get_string(service, "provider-name");
                klk_log(KLKLOG_DEBUG, "Provider name: %s", prvname.c_str());
            }

            // dump the info
            m_dumpSDT(program_number, name, prvname, scrambled);
        }
    }
}