Instruction* TraceProcessor::fetch ( void )
{
    if(m_next_inst_idx < m_num_inst) {
	Instruction* inst = m_instructions[m_next_inst_idx++];
	return inst;
    }

    //no more left in m_instructions, get more if any.

    if(!m_trace_file.is_open()) //file closed, meaning no more to read.
        return 0;


    //Read BUF_SIZE instructions or until end of file, whichever comes first.
    string line;
    int nline=0;
    while(nline < BUF_SIZE && getline(m_trace_file, line) ) {
	istringstream strin(line);

	uint64_t c;
	strin >>hex>> c >>dec;
	if(c == 0x0) {
	    uint64_t a;
	    strin >>hex>> a >>dec;
	    m_instructions[nline] = new Instruction(Instruction::OpMemLd, a);
	}
	else if(c == 0x1) {
	    uint64_t a;
	    strin >>hex>> a >>dec;
	    m_instructions[nline] = new Instruction(Instruction::OpMemSt, a);
	}
	else {
	    m_instructions[nline] = new Instruction(Instruction::OpNop);
	}

	nline++;
    }

    if(m_trace_file.eof()) {
        m_trace_file.close();
    }

    m_num_inst = nline;
    m_next_inst_idx = 0;
    if(m_next_inst_idx < m_num_inst) {
	Instruction* inst = m_instructions[m_next_inst_idx++];
	return inst;
    }
    else
        return 0;
}