/// Leetcode 349. Intersection of Two Arrays
/// https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> m_set;
        for(auto num: nums1) {
            m_set.insert(num);
        }

        vector<int> res;
        for(auto num: nums2) {
            if(m_set.find(num) != m_set.end()) {
                res.push_back(num);
                m_set.erase(num);
            }
        }

        return res;
    }
};