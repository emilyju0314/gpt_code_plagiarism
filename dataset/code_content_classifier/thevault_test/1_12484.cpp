ArchiveTestFixture()
            : ScopedAllocatorSetupFixture(
                []() { AZ::SystemAllocator::Descriptor desc; desc.m_stackRecordLevels = 30; return desc; }()
            )
            , m_application{ AZStd::make_unique<AzFramework::Application>() }
        {
        }