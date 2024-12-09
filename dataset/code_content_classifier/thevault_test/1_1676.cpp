Bucket::OutputIterator::OutputIterator(std::string const& tmpDir,
                                       bool keepDeadEntries)
    : mFilename(randomBucketName(tmpDir))
    , mBuf(nullptr)
    , mHasher(SHA256::create())
    , mKeepDeadEntries(keepDeadEntries)
{
    CLOG(TRACE, "Bucket") << "Bucket::OutputIterator opening file to write: "
                          << mFilename;
    mOut.open(mFilename);
}