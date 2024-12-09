int DataManager::startThreads(int argc, char **argv) 
{
    arena.enqueue( [&] 
    {
        dataMain();
    });
    return 1;
}