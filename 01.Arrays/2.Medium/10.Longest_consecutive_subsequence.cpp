# Longest Consecutive Sequence

> Problem: Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

> You must write an algorithm that runs in **O(n)** time.

**LeetCode: longest-consecutive-sequence

### Example 1
Input: `nums = [100,4,200,1,3,2]`
Output: `4`

Explanation:
The longest consecutive sequence is `[1,2,3,4]`.
Therefore, its length is `4`.

### Example 2
Input: `nums = [0,3,7,2,5,8,4,6,0,1]`
Output: `9`

Explanation:
The longest consecutive sequence is `[0,1,2,3,4,5,6,7,8]`.
Therefore, its length is `9`.

### Example 3
Input: `nums = [1,0,1,2]`
Output: `3`

Explanation:
The longest consecutive sequence is `[0,1,2]`.
Therefore, its length is `3`.

---

## 1. Brute Force

### Idea
For every element, keep searching for the next consecutive element (`x + 1`, `x + 2`, ...) using linear search.

### Algorithm
1. Traverse every element.
2. For each element, repeatedly search for the next consecutive value.
3. Count the length of the sequence.
4. Update the maximum length.

### Time Complexity
* O(N²)

### Space Complexity
* O(1)

### C++ Code
  
class Solution {
public:
    bool linearSearch(vector<int>& nums, int target) {

        for(int num : nums) {
            if(num == target)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;

        for(int num : nums) {

            int current = num;
            int cnt = 1;

            while(linearSearch(nums, current + 1)) {
                current++;
                cnt++;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};
```

---

## 2. Better Approach

### Idea

Sort the array so that consecutive numbers become adjacent.

### Algorithm

1. Sort the array.
2. Traverse the sorted array.
3. Ignore duplicate elements.
4. If the current element is one greater than the previous, increase the count.
5. Otherwise, start a new sequence.
6. Update the maximum length.

### Time Complexity

* O(N log N)

### Space Complexity

* O(1)

### C++ Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[i - 1])
                continue;

            if(nums[i] == nums[i - 1] + 1)
                cnt++;
            else
                cnt = 1;

            longest = max(longest, cnt);
        }

        return longest;
    }
};
```

---

## 3. Optimal Approach

### Idea

Store all elements in a hash set.

Only start counting from numbers that are the beginning of a sequence (`num - 1` is not present). This ensures every sequence is counted exactly once.

### Algorithm

1. Insert all elements into a hash set.
2. Traverse the set.
3. If `num - 1` is not present:

   * Start a new sequence.
   * Keep checking `num + 1`, `num + 2`, ...
4. Update the maximum length.

### Time Complexity

* O(N)

### Space Complexity

* O(N)

### C++ Code

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st) {

            if(st.find(num - 1) == st.end()) {

                int current = num;
                int cnt = 1;

                while(st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
```

---

## Dry Run

Example:

`nums = [100,4,200,1,3,2]`

Hash Set:

`{100,4,200,1,3,2}`

Start counting only from sequence beginnings:

* `100 → Length = 1`
* `200 → Length = 1`
* `1 → 2 → 3 → 4 → Length = 4`

Answer:

`Longest Consecutive Sequence Length = 4`

---

# Complexity Comparison

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Brute              | O(N²)           | O(1)             |
| Better (Sorting)   | O(N log N)      | O(1)             |
| Optimal (Hash Set) | O(N)            | O(N)             |

---

## Interview Flow

* Brute: For every element, linearly search for the next consecutive numbers.
* Better: Sort the array and count consecutive elements while skipping duplicates.
* Optimal: Use a hash set and start counting only from the beginning of each sequence (`num - 1` not present), achieving O(N) time.
