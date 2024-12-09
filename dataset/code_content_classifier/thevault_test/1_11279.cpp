explicit inline hyperloglog(size_t b = 16):
      m_b(b), m_m(1 << b), m_buckets(m_m, 0) {
     ASSERT_GE(m_m, 16);
      // constants from SFlajolet et al. Fig 3
     switch(m_m) {
      case 16:
       m_alpha = 0.673;
       break;
      case 32: 
       m_alpha = 0.697;
       break;
      case 64: 
       m_alpha = 0.709;
       break;
      default:
       m_alpha = 0.7213 / (1 + 1.079 / (double)m_m);
     }
   }