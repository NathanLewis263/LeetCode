class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        
        // Step 1: Pair (nums2[i], nums1[i]) and sort descending by nums2[i]
        for (int i = 0; i < n; i++) {
            pairs.emplace_back(nums2[i], nums1[i]);
        }
        sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
            });  
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap for k elements
        long long sum = 0, maxScore = 0;
        
        // Step 2: Process k elements
        for (int i = 0; i < n; i++) {
            int val1 = pairs[i].second;  // nums1 value
            int val2 = pairs[i].first;   // nums2 value (smallest multiplier)

            // If heap exceeds size k, remove smallest element
            if (minHeap.size() >= k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            minHeap.push(val1);
            sum += val1;  // Add to sum


            // If we have exactly k elements, calculate score
            if (minHeap.size() == k) {
                maxScore = max(maxScore, sum * val2);
            }
        }

        return maxScore;
    }
};