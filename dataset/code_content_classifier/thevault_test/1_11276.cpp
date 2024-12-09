inline static size_t hash_edge (const std::pair<vertex_id_type, vertex_id_type>& e, const uint32_t seed = 5) {
      // a bunch of random numbers
#if (__SIZEOF_PTRDIFF_T__ == 8)
      static const size_t a[8] = {0x6306AA9DFC13C8E7,
        0xA8CD7FBCA2A9FFD4,
        0x40D341EB597ECDDC,
        0x99CFA1168AF8DA7E,
        0x7C55BCC3AF531D42,
        0x1BC49DB0842A21DD,
        0x2181F03B1DEE299F,
        0xD524D92CBFEC63E9};
#else
      static const size_t a[8] = {0xFC13C8E7,
        0xA2A9FFD4,
        0x597ECDDC,
        0x8AF8DA7E,
        0xAF531D42,
        0x842A21DD,
        0x1DEE299F,
        0xBFEC63E9};
#endif
      vertex_id_type src = e.first;
      vertex_id_type dst = e.second;
      return (integer_mix(src^a[seed%8]))^(integer_mix(dst^a[(seed+1)%8]));
    }