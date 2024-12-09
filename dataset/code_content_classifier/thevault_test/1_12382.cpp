Motion* Importer::LoadMotion(AZStd::string filename, MotionSettings* settings)
    {
        EBUS_EVENT(AzFramework::ApplicationRequests::Bus, NormalizePathKeepCase, filename);

        // check if we want to load the motion even if a motion with the given filename is already inside the motion manager
        if (settings == nullptr || (settings && settings->m_forceLoading == false))
        {
            // search the motion inside the motion manager and return it if it already got loaded
            Motion* motion = GetMotionManager().FindMotionByFileName(filename.c_str());
            if (motion)
            {
                motion->IncreaseReferenceCount();
                MCore::LogInfo("  + Motion '%s' already loaded, returning already loaded motion from the MotionManager.", filename.c_str());
                return motion;
            }
        }

        if (GetLogging())
        {
            MCore::LogInfo("- Trying to load motion from file '%s'...", filename.c_str());
        }

        // try to open the file from disk
        MCore::DiskFile f;
        if (f.Open(filename.c_str(), MCore::DiskFile::READ) == false)
        {
            if (GetLogging())
            {
                MCore::LogError("  + Failed to open the file for motion '%s'!", filename.c_str());
            }
            return nullptr;
        }

        // retrieve the filesize
        const size_t fileSize = f.GetFileSize();

        // create a temporary buffer for the file
        uint8* fileBuffer = (uint8*)MCore::Allocate(fileSize, EMFX_MEMCATEGORY_IMPORTER);

        // read in the complete file
        f.Read(fileBuffer, fileSize);

        // close the file again
        f.Close();

        // create the motion reading from memory
        Motion* result = LoadMotion(fileBuffer, fileSize, settings);
        if (result)
        {
            result->SetFileName(filename.c_str());
        }

        // delete the filebuffer again
        MCore::Free(fileBuffer);

        // check if it worked :)
        if (result == nullptr)
        {
            if (GetLogging())
            {
                MCore::LogError("  + Failed to load motion from file '%s'", filename.c_str());
            }
        }
        else
        {
            if (GetLogging())
            {
                MCore::LogInfo("  + Loading successfully finished");
            }
        }

        // return the result
        return result;
    }