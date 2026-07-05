# Rearrange Array Elements by Sign | 2 Varieties of Same Problem

Problem: Rearrange the array so that positive and negative elements appear alternately.

LeetCode 2149 -  rearrange-array-elements-by-sign

---

# Variety 1

### Condition

- Number of positive and negative elements are equal.
- The array starts with a positive element.
- Relative order of positive and negative elements should be maintained.

Example:
Input:  [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]

# 1. Brute Force

### Idea

Store all positive and negative numbers in separate arrays, then place them alternately.

### Algorithm

1. Store all positive elements in one array.
2. Store all negative elements in another array.
3. Fill the original array alternately using both arrays.

### Time Complexity

- O(N)

### Space Complexity

- O(N)

### C++ Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos, neg;

        for(int num : nums) {
            if(num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        vector<int> ans(nums.size());

        for(int i = 0; i < pos.size(); i++) {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        return ans;
    }
};
```

---

# 2. Optimal Approach

### Idea

Instead of using two separate arrays, directly place each element into its correct position.

- Positive numbers go to even indices.
- Negative numbers go to odd indices.

### Algorithm

1. Create an answer array.
2. Maintain:
   - `posIndex = 0`
   - `negIndex = 1`
3. Traverse the array.
4. Place positives at even indices.
5. Place negatives at odd indices.

### Time Complexity

- O(N)

### Space Complexity

- O(N)

### C++ Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans(nums.size());

        int posIndex = 0;
        int negIndex = 1;

        for(int num : nums) {

            if(num > 0) {
                ans[posIndex] = num;
                posIndex += 2;
            }
            else {
                ans[negIndex] = num;
                negIndex += 2;
            }
        }

        return ans;
    }
};
```

---

# Variety 2

### Condition

- Positive and negative elements are not necessarily equal.
- Extra positive or negative elements should be placed at the end.
- Relative order should be maintained.

Example 1

```text
Input:  [1,2,-4,-5,3,4]
Output: [1,-4,2,-5,3,4]
```

Example 2

```text
Input:  [-1,-2,3,4,5]
Output: [3,-1,4,-2,5]
```

---

# Optimal Approach

### Idea

Store positive and negative elements separately.

Alternate elements until one list becomes empty, then append the remaining elements.

### Algorithm

1. Store positives and negatives in separate arrays.
2. Fill the answer alternately.
3. Append the remaining elements from the longer array.

### Time Complexity

- O(N)

### Space Complexity

- O(N)

### C++ Code

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos, neg;

        for(int num : nums) {
            if(num >= 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        vector<int> ans;
        int i = 0, j = 0;

        while(i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        while(i < pos.size())
            ans.push_back(pos[i++]);

        while(j < neg.size())
            ans.push_back(neg[j++]);

        return ans;
    }
};
```

---

# Complexity Comparison

| Variety | Approach | Time | Space |
|----------|----------|------|-------|
| Variety 1 | Brute | O(N) | O(N) |
| Variety 1 | Optimal | O(N) | O(N) |
| Variety 2 | Optimal | O(N) | O(N) |

---

# Interview Flow

- Variety 1:
  - Store positives and negatives separately.
  - Better optimization is to directly place positives at even indices and negatives at odd indices.

- Variety 2:
  - Since the counts of positives and negatives may differ, store them separately, alternate as long as possible, then append the remaining elements.
````
