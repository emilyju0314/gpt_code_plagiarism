#include <iostream>
#include <bitset>

int main() {
    int q;
    std::cin >> q;

    std::bitset<64> flags;

    for (int i = 0; i < q; ++i) {
        int op, index;
        std::cin >> op >> index;

        if (op == 0) {
            // test(i)
            std::cout << flags[index] << std::endl;
        } else if (op == 1) {
            // set(i)
            flags.set(index);
        } else if (op == 2) {
            // clear(i)
            flags.reset(index);
        } else if (op == 3) {
            // flip(i)
            flags.flip(index);
        } else if (op == 4) {
            // all
            std::cout << flags.all() << std::endl;
        } else if (op == 5) {
            // any
            std::cout << flags.any() << std::endl;
        } else if (op == 6) {
            // none
            std::cout << flags.none() << std::endl;
        } else if (op == 7) {
            // count
            std::cout << flags.count() << std::endl;
        } else if (op == 8) {
            // val
            std::cout << flags.to_ulong() << std::endl;
        }
    }

    return 0;
}