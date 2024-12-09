#include <iostream>
#include <cmath>

int main() {
    int x_ic, y_ic, x_pc, y_pc, x_acm, y_acm;
    int seq_num = 1;

    while (true) {
        std::cin >> x_ic >> y_ic >> x_pc >> y_pc >> x_acm >> y_acm;
        
        if (x_ic == 0 && y_ic == 0 && x_pc == 0 && y_pc == 0 && x_acm == 0 && y_acm == 0) {
            break;
        }

        double dist_ic = sqrt((x_ic - x_pc) * (x_ic - x_pc) + (y_ic - y_pc) * (y_ic - y_pc));
        double dist_pc = sqrt((x_pc - x_acm) * (x_pc - x_acm) + (y_pc - y_acm) * (y_pc - y_acm));
        double dist_acm = sqrt((x_acm - x_ic) * (x_acm - x_ic) + (y_acm - y_ic) * (y_acm - y_ic));

        double total_dist = dist_ic + dist_pc + dist_acm;

        double probability_ic = (total_dist - dist_pc) * (total_dist - dist_acm) / (total_dist * total_dist);

        std::cout << seq_num << " " << std::fixed << probability_ic << std::endl;

        seq_num++;
    }

    return 0;
}