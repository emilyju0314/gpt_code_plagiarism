const physx::PxActor* GetPxActor(const AzPhysics::SimulatedBody* simBody)
        {
            const AZ::Crc32& nativeType = simBody->GetNativeType();
            if (nativeType != NativeTypeIdentifiers::RigidBody &&
                nativeType != NativeTypeIdentifiers::RigidBodyStatic)
            {
                return nullptr;
            }

            return static_cast<physx::PxActor*>(simBody->GetNativePointer());
        }