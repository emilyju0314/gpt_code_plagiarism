NvDlaError Runtime::initBindableMemory()
{
    NvDlaError e = NvDlaSuccess;

    m_tensor_desc.resize(m_tensor_desc_entries.size());

    for ( size_t tdi = 0, TDI = m_tensor_desc_entries.size(); tdi != TDI; ++tdi ) {
        m_tensor_desc[tdi] = TensorDesc(m_tensor_desc_entries[tdi]);
        if ( m_tensor_desc[tdi].id != tdi ) {
            gLogInfo << "tdi != TDI " << tdi << " " << m_tensor_desc[tdi].id << endl;
        }
    }

    m_bindable_memory.resize(IOD_Max);

    for ( size_t mi = 0, MI = m_memory.size(); mi != MI; ++mi )
    {
        IOD which_iod;
        int bind_id;

        bind_id = m_memory[mi].bindId(which_iod);
        if ( bind_id == -1 ) {
            continue;
        }

        // insert and detect any duplicates
        {
            std::vector<Memory *> &which_mem = m_bindable_memory[which_iod];
            MemoryId_BindId_Is check_for_dup_id(bind_id);

            if ( which_mem.end() == std::find_if(which_mem.begin(), which_mem.end(), check_for_dup_id) ) {
                which_mem.push_back(&m_memory[mi]);
            } else {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Duplicate bind ids on separate memory objects in runtime.");
            }
        }
    }

    // it's possible that these we're given out of order.
    // sort now based upon bind id in each category.
    {
        Memory_BindId_LT_Compare less_than;
        IOD w;
        NVDLA_UNUSED(w);
        for ( size_t w = 0; w < size_t(IOD_Max); w++ )
        {
            int num_ids = int(m_bindable_memory[w].size());

            if ( ! m_bindable_memory[w].size() ) {
                continue;
            }

            std::sort(m_bindable_memory[w].begin(),  m_bindable_memory[w].end(), less_than);

            // now check to be sure there are no gaps/out-of-bounds ids
            IOD na;
            int first_id = m_bindable_memory[w][0]->bindId(na);
            int last_id  = m_bindable_memory[w][num_ids-1]->bindId(na);

            if ( (first_id != 0) || (last_id != (num_ids-1)) ) {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Out of bounds bind id on memory object");
            }
        }
    }

 fail:
    return e;
}