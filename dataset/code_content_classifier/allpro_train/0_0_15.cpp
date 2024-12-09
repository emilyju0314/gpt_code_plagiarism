#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    int t, a, b;
};

bool compareBooks(Book& book1, Book& book2) {
    return book1.t < book2.t;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Book> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].t >> books[i].a >> books[i].b;
    }

    vector<int> likedBooksIndexes;
    for (int i = 0; i < n; i++) {
        if (books[i].a || books[i].b) {
            likedBooksIndexes.push_back(i);
        }
    }

    if (likedBooksIndexes.size() < k) {
        cout << -1 << endl;
        return 0;
    }

    sort(likedBooksIndexes.begin(), likedBooksIndexes.end(), [&](int i, int j) {
        return books[i].t < books[j].t;
    });

    int totalReadingTime = 0;
    int aliceLikedCount, bobLikedCount;
    aliceLikedCount = bobLikedCount = 0;

    for (int i = 0; i < k; i++) {
        totalReadingTime += books[likedBooksIndexes[i]].t;
        if (books[likedBooksIndexes[i]].a) {
            aliceLikedCount++;
        }
        if (books[likedBooksIndexes[i]].b) {
            bobLikedCount++;
        }
    }

    int remainingBooks = likedBooksIndexes.size() - k;
    int extraBooks = max(0, k - aliceLikedCount) + max(0, k - bobLikedCount);

    cout << (remainingBooks >= extraBooks ? totalReadingTime : -1) << endl;

    return 0;
}