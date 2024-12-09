updater_sub_context(Layer& layer) : grad(std::get<I>(layer.trainable_parameters())), g(grad), x(grad), v(grad) {
        grad = 0;
        g = 0;
        x = 0;
        v = 0;
    }