updater_sub_context(Layer& layer) : grad(std::get<I>(layer.trainable_parameters())), m(grad), mt(grad), v(grad), vt(grad) {
        grad = 0;
        m = 0;
        mt = 0;
        v = 0;
        vt = 0;
    }