PQ_quantizer::PQ_quantizer(size_t dimension, size_t nc_upper, size_t M, size_t max_nbits):
        Base_quantizer(dimension, nc_upper, new_pow(2, max_nbits*M)), M(M), max_nbits(max_nbits){

            this->max_ksub = new_pow(2, max_nbits);
            this->dsub = dimension / M;
            this->exact_ksubs.resize(nc_upper);
            this->exact_nbits.resize(nc_upper);
        }