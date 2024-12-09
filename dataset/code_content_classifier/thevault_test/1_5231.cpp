bool ts::TablesLogger::loadArgs(DuckContext& duck, Args& args)
{
    // Type of output, text is the default.
    _use_xml = args.present(u"xml-output");
    _use_binary = args.present(u"binary-output");
    _use_udp = args.present(u"ip-udp");
    _use_text = args.present(u"output-file") || args.present(u"text-output") || ( !_use_xml && !_use_binary && !_use_udp);

    // --output-file and --text-output are synonyms.
    if (args.present(u"output-file") && args.present(u"text-output")) {
        args.error(u"--output-file and --text-output are synonyms, do not use both");
    }

    // Output destinations.
    _xml_destination = args.value(u"xml-output");
    _bin_destination = args.value(u"binary-output");
    _udp_destination = args.value(u"ip-udp");
    _text_destination = args.value(u"output-file", args.value(u"text-output").c_str());

    // Accept "-" as a specification for standard output (common convention in UNIX world).
    if (_text_destination == u"-") {
        _text_destination.clear();
    }
    if (_xml_destination == u"-") {
        _xml_destination.clear();
    }

    _multi_files = args.present(u"multiple-files");
    _rewrite_binary = args.present(u"rewrite-binary");
    _rewrite_xml = args.present(u"rewrite-xml");
    _flush = args.present(u"flush");
    _udp_local = args.value(u"local-udp");
    _udp_ttl = args.intValue(u"ttl", 0);
    _pack_all_sections = args.present(u"pack-all-sections");
    _pack_and_flush = args.present(u"pack-and-flush");
    _fill_eit = args.present(u"fill-eit");
    _all_once = args.present(u"all-once");
    _all_sections = _all_once || _pack_all_sections || args.present(u"all-sections");
    _max_tables = args.intValue<uint32_t>(u"max-tables", 0);
    _time_stamp = args.present(u"time-stamp");
    _packet_index = args.present(u"packet-index");
    _logger = args.present(u"log");
    _log_size = args.intValue<size_t>(u"log-size", DEFAULT_LOG_SIZE);
    _no_duplicate = args.present(u"no-duplicate");
    _udp_raw = args.present(u"no-encapsulation");
    _use_current = !args.present(u"exclude-current");
    _use_next = args.present(u"include-next");

    // Check consistency of options.
    if (_rewrite_binary && _multi_files) {
        args.error(u"options --rewrite-binary and --multiple-files are incompatible");
        return false;
    }

    // Load options from all section filters.
    _initial_pids.reset();
    for (auto it = _section_filters.begin(); it != _section_filters.end(); ++it) {
        PIDSet pids;
        if (!(*it)->loadFilterOptions(_duck, args, pids)) {
            return false;
        }
        _initial_pids |= pids;
    }

    // Load XML options.
    return _xml_tweaks.loadArgs(duck, args);
}