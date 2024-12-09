#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int price;
    int genre;
};

bool compare(Book &a, Book &b) {
    return a.price < b.price;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Book> books(N);
    for(int i = 0; i < N; i++) {
        cin >> books[i].price >> books[i].genre;
    }

    sort(books.begin(), books.end(), compare);

    int totalPurchasePrice = 0;
    vector<int> soldGenres(10, 0);
    for(int i = 0; i < K; i++) {
        totalPurchasePrice += books[i].price + soldGenres[books[i].genre - 1];
        soldGenres[books[i].genre - 1]++;
    }

    cout << totalPurchasePrice << endl;

    return 0;
}