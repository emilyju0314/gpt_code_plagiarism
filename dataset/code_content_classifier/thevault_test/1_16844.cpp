void Server::actions(Commands& cmd) {

    switch(cmd) {


            //SlamMap
        case START_STREAM_MAP: {
            std::cout << "Start Stream Map!" << std::endl;
            slamMap_.startSendSlamMap(*sock);
        }
            break;

        case STOP_STREAM_MAP:
            std::cout << "Stop Stream Map!" << std::endl;
            slamMap_.stopSendSlamMap();
            break;

        case SAVE_MAP: {
            std::cout << "Save SLAM Map" << std::endl;
            slamMap_.setSaveMap(true);
        }
            break;

        case RESET_MAP: {
            std::cout << "Reset SLAM Map" << std::endl;
            slamMap_.resetMap();
        }
            break;


        default:
            std::cout << "Default in method Server::actions!" << std::endl;
    }
}