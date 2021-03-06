
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.IntStream;

public class Solution {

    public int longestConsecutive(int[] nums) {
        if (nums.length < 2) {
            return nums.length;
        }

        Map<Integer, Integer> valueToIndex = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            valueToIndex.put(nums[i], i);
        }

        UnionFind unionFind = new UnionFind(nums.length);

        for (int n : valueToIndex.keySet()) {
            if (valueToIndex.containsKey(n - 1)) {
                unionFind.joinByRank(unionFind.findParent(valueToIndex.get(n)), unionFind.findParent(valueToIndex.get(n - 1)));
            }
            if (valueToIndex.containsKey(n + 1)) {
                unionFind.joinByRank(unionFind.findParent(valueToIndex.get(n)), unionFind.findParent(valueToIndex.get(n + 1)));
            }
        }

        int[] lengthConsecutiveSequence = new int[nums.length];
        for (int n : valueToIndex.keySet()) {
            ++lengthConsecutiveSequence[unionFind.findParent(valueToIndex.get(n))];
        }

        return Arrays.stream(lengthConsecutiveSequence).max().getAsInt();
    }
}

class UnionFind {

    int[] parent;
    int[] rank;

    UnionFind(int numberOfUniqueElements) {
        parent = IntStream.range(0, numberOfUniqueElements).toArray();
        rank = new int[numberOfUniqueElements];
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
}
