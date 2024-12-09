edge_scope(vertex_data* source, vertex_data* target, edge_data* edge,
             graphlab::mutex* lock_0=NULL,
             graphlab::mutex* lock_1=NULL) :
      m_source(source), m_target(target), m_edge(edge),
      m_lock_0(lock_0), m_lock_1(lock_1) { }