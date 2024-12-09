int hash_password(TestConnections* test)
{
    test->maxscale->stop();

    test->tprintf("Creating a new encrypted password\n");
    auto res = test->maxscale->ssh_output("maxpasswd /var/lib/maxscale/ skysql");

    std::string enc_pw = res.output;
    auto pos = enc_pw.find('\n');
    if (pos != std::string::npos)
    {
        enc_pw = enc_pw.substr(0, pos);
    }

    test->tprintf("Encrypted password is: %s\n", enc_pw.c_str());
    test->maxscale->ssh_node_f(true,
                               "sed -i -e 's/password[[:space:]]*=[[:space:]]*skysql/password=%s/' /etc/maxscale.cnf",
                               enc_pw.c_str());

    test->tprintf("Starting MaxScale\n");
    test->maxscale->start_maxscale();

    test->tprintf("Checking if MaxScale is alive\n");
    return test->check_maxscale_alive();
}