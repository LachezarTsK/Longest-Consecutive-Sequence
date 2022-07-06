
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    if (nums.length < 2) {
        return nums.length;
    }

    const valueToIndex = new Map();
    for (let i = 0; i < nums.length; ++i) {
        valueToIndex.set(nums[i], i);
    }

    const unionFind = new UnionFind(nums.length);
    for (let [value, index] of valueToIndex) {
        if (valueToIndex.has(value - 1)) {
            unionFind.joinByRank(unionFind.findParent(index), unionFind.findParent(valueToIndex.get(value - 1)));
        }
        if (valueToIndex.has(value + 1)) {
            unionFind.joinByRank(unionFind.findParent(index), unionFind.findParent(valueToIndex.get(value + 1)));
        }
    }

    const lengthConsecutiveSequence = new Array(nums.length).fill(0);
    for (let index of valueToIndex.values()) {
        ++lengthConsecutiveSequence[unionFind.findParent(index)];
    }

    return Math.max(...lengthConsecutiveSequence);
};

class UnionFind {

    constructor(numberOfUniqueElements) {
        this.parent = Array.from(new Array(numberOfUniqueElements).keys());
        this.rank = new Array(numberOfUniqueElements).fill(0);
    }

    findParent(index) {
        if (this.parent[index] !== index) {
            this.parent[index] = this.findParent(this.parent[index]);
        }
        return this.parent[index];
    }

    joinByRank(first, second) {
        if (this.rank[first] > this.rank[second]) {
            this.parent[second] = first;
        } else if (this.rank[first] < this.rank[second]) {
            this.parent[first] = second;
        } else {
            this.parent[second] = first;
            ++this.rank[first];
        }
    }
}
