
import java.util.HashSet;
import java.util.Set;

public class Solution {

    public int longestConsecutive(int[] nums) {
        Set<Integer> inputUniqueIntegers = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            inputUniqueIntegers.add(nums[i]);
        }

        int longestConsecutiveSequence = 0;
        for (int n : inputUniqueIntegers) {

            if (!inputUniqueIntegers.contains(n - 1)) {
                int currentLength = 1;
                int element = n;

                while (inputUniqueIntegers.contains(element + 1)) {
                    ++element;
                    ++currentLength;
                }
                longestConsecutiveSequence = Math.max(longestConsecutiveSequence, currentLength);
            }
        }
        return longestConsecutiveSequence;
    }
}
