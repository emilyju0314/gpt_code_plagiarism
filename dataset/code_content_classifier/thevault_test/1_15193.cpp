kaldi::CuSubVector<kaldi::BaseFloat> TensorToKaldiCuSubVector(torch::Tensor &t) {
    if(kaldi::CuDevice::Instantiate().Enabled()) {
        if(t.is_contiguous())  {
            kaldi::CuSubVector<kaldi::BaseFloat> kvec((kaldi::BaseFloat *)t.data_ptr(), t.size(0));
            return kvec;
        }
    }
    else {
        // we can't really do much b/c we don't have GPU
        // TODO: we need to make sure t is in CPU else raise an exception. right now the code
        // below is really not what the user expects to happen b/c if t is not already in CPU
        // we return an object that is pointing to a completely different tensor
        auto t_cpu = t.to(torch::kCPU);
        if(t.is_contiguous())  {
            kaldi::CuSubVector<kaldi::BaseFloat> cukvec((kaldi::BaseFloat *)t_cpu.data_ptr(), t_cpu.size(0));
            return cukvec;
        }
    }
}