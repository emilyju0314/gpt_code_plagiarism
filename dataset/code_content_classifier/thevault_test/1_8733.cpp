void load_triples_from_all(std::vector<std::string>& dfiles,
                               std::vector<std::vector<triple_t>>& triple_pso,
                               std::vector<std::vector<triple_t>>& triple_pos) {
        // read_partial_exchange: load partial input files by each server and exchanges triples
        //            according to graph partitioning
        // read_all_files: load all files by each server and select triples
        //                          according to graph partitioning
        //
        // Trade-off: read_all_files avoids network traffic and memory,
        //            but it requires more I/O from distributed FS.
        //
        // Wukong adopts read_all_files for slow network (w/o RDMA) and
        //        adopts read_partial_exchange for fast network (w/ RDMA).
        uint64_t start = timer::get_usec();
        int num_partitons = 0;
        if (Global::use_rdma)
            num_partitons = read_partial_exchange(dfiles);
        else
            num_partitons = read_all_files(dfiles);
        uint64_t end = timer::get_usec();
        logstream(LOG_INFO) << "[Loader] #" << sid << ": " << (end - start) / 1000 << " ms "
                            << "for loading data files" << LOG_endl;

        // all triples are partitioned and temporarily stored in the kvstore on each server.
        // the kvstore is split into num_partitions partitions, each contains #triples and triples
        //
        // Wukong aggregates all triples before finally inserting them to gstore (kvstore)
        start = timer::get_usec();
        aggregate_data(num_partitons, triple_pso, triple_pos);
        end = timer::get_usec();
        logstream(LOG_INFO) << "[Loader] #" << sid << ": " << (end - start) / 1000 << " ms "
                            << "for aggregrating triples" << LOG_endl;
    }