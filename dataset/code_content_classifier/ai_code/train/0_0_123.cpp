#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double getWeakestSegment(vector<int>& nums, double x) {
    double maxSegmentSum = 0.0, segmentSum = 0.0;

    for(int num : nums) {
        segmentSum = max(0.0, segmentSum + (double)num - x);
        maxSegmentSum = max(maxSegmentSum, segmentSum);
    }

    segmentSum = 0.0;
    for(int num : nums) {
        segmentSum = max(0.0, segmentSum + x - (double)num);
        maxSegmentSum = max(maxSegmentSum, segmentSum);
    }

    return maxSegmentSum;
}

double findMinimumWeakness(vector<int>& nums) {
    double left = *min_element(nums.begin(), nums.end());
    double right = *max_element(nums.begin(), nums.end());
    
    while((right - left) > 1e-9) {
        double mid = (left + right) / 2.0;
        double midNext = (mid + right) / 2.0;
        
        double weakestSegmentMid = getWeakestSegment(nums, mid);
        double weakestSegmentMidNext = getWeakestSegment(nums, midNext);
        
        if(weakestSegmentMid < weakestSegmentMidNext) {
            right = midNext;
        } else {
            left = mid;
        }
    }
    
    return getWeakestSegment(nums, left);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    double minWeakness = findMinimumWeakness(nums);

    cout << fixed << setprecision(12) << minWeakness << endl;

    return 0;
}