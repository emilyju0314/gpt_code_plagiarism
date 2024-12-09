void BaseBranchFactory::playPipeline()
{
    BOOST_ASSERT(m_pipeline);
    m_pipeline->play();
}