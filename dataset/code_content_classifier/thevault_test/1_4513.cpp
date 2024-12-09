void producer () {
    {
        lock_guard<mutex> lock(g_print_mutex);
        g_tid2str[this_thread::get_id()] = string("Producer");
    }
    coutln << "Starting";

    mt19937 gen(random_device{}());
    uniform_int_distribution<> dis(1, g_rbuffer.capacity() - 1);
    auto t0 = high_resolution_clock::now();
    auto pc = 0u;
    while(true) {
        if (pc < g_data_size) {
            auto ok = false;
            auto chunk_size = min((uint32_t)dis(gen), (uint32_t)(g_data_size - pc));
            if (auto wt = g_rbuffer.try_write(time_now())) {
                if (wt.push_back(chunk_size) &&
                    wt.push_back(g_data.get() + pc, chunk_size)) {
                    pc += chunk_size;
                    ok = true;
                } else {
                    wt.invalidate();
                }
            }

            if (!ok) {
                g_failed_writes++;
            }

        } else if (auto wt = g_rbuffer.try_write(time_now())) {
            if (wt.push_back(0xFFffFFff)) {
                break; // Final transaction
            }
            wt.invalidate();
        }
    }

    auto ns = duration_cast<nanoseconds>(high_resolution_clock::now() - t0).count();
    coutln << "Transfer speed = " << dec << (((double)g_data_size / 1_MiB) / (ns / 1000000000.0)) << " MiB/sec";
}