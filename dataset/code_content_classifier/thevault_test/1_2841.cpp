CameraConnector *CameraConnector::getInstance()
{
    if (pSingleton == NULL)
    {
        pSingleton = new CameraConnector();
    }
    return pSingleton;
}