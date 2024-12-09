explicit            quaternion( ::std::complex<T> const & z0,
                                            ::std::complex<T> const & z1 = ::std::complex<T>())
            :   a(z0.real()),
                b(z0.imag()),
                c(z1.real()),
                d(z1.imag())
            {
                // nothing to do!
            }