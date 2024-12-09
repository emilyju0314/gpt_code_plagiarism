void consumer() {
    {
        lock_guard<mutex> lock(g_print_mutex);
        g_tid2str[this_thread::get_id()] = string("Consumer");
    }
    coutln << "Starting";

    const auto process_chunk = [&](auto _buff, auto _len) { 
        g_consumer_hash = crc32(_buff, _len, g_consumer_hash); 
    };

    auto t0 = high_resolution_clock::now();
    while (true) {
        if (auto rt = g_rbuffer.try_read()) {
            if (auto [tsize, ok] = rt.pop_front<uint32_t>(); ok) {
                if (tsize == 0xFFffFFff) {
                    break; // Done!
                } else if (!rt.pop_front(tsize, process_chunk)) {
                    return; // Error!
                }
            } else {
                return; // Error!
            }
        } else {
            g_failed_reads++;
        }
    }

    g_consumer_hash = g_consumer_hash ^ 0xFFffFFff;

    auto ns = duration_cast<nanoseconds>(high_resolution_clock::now() - t0).count();
    coutln << "Read/process speed = " << dec << (((double)g_data_size / 1_MiB) / (ns / 1000000000.0)) << " MiB/sec";
}