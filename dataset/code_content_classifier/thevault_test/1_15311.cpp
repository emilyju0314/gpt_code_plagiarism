bool Runtime::bindInputTensor(int index, void *hMem)
{
    std::vector<Memory *>bind_to_mem;
    bool ok = true;
    if ( index < 0 ) {
        ok = false;
        goto done;
    }

    // determine which mem needs to be rebound
    for ( size_t mi = 0, MI = m_memory.size(); mi != MI; ++mi ) {
        if ( m_memory[mi].inputBindId() == index ) {
            bind_to_mem.push_back( &m_memory[mi] );
        }
    }

    // unlikely to be > size 1, but...
    for (size_t bmi = 0, BMI = bind_to_mem.size(); bmi != BMI; ++bmi ) {
        bind_to_mem[bmi]->setHandle(hMem);
        bind_to_mem[bmi]->setVirtAddr(m_hmem_memory_map[hMem]);
    }

 done:
    return ok;
}