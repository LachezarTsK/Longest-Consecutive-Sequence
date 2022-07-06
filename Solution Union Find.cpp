
#include <vector>
using namespace std;

class UnionFind {
    
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int numberOfUniqueElements) {
        parent.resize(numberOfUniqueElements);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(numberOfUniqueElements);
    }

    int findParent(int index) {
        if (parent[index] != index) {
            parent[index] = findParent(parent[index]);
        }
        return parent[index];
    }

    void joinByRank(int first, int second) {
        if (rank[first] > rank[second]) {
            parent[second] = first;
        } else if (rank[first] < rank[second]) {
            parent[first] = second;
        } else {
            parent[second] = first;
            ++rank[first];
        }
    }
};

class Solution {
    
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            valueToIndex[nums[i]] = i;
        }

        UnionFind unionFind(nums.size());
        for (const auto& [value, index] : valueToIndex) {

            //C++20: valueToIndex.contains(n.first - 1) ...
            if (valueToIndex.find(value - 1) != valueToIndex.end()) {
                unionFind.joinByRank(unionFind.findParent(index), unionFind.findParent(valueToIndex[value - 1]));
            }
            if (valueToIndex.find(value + 1) != valueToIndex.end()) {
                unionFind.joinByRank(unionFind.findParent(index), unionFind.findParent(valueToIndex[value + 1]));
            }
        }

        vector<int> lengthConsecutiveSequence(nums.size());
        for (const auto& [value, index] : valueToIndex) {
            ++lengthConsecutiveSequence[unionFind.findParent(index)];
        }

        return *max_element(lengthConsecutiveSequence.begin(), lengthConsecutiveSequence.end());
    }
};
