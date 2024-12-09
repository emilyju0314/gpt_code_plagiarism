AZStd::unique_ptr<Actor> Importer::LoadActor(MCore::File* f, ActorSettings* settings, const char* filename)
    {
        MCORE_ASSERT(f);
        MCORE_ASSERT(f->GetIsOpen());

        // create the shared data
        AZStd::vector<SharedData*> sharedData;
        PrepareSharedData(sharedData);

        // verify if this is a valid actor file or not
        MCore::Endian::EEndianType endianType = MCore::Endian::ENDIAN_LITTLE;
        if (CheckIfIsValidActorFile(f, &endianType) == false)
        {
            MCore::LogError("The specified file is not a valid EMotion FX actor file!");
            ResetSharedData(sharedData);
            f->Close();
            return nullptr;
        }

        // copy over the actor settings, or use defaults
        ActorSettings actorSettings;
        if (settings)
        {
            actorSettings = *settings;
        }

        if (actorSettings.m_optimizeForServer)
        {
            actorSettings.OptimizeForServer();
        }

        // fix any possible conflicting settings
        ValidateActorSettings(&actorSettings);

        // create the actor
        AZStd::unique_ptr<Actor> actor = AZStd::make_unique<Actor>("Unnamed actor");
        MCORE_ASSERT(actor);

        if (actor)
        {
            actor->SetThreadIndex(actorSettings.m_threadIndex);

            // set the scale mode
            // actor->SetScaleMode( scaleMode );

            // init the import parameters
            ImportParameters params;
            params.m_sharedData = &sharedData;
            params.m_endianType = endianType;
            params.m_actorSettings = &actorSettings;
            params.m_actor = actor.get();

            // process all chunks
            while (ProcessChunk(f, params))
            {
            }

            actor->SetFileName(filename);

            // Generate an optimized version of skeleton for server.
            if (actorSettings.m_optimizeForServer && actor->GetOptimizeSkeleton())
            {
                actor->GenerateOptimizedSkeleton();
            }

            // post create init
            actor->PostCreateInit(actorSettings.m_makeGeomLoDsCompatibleWithSkeletalLoDs, actorSettings.m_unitTypeConvert);
        }

        // close the file and return a pointer to the actor we loaded
        f->Close();

        // get rid of shared data
        ResetSharedData(sharedData);
        sharedData.clear();

        // return the created actor
        return actor;
    }