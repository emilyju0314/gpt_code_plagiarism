bool
nmap_is_ok() {
    return (
        (system("dpkg -l | cut -c 5-9 | grep nmap") == 0)
        && launch_command("mkdir -p /tmp/scans")); // Creates the directory in which the scans will be stored
}