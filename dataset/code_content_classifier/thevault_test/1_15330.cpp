void adjust(deque<int>&a1,deque<int>&a2, int val, bool way) {
    if (way) {
        int back = a1.back();
        a1.pop_back(); // since pop back does not actually return the data, we can't do `itn back = a1.pop_back()`
        a2.push_front(back);
    } else {
        int front = a2.front();
        a2.pop_front(); // since pop back does not actually return the data, we can't do `itn back = a1.pop_back()`
        a1.push_back(front);
    }
    ;
}