void mult_partial(std::vector<torch::Tensor>& arg1, const std::vector<torch::Tensor>& arg2,
                              torch::Scalar scalar_term_value, s_size_type top_terms_to_skip) {
                auto depth = arg1.size();
                for (s_size_type depth_index = depth - top_terms_to_skip - 1; depth_index >= 0; --depth_index) {
                    torch::Tensor tensor_at_depth = arg1[depth_index];

                    // corresponding to the zero scalar assumed to be associated with arg2
                    tensor_at_depth.zero_();

                    detail::mult_inner(tensor_at_depth, arg1, arg2, depth_index);

                    tensor_at_depth.add_(arg2[depth_index], scalar_term_value);
                }
            }