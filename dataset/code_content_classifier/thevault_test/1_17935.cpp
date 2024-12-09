auto ProcWatch::listRunningProcs() noexcept -> vector<string>
{
        // scan /proc/PID/comms for list of viable targets
        comms = scan_proc();

        // RAII lock for reads
        std::shared_lock <std::shared_mutex> lock(write);

        // move elements of comms set into vector
        vector <string> res(comms.begin(), comms.end());
        // sort for user output
        std::sort(res.begin(), res.end());
        return res;
}