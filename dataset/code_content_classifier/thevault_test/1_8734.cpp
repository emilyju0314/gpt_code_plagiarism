KVStore(int sid, Mem* mem) : sid(sid), mem(mem) {
        uint64_t header_region = mem->kvstore_size() * HD_RATIO / 100;
        uint64_t entry_region = mem->kvstore_size() - header_region;

        // header region
        this->num_slots = header_region / sizeof(slot_t);
        this->num_buckets = wukong::math::hash_prime_u64((num_slots / ASSOCIATIVITY) * MHD_RATIO / 100);
        this->num_buckets_ext = (num_slots / ASSOCIATIVITY) - num_buckets;
        // entry region
        this->num_entries = entry_region / sizeof(ValueType);

        this->slots = reinterpret_cast<slot_t*>(mem->kvstore());
        this->values = reinterpret_cast<ValueType*>(mem->kvstore() + this->num_slots * sizeof(slot_t));

        pthread_spin_init(&this->bucket_ext_lock, 0);
        for (int i = 0; i < NUM_LOCKS; i++) {
            pthread_spin_init(&this->bucket_locks[i], 0);
        }

        // print kvstore usage
        logstream(LOG_INFO) << "[KV] kvstore = ";
        logstream(LOG_INFO) << mem->kvstore_size() << " bytes " << LOG_endl;
        logstream(LOG_INFO) << "  header region: " << this->num_slots << " slots"
                            << " (main = " << this->num_buckets
                            << ", indirect = " << this->num_buckets_ext << ")" << LOG_endl;
        logstream(LOG_INFO) << "  entry region: " << this->num_entries << " entries" << LOG_endl;
    }