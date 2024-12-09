TEST_F(FeatureProcessorFactoryTests, CreateFeatureProcessor_MultipleImplmentationsOfTheSameInterface_CreatesBothFeatureProcessors)
    {
        FeatureProcessorPtr implementation1 = FeatureProcessorFactory::Get()->CreateFeatureProcessor(FeatureProcessorId{ TestFeatureProcessorImplementation::RTTI_TypeName() });
        FeatureProcessorPtr implementation2 = FeatureProcessorFactory::Get()->CreateFeatureProcessor(FeatureProcessorId{ TestFeatureProcessorImplementation2::RTTI_TypeName() });
        EXPECT_TRUE(implementation1 != nullptr);
        EXPECT_TRUE(implementation2 != nullptr);
        EXPECT_NE(implementation1, implementation2);
    }