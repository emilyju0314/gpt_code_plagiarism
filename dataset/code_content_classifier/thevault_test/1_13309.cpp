void BaseBranchFactory::pausePipeline()
{
    BOOST_ASSERT(m_pipeline);
    m_pipeline->pause();
}