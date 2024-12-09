void Exporter::ResetMemoryFile(MCore::MemoryFile* file)
    {
        // make sure the file is valid
        MCORE_ASSERT(file);

        // reset the incoming memory file
        file->Close();
        file->Open();
        file->SetPreAllocSize(262144); // 256kB
        file->Seek(0);
    }