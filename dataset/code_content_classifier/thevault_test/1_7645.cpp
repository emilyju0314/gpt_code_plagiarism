size_t danscalarintersectioncardinality(const uint32_t * set1, const size_t length1,
        const uint32_t * set2, const size_t length2) {
    if ((0 == length1) or (0 == length2))
        return 0;
    size_t answer = 0;
    size_t k1 = 0, k2 = 0;
    while (true) {
        if (set1[k1] < set2[k2]) {
            do {
                ++k1;
                if (k1 == length1)
                    return answer;
            } while (set1[k1] < set2[k2]);
        }
        if (set2[k2] < set1[k1]) {

            do {
                ++k2;
                if (k2 == length2)
                    return answer;
            } while (set2[k2] < set1[k1]);
        } else {
            // assert(set2[k2] == set1[k1]);
            ++answer;
            ++k1;
            if (k1 == length1)
                break;
            ++k2;
            if (k2 == length2)
                break;
        }
    }
    return answer;
}