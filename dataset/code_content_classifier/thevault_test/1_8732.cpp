void load_attr_from_allfiles(std::vector<std::string>& fnames, std::vector<std::vector<triple_attr_t>>& triple_sav) {
        if (fnames.size() == 0)
            return;  // no attributed files

        std::sort(fnames.begin(), fnames.end());

        auto load_attr = [&](std::istream& file, int localtid) {
            sid_t s, a;
            attr_t v;
            int type;
            while (file >> s >> a >> type) {
                switch (type) {
                case INT_t: {
                    int i;
                    file >> i;
                    v = i;
                    break;
                }
                case FLOAT_t: {
                    float f;
                    file >> f;
                    v = f;
                    break;
                }
                case DOUBLE_t: {
                    double d;
                    file >> d;
                    v = d;
                    break;
                }
                default:
                    logstream(LOG_ERROR) << "Unsupported value type" << LOG_endl;
                    break;
                }

                if (sid == PARTITION(s))
                    triple_sav[localtid].push_back(triple_attr_t(s, a, v));
            }
        };

        // parallel load from all files
        int num_files = fnames.size();
        #pragma omp parallel for num_threads(Global::num_engines)
        for (int i = 0; i < num_files; i++) {
            int localtid = omp_get_thread_num();

            // load from hdfs or posix file
            std::istream* file = init_istream(fnames[i]);
            load_attr(*file, localtid);
            close_istream(file);
        }
    }