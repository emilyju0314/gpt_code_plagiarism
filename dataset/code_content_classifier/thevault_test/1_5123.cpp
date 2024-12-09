void ThreadTest::testMutexRecursion()
{
    ts::Mutex mutex;

    TSUNIT_ASSERT(!mutex.release());

    TSUNIT_ASSERT(mutex.acquire());
    TSUNIT_ASSERT(mutex.acquire());
    TSUNIT_ASSERT(mutex.acquire());

    TSUNIT_ASSERT(mutex.release());
    TSUNIT_ASSERT(mutex.release());
    TSUNIT_ASSERT(mutex.release());

    TSUNIT_ASSERT(!mutex.release());
    TSUNIT_ASSERT(!mutex.release());
}