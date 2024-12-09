inline long long shanks(long long n){
        auto find_factor = [n](const long long k)->long long{
            long long p, q, b, x, old_p, old_q, sqrt_q, sqrt_kn;

            p = sqrt_kn = isqrt(k * n);
            q = k * n - p * p, old_p = old_q = 1;
            if (q == 0) return (k == 1) ? p : 1;

            auto update = [&]{
                old_p = p;
                b = (sqrt_kn + old_p) / q, p = b * q - old_p;
                x = q, q = old_q + b * (old_p - p), old_q = x;
            };
            for (int i = 1; (i & 1) || !is_square(q); i++) update();

            sqrt_q = isqrt(q), b = (sqrt_kn - p) / sqrt_q;
            p = b * sqrt_q + p, old_q = sqrt_q, q = (k * n - p * p) / old_q;

            do{
                update();
            } while (p != old_p);
            return __gcd(n, p);
        };

        const long long lim = std::numeric_limits <long long>::max() / n;
        for (long long k = 1; k <= lim; k++){
            long long f = find_factor(k);
            if (f != 1 && f != n) return f;
        }

        throw std::overflow_error("Shanks overflow error!\n");
        return -1;
    }