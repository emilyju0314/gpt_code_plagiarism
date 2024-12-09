void init_options_desc()
{
    // e.g., wukong> help
    all_desc.add(help_desc);

    // e.g., wukong> quit
    all_desc.add(quit_desc);

    // e.g., wukong> config <args>
    config_desc.add_options()
    (",v", "print current config")
    (",l", value<std::string>()->value_name("<fname>"), "load config items from <fname>")
    (",s", value<std::string>()->value_name("<string>"), "set config items by <str> (e.g., item1=val1&item2=...)")
    ("help,h", "help message about config")
    ;
    all_desc.add(config_desc);

    // e.g., wukong> logger <args>
    logger_desc.add_options()
    (",v", "print loglevel")
    (",s", value<int>()->value_name("<level>"), "set loglevel to <level> (e.g., DEBUG=1, INFO=2, WARNING=4, ERROR=5)")
    ("help,h", "help message about logger")
    ;
    all_desc.add(logger_desc);

    // e.g., wukong> sparql <args>
    sparql_desc.add_options()
    (",f", value<std::string>()->value_name("<fname>"), "run a [single] SPARQL query from <fname>")
    (",m", value<int>()->default_value(1)->value_name("<factor>"), "set multi-threading <factor> for heavy query processing")
    (",n", value<int>()->default_value(1)->value_name("<num>"), "repeat query processing <num> times")
    (",p", value<std::string>()->value_name("<fname>"), "adopt user-defined query plan from <fname> for running a single query")
    (",N", value<int>()->default_value(1)->value_name("<num>"), "do query optimization <num> times")
    (",v", value<int>()->default_value(0)->value_name("<lines>"), "print at most <lines> of results")
    (",o", value<std::string>()->value_name("<fname>"), "output results into <fname>")
    (",g", "leverage GPU to accelerate heavy query processing ")
    (",b", value<std::string>()->value_name("<fname>"), "run a [batch] of SPARQL queries configured by <fname>")
    ("help,h", "help message about sparql")
    ;
    all_desc.add(sparql_desc);

    // e.g., wukong> sparql-emu <args>
    sparql_emu_desc.add_options()
    (",f", value<std::string>()->value_name("<fname>"), "run queries generated from temples configured by <fname>")
    (",p", value<std::string>()->value_name("<fname>"), "adopt user-defined query plans from <fname> for running queries")
    (",d", value<int>()->default_value(10)->value_name("<sec>"), "eval <sec> seconds (default: 10)")
    (",w", value<int>()->default_value(5)->value_name("<sec>"), "warmup <sec> seconds (default: 5)")
    (",n", value<int>()->default_value(20)->value_name("<num>"), "keep <num> queries being processed (default: 20)")
    ("help,h", "help message about sparql-emu")
    ;
    all_desc.add(sparql_emu_desc);

    // e.g., wukong> load <args>
    load_desc.add_options()
    (",d", value<std::string>()->value_name("<dname>"), "load data from directory <dname>")
    (",c", "check and skip duplicate RDF triples")
    ("help,h", "help message about load")
    ;
    all_desc.add(load_desc);

    // e.g., wukong> gsck <args>
    gsck_desc.add_options()
    (",i", "check from index key/value pair to normal key/value pair")
    (",n", "check from normal key/value pair to index key/value pair")
    ("help,h", "help message about gsck")
    ;
    all_desc.add(gsck_desc);

    // e.g., wukong> load-stat
    load_stat_desc.add_options()
    (",f", value<std::string>()->value_name("<fname>"), "load statistics from <fname> located at data folder")
    ("help,h", "help message about load-stat")
    ;
    all_desc.add(load_stat_desc);

    // e.g., wukong> store-stat
    store_stat_desc.add_options()
    (",f", value<std::string>()->value_name("<fname>"), "store statistics to <fname> located at data folder")
    ("help,h", "help message about store-stat")
    ;
    all_desc.add(store_stat_desc);
}