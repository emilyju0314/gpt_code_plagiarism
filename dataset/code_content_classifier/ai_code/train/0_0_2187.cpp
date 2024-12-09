#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;

vector<int> virus_lengths(101, -1); // stores the minimum length of undetectable virus for each gene

void check_virus(int gene, map<int, vector<vector<int>>>& mutations, vector<string>& antibodies) {
    unordered_set<string> detected_viruses;

    for (int i = 0; i < mutations[gene].size(); i++) {
        vector<int> current_mut = mutations[gene][i];

        string current_virus = "";
        for (int j = 0; j < current_mut.size(); j++) {
            current_virus += to_string(current_mut[j]);
        }

        detected_viruses.insert(current_virus);
    }

    for (int i = 0; i < antibodies.size(); i++) {
        string antibody = antibodies[i];

        for (auto virus = detected_viruses.begin(); virus != detected_viruses.end(); ) {
            if (virus->find(antibody) != string::npos) {
                virus = detected_viruses.erase(virus);
            } else {
                virus++;
            }
        }
    }

    if (!detected_viruses.empty()) {
        int min_length = INT_MAX;
        for (auto virus : detected_viruses) {
            if (virus.length() < min_length) {
                min_length = virus.length();
            }
        }

        virus_lengths[gene] = min_length;
    } else {
        virus_lengths[gene] = 0;
    }
}

int main() {
    int G, N, M;
    cin >> G >> N >> M;

    map<int, vector<vector<int>>> mutations;
    for (int i = 0; i < N; i++) {
        int a, k;
        cin >> a >> k;
        vector<int> genes(k, 0);
        for (int j = 0; j < k; j++) {
            cin >> genes[j];
        }
        mutations[a].push_back(genes);
    }

    vector<string> antibodies;
    for (int i = 0; i < M; i++) {
        int l;
        cin >> l;
        string antibody = "";
        for (int j = 0; j < l; j++) {
            int c;
            cin >> c;
            antibody += to_string(c);
        }
        antibodies.push_back(antibody);
    }

    for (int gene = 2; gene <= G-1; gene++) {
        check_virus(gene, mutations, antibodies);
    }

    for (int i = 2; i <= G-1; i++) {
        if (virus_lengths[i] == -1) {
            cout << "YES" << endl;
        } else {
            cout << "NO " << virus_lengths[i] + 1 << endl;
        }
    }

    return 0;
}