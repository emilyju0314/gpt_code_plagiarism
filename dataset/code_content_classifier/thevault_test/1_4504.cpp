int create_key(TestConnections* test)
{
    int res = 0;
    test->tprintf("Creating new encryption keys\n");
    test->maxscale->ssh_node(
        "test -f /var/lib/maxscale/.secrets && sudo rm /var/lib/maxscale/.secrets",
        true);
    test->maxscale->ssh_node("maxkeys", true);
    auto result = test->maxscale->ssh_output("sudo test -f /var/lib/maxscale/.secrets && echo SUCCESS",
                                             false);

    if (strncmp(result.output.c_str(), "SUCCESS", 7) != 0)
    {
        test->tprintf("FAILURE: /var/lib/maxscale/.secrets was not created\n");
        res = 1;
    }
    else
    {
        test->maxscale->ssh_node("sudo chown maxscale:maxscale /var/lib/maxscale/.secrets", true);
    }
    return res;
}