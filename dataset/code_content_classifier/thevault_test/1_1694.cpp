bool
mapping::run() const {
    if (nmap_is_ok()) {
        std::string target = this->conf.target;
        std::replace(target.begin(), target.end(), ',', ' ');
        LOG_INFO_("Nmap 6.0 or greater found", "mapping");
        LOG_INFO_("Beginning mapping task. This may take a while.", "mapping");
        std::string cmd =
            "nmap -T4 -A " + target + " -p " + this->conf.ports + " -oX " + nmap_output;
        LOG_DEBUG_("Launching nmap : " + cmd, "mapping");
        bool ret = launch_command(cmd);
        if (ret)
            LOG_INFO_("Nmap XML output successfully generated in file: " + nmap_output, "mapping");
        else
            LOG_ERR_("Nmap command failed", "mapping");
        return ret;
    } else {
        LOG_ERR_("Nmap 6.0 or greater is required to launch Cameradar", "mapping");
        return false;
    }
}