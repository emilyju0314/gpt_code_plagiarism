VQ_quantizer::VQ_quantizer(size_t dimension, size_t nc_upper, size_t max_nc_per_group, size_t M, size_t efConstruction, bool use_HNSW):
        Base_quantizer(dimension, nc_upper, max_nc_per_group){
            this->use_HNSW = use_HNSW;
            this->M = M;
            this->efConstruction = efConstruction;

            this->exact_nc_in_groups.resize(nc_upper);

            if (this->use_HNSW){
                this->HNSW_quantizers.resize(nc_upper);
            }
            else{
                this->L2_quantizers.resize(nc_upper);
            }
        }