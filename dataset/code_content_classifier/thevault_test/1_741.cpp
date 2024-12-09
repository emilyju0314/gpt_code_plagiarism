QByteArray DownloadExtractThread::_popQueue()
{
    std::unique_lock<std::mutex> lock(_queueMutex);

    _cv.wait(lock, [this]{
            return _queue.size() != 0;
    });

    QByteArray result = _queue.front();
    _queue.pop_front();

    if (_queue.size() == (MAX_QUEUE_SIZE-1))
    {
        lock.unlock();
        _cv.notify_one();
    }

    return result;
}