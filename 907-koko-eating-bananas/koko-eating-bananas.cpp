class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        auto canFinish = [&](int k) {
            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k; // ceil(pile / k)
            }
            return hours <= h;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
