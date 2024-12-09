void Display::setStatus(const std::string statusName, const eu::nifti::ocu::StatusLevel& level, const std::string& msg)
    {
        statuses.insert(std::pair<std::string, eu::nifti::ocu::AnnotatedStatusLevel > (statusName, eu::nifti::ocu::AnnotatedStatusLevel(level, msg)));
        
//        if(level == eu::nifti::ocu::STATUS_LEVEL_ERROR)
//        {
//            ROS_ERROR_STREAM("Error with display status '" << statusName << "': " << msg);
//        }
    }