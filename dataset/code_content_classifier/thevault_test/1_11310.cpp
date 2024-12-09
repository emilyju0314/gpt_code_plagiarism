map_reduce_type(EdgeMapperType map_edge_function,
                      FinalizerType finalize_function,
                      bool)
                : map_edge_function(map_edge_function),
                finalize_function(finalize_function), vertex_map(false) { }