updater_sub_context(Layer& layer) : grad(std::get<I>(layer.trainable_parameters())), inc(grad), inc_prev(grad) {
        grad = 0;
        inc = 0;
        inc_prev = 0;
    }