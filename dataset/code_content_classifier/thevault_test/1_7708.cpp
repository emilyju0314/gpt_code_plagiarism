updater_sub_context(Layer& layer) : grad(std::get<I>(layer.trainable_parameters())), m(grad), v(grad) {
        grad = 0;
        m = 0;
        v = 0;
    }