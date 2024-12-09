void CameraConnector::connectCameras(int number, int type)
{
    switch (type)
    {
    case 1:
    {
        RSCameraHandler* newCamera = new RSCameraHandler();
        if (newCamera->getPipeRunning()) {
            std::thread camThread(threadFunc, newCamera);
            camThread.detach();
            connectedCams.insert(connectedCams.begin() + number, newCamera);
        } else {
            std::cout << "RS camera handler failed to initialize!" << std::endl;
        }
        break;
    }
    case 2:
        //zed
        break;

    case 3:
        //other
        break;

    default:
        break;
    }
}