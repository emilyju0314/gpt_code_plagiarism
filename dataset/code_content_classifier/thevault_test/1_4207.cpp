Polynomial(Polynomial&& p) noexcept : degree(p.degree) {
            std::cout << "Move constructor" << std::endl;
            coefficients = std::move(p.coefficients);
            p.degree = -1; // The source must be left in an "empty" state
        }