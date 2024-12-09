void mult_inner_backward(torch::Tensor grad_tensor_at_depth,
                                     std::vector<torch::Tensor>& grad_arg1,
                                     std::vector<torch::Tensor>& grad_arg2,
                                     const std::vector<torch::Tensor> arg1,
                                     const std::vector<torch::Tensor> arg2,
                                     s_size_type depth_index) {
                for (s_size_type j = depth_index - 1, k = 0; j >= 0; --j, ++k) {
                    /* loop invariant: j + k = depth_index - 1 */
                    torch::Tensor out_view = grad_tensor_at_depth.view({arg1[j].size(batch_dim),
                                                                        arg1[j].size(channel_dim),
                                                                        arg2[k].size(channel_dim)});

                    grad_arg1[j].unsqueeze(channel_dim).baddbmm_(out_view, arg2[k].unsqueeze(channel_dim));
                    grad_arg2[k].unsqueeze(channel_dim - 1).baddbmm_(arg1[j].unsqueeze(channel_dim - 1), out_view);
                }
            }