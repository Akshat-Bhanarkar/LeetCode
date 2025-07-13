class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
       unordered_map<int, int> frequencyMap;
       for (int num : nums) {
        frequencyMap[num]++; // Increment the count for the current number
    } 
     priority_queue< pair<int,int>>max_heap;
     for (const auto& pair : frequencyMap) {
            max_heap.push({ pair.second,pair.first}); // {frequency, integer}
        }
        for(int i=0;i<k;i++){
            v.push_back(max_heap.top().second); // return number
            max_heap.pop();
        }
        return v;    // Kindly Upvote!
    }
};