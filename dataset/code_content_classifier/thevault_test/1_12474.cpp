physx::PxCookingParams GetRealTimeCookingParams()
        {
            physx::PxCookingParams params{ physx::PxTolerancesScale() };
            // disable mesh cleaning - perform mesh validation on development configurations
            params.meshPreprocessParams |= physx::PxMeshPreprocessingFlag::eDISABLE_CLEAN_MESH;
            // disable edge pre-compute, edges are set for each triangle, slows contact generation
            params.meshPreprocessParams |= physx::PxMeshPreprocessingFlag::eDISABLE_ACTIVE_EDGES_PRECOMPUTE;

            return params;
        }