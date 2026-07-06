# Next Permutation

> Problem: Rearrange numbers into the lexicographically next greater permutation. If such an arrangement is not possible, rearrange it as the lowest possible order (ascending order).

LeetCode 31 -   next-permutation

---

# 1. Brute Force

### Idea

Generate all possible permutations, sort them lexicographically, find the current permutation, and return the next one.

### Algorithm

1. Generate all permutations.
2. Sort them lexicographically.
3. Find the current permutation.
4. Return the next permutation.
5. If the current permutation is the last one, return the first permutation.

### Time Complexity

- O(N! × N)

### Space Complexity

- O(N!)

---

# 2. Optimal Approach

### Intuition

To get the next lexicographical permutation:

- Find the first index from the right where the order is increasing (`nums[i] < nums[i+1]`). This is called the breakpoint.
- Find the smallest element greater than `nums[i]` on its right.
- Swap them.
- Reverse the suffix to make it as small as possible.

---

### Algorithm

1. Traverse from right to left and find the first index `i` such that `nums[i] < nums[i+1]`.
2. If no such index exists:
   - Reverse the entire array.
   - Return.
3. Traverse from the end and find the first element greater than `nums[i]`.
4. Swap both elements.
5. Reverse the subarray from `i+1` to the end.

### Time Complexity

- O(N)

### Space Complexity

- O(1)

---

### C++ Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int index = -1;

        // Find breakpoint
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Last permutation
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find next greater element
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
```

---

# Dry Run

### Example

```text
nums = [2,1,5,4,3,0,0]
```

### Step 1: Find Breakpoint

```text
2 1 5 4 3 0 0
      ^
index = 1 (1 < 5)
```

### Step 2: Find Next Greater Element

```text
From right → 3

2 1 5 4 3 0 0
        ^
```

Swap:

```text
2 3 5 4 1 0 0
```

### Step 3: Reverse Suffix

Reverse everything after index 1:

```text
2 3 | 5 4 1 0 0

↓

2 3 | 0 0 1 4 5
```

Final Answer:

```text
[2,3,0,0,1,4,5]
```

---

# Edge Case

Input:

```text
[3,2,1]
```

No breakpoint exists.

Reverse the entire array.

Output:

```text
[1,2,3]
```

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute | O(N! × N) | O(N!) |
| Optimal | O(N) | O(1) |

---

# Interview Flow

- Brute: Generate all permutations, sort them, and return the next one.
- Optimal:
  1. Find the breakpoint.
  2. Find the next greater element from the right.
  3. Swap them.
  4. Reverse the suffix.
```
````
