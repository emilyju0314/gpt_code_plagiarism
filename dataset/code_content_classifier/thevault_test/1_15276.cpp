memory::MemoryResolver::MemoryResolver() :
    ast::GraphVisitor<engine_ast::Graph>(),
    m_useMemPool(false),
    m_useReusePooledMemory(false),
    m_useGreedyEviction(false),
    m_useCVSRAM(false),
    m_pools(NULL),
    m_localCVSRAM(NULL),
    m_localSDRAM(NULL),
    m_globalSDRAM(NULL),
    m_debug(false),
    m_inLocalPool()
{

}