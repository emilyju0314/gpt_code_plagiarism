BOOST_AUTO_TEST_CASE(existing_data_reindex)
{
    // We're going to share this fs::path between two wrappers
    fs::path ph = fs::temp_directory_path() / fs::unique_path();
    create_directories(ph);

    // Set up a non-obfuscated wrapper to write some initial data.
    CDBWrapper* dbw = new CDBWrapper(ph, (1 << 10), false, false, false);
    char key = 'k';
    uint256 in = InsecureRand256();
    uint256 res;

    BOOST_CHECK(dbw->Write(key, in));
    BOOST_CHECK(dbw->Read(key, res));
    BOOST_CHECK_EQUAL(res.ToString(), in.ToString());

    // Call the destructor to free leveldb LOCK
    delete dbw;

    // Simulate a -reindex by wiping the existing data store
    CDBWrapper odbw(ph, (1 << 10), false, true, true);

    // Check that the key/val we wrote with unobfuscated wrapper doesn't exist
    uint256 res2;
    BOOST_CHECK(!odbw.Read(key, res2));
    BOOST_CHECK(!is_null_key(dbwrapper_private::GetObfuscateKey(odbw)));

    uint256 in2 = InsecureRand256();
    uint256 res3;

    // Check that we can write successfully
    BOOST_CHECK(odbw.Write(key, in2));
    BOOST_CHECK(odbw.Read(key, res3));
    BOOST_CHECK_EQUAL(res3.ToString(), in2.ToString());
}