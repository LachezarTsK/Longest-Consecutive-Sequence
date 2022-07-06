
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    const inputUniqueIntegers = new Set();
    for (let i = 0; i < nums.length; ++i) {
        inputUniqueIntegers.add(nums[i]);
    }

    let longestConsecutiveSequence = 0;
    for (let n of inputUniqueIntegers) {

        if (!inputUniqueIntegers.has(n - 1)) {
            let currentLength = 1;
            let element = n;

            while (inputUniqueIntegers.has(element + 1)) {
                ++element;
                ++currentLength;
            }
            longestConsecutiveSequence = Math.max(longestConsecutiveSequence, currentLength);
        }
    }
    return longestConsecutiveSequence;
};
