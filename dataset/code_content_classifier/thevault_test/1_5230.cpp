void ts::TablesLogger::defineArgs(Args& args) const
{
    // Define XML options.
    _xml_tweaks.defineArgs(args);

    // Define options from all section filters.
    for (auto it = _section_filters.begin(); it != _section_filters.end(); ++it) {
        (*it)->defineFilterOptions(args);
    }

    args.option(u"all-once");
    args.help(u"all-once",
              u"Same as --all-sections but collect each section only once per combination of "
              u"PID, table id, table id extension, section number and version.");

    args.option(u"all-sections", 'a');
    args.help(u"all-sections", u"Display/save all sections, as they appear in the stream. By default, "
              u"collect complete tables, with all sections of the tables grouped and "
              u"ordered and collect each version of a table only once. Note that this "
              u"mode is incompatible with --xml-output since valid XML structures may "
              u"contain complete tables only.");

    args.option(u"binary-output", 'b', Args::STRING);
    args.help(u"binary-output", u"filename",
              u"Save sections in the specified binary output file. "
              u"See also option -m, --multiple-files.");

    args.option(u"fill-eit");
    args.help(u"fill-eit",
              u"Before exiting, add missing empty sections in EIT's and flush them. "
              u"This can be useful with segmented EIT schedule where empty sections "
              u"at end of segments are usually not transmitted.");

    args.option(u"flush", 'f');
    args.help(u"flush", u"Flush output after each display.");

    args.option(u"exclude-current");
    args.help(u"exclude-current",
              u"Exclude short sections and long sections with \"current\" indicator. "
              u"This is rarely necessary. See also --include-next.");

    args.option(u"include-next");
    args.help(u"include-next",
              u"Include long sections with \"next\" indicator. By default, they are excluded.");

    args.option(u"ip-udp", 'i', Args::STRING);
    args.help(u"ip-udp", u"address:port",
              u"Send binary tables over UDP/IP to the specified destination. "
              u"The 'address' specifies an IP address which can be either unicast "
              u"or multicast. It can be also a host name that translates to an IP "
              u"address. The 'port' specifies the destination UDP port.");

    args.option(u"local-udp", 0, Args::STRING);
    args.help(u"local-udp", u"address",
              u"With --ip-udp, when the destination is a multicast address, specify "
              u"the IP address of the outgoing local interface. It can be also a host "
              u"name that translates to a local address.");

    args.option(u"log", 0);
    args.help(u"log", u"Display a short one-line log of each table instead of full table display.");

    args.option(u"log-size", 0, Args::UNSIGNED);
    args.help(u"log-size",
              u"With option --log, specify how many bytes are displayed at the "
              u"beginning of the table payload (the header is not displayed). "
              u"The default is 8 bytes.");

    args.option(u"max-tables", 'x', Args::POSITIVE);
    args.help(u"max-tables", u"Maximum number of tables to dump. Stop logging tables when this limit is reached.");

    args.option(u"multiple-files", 'm');
    args.help(u"multiple-files",
              u"Create multiple binary output files, one per section. A binary "
              u"output file name must be specified (option -b or --binary-output). "
              u"Assuming that the specified file name has the form 'base.ext', "
              u"each file is created with the name 'base_pXXXX_tXX.ext' for "
              u"short sections and 'base_pXXXX_tXX_eXXXX_vXX_sXX.ext' for long "
              u"sections, where the XX specify the hexadecimal values of the "
              u"PID, TID (table id), TIDext (table id extension), version and "
              u"section index.");

    args.option(u"no-duplicate");
    args.help(u"no-duplicate",
              u"Do not report consecutive identical tables with a short section in the "
              u"same PID. This can be useful for ECM's. This is the way to display new "
              u"ECM's only. By default, tables with long sections are reported only when "
              u"a new version is detected but tables with a short section are all reported.");

    args.option(u"no-encapsulation");
    args.help(u"no-encapsulation",
              u"With --ip-udp, send the tables as raw binary messages in UDP packets. "
              u"By default, the tables are formatted into TLV messages.");

    args.option(u"output-file", 'o', Args::STRING);
    args.help(u"output-file", u"",
              u"Save the tables or sections in human-readable text format in the specified "
              u"file. By default, when no output option is specified, text is produced on "
              u"the standard output. If you need text formatting on the standard output in "
              u"addition to other output like binary files or UPD/IP, explicitly specify "
              u"this option with \"-\" as output file name.\n\n"
              u"By default, the tables are interpreted and formatted as text on the standard "
              u"output. Several destinations can be specified at the same time: human-readable "
              u"text output, binary output, UDP/IP messages.");

    args.option(u"pack-all-sections");
    args.help(u"pack-all-sections",
              u"Same as --all-sections but also modify each long section so that it becomes a "
              u"valid complete table. Its section_number and last_section_number are forced "
              u"to zero. Use with care because this may create inconsistent tables. This "
              u"option can be useful with tables with sparse sections such as EIT's to save "
              u"them in XML format (as an alternative, see also --fill-eit).");

    args.option(u"pack-and-flush");
    args.help(u"pack-and-flush",
              u"Before exiting, pack incomplete tables, ignoring missing sections, and flush "
              u"them. Use with care because this may create inconsistent tables. Unlike option "
              u"--pack-all-sections, --pack-and-flush does not force --all-sections because it "
              u"only applies to the last incomplete tables before exiting.");

    args.option(u"packet-index");
    args.help(u"packet-index",
              u"Display the index of the first and last TS packet of each displayed "
              u"section or table.");

    args.option(u"rewrite-binary");
    args.help(u"rewrite-binary",
              u"With --binary-output, rewrite the same file with each table. "
              u"The specified file always contains one single table, the latest one.");

    args.option(u"rewrite-xml");
    args.help(u"rewrite-xml",
              u"With --xml-output, rewrite the same file with each table. "
              u"The specified file always contains one single table, the latest one.");

    args.option(u"text-output", 0, Args::STRING);
    args.help(u"text-output", u"A synonym for --output-file.");

    args.option(u"time-stamp");
    args.help(u"time-stamp", u"Display a time stamp (current local time) with each table.");

    args.option(u"ttl", 0, Args::POSITIVE);
    args.help(u"ttl",
              u"With --ip-udp, specifies the TTL (Time-To-Live) socket option. "
              u"The actual option is either \"Unicast TTL\" or \"Multicast TTL\", "
              u"depending on the destination address. Remember that the default "
              u"Multicast TTL is 1 on most systems.");

    args.option(u"xml-output", 0,  Args::STRING);
    args.help(u"xml-output", u"filename",
              u"Save the tables in XML format in the specified file. To output the XML "
              u"text on the standard output, explicitly specify this option with \"-\" "
              u"as output file name.");
}