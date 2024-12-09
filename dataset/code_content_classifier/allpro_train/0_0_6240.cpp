#include <iostream>
#include <deque>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::deque<int> dq;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        dq.push_back(x);
    }

    int A = dq.front();
    int B = dq[1];

    for(int i = 0; i < q; i++) {
        long long mj;
        std::cin >> mj;

        if(mj <= 2) {
            std::cout << A << " " << B << std::endl;
        } else {
            long long steps = mj % (n - 1);
            if(steps == 0) steps = n - 1;

            for(int j = 0; j < steps; j++) {
                if(A > B) {
                    int temp = A;
                    A = dq.front();
                    dq.pop_front();
                    dq.push_back(temp);
                } else {
                    int temp = B;
                    B = dq.front();
                    dq.pop_front();
                    dq.push_back(temp);
                }
            }

            std::cout << A << " " << B << std::endl;
        }
    }

    return 0;
}