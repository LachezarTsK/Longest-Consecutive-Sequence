
#include <vector>
using namespace std;

class Solution {
    
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> inputUniqueIntegers;
        for (const auto& n : nums) {
            inputUniqueIntegers.insert(n);
        }

        int longestConsecutiveSequence = 0;
        for (const auto& n : inputUniqueIntegers) {

            //C++20: !inputUniqueIntegers.contains(n - 1)
            if (inputUniqueIntegers.find(n - 1) == inputUniqueIntegers.end()) {
                int currentLength = 1;
                int element = n;

                while (inputUniqueIntegers.find(element + 1) != inputUniqueIntegers.end()) {
                    ++element;
                    ++currentLength;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentLength);
            }
        }
        return longestConsecutiveSequence;
    }
};
