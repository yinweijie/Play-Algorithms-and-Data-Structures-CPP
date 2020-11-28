/// Leetcode 350. Intersection of Two Arrays II
/// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m_map;
        for(auto num: nums1) {
            if(m_map.find(num) != m_map.end()) {
                m_map[num] += 1;
            } else {
                m_map.insert(std::pair<int, int>(num, 1));
            }
        }

        vector<int> res;
        for(auto num: nums2) {
            if(m_map.find(num) != m_map.end()) {
                m_map[num] -= 1;
                res.push_back(num);
                if(m_map[num] == 0) {
                    m_map.erase(num);
                }
            }
        }

        return res;
    }
};