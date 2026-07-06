````markdown id="cxm8qe"
# Leaders in an Array

> Problem: Given an array `A` of positive integers, find all the leaders in the array. An element is a leader if it is greater than or equal to all the elements to its right. The rightmost element is always a leader.

**GFG:** https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

---

# 1. Brute Force

### Idea

For every element, check whether all the elements to its right are smaller than or equal to it.

### Algorithm

1. Traverse each element.
2. Compare it with every element on its right.
3. If no greater element is found, it is a leader.
4. Store the leader.

### Time Complexity

- O(N²)

### Space Complexity

- O(1) (excluding output array)

### C++ Code

```cpp
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            bool leader = true;

            for(int j = i + 1; j < n; j++) {

                if(arr[j] > arr[i]) {
                    leader = false;
                    break;
                }
            }

            if(leader)
                ans.push_back(arr[i]);
        }

        return ans;
    }
};
```

---

# 2. Optimal Approach

### Intuition

A leader must be greater than or equal to every element on its right.

Instead of checking every element repeatedly, traverse the array from right to left while maintaining the maximum element seen so far.

- The rightmost element is always a leader.
- If the current element is greater than or equal to the maximum seen so far, it is also a leader.

---

### Algorithm

1. Initialize `maxi = INT_MIN`.
2. Traverse the array from right to left.
3. If `arr[i] >= maxi`:
   - Add it to the answer.
   - Update `maxi`.
4. Reverse the answer before returning.

### Time Complexity

- O(N)

### Space Complexity

- O(1) (excluding output array)

### C++ Code

```cpp
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {

        int n = arr.size();

        vector<int> ans;

        int maxi = INT_MIN;

        for(int i = n - 1; i >= 0; i--) {

            if(arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

---

# Dry Run

### Example

```text
arr = [16,17,4,3,5,2]
```

Traverse from right:

| Element | Maximum So Far | Leader |
|---------|----------------|--------|
| 2 | 2 | Yes |
| 5 | 5 | Yes |
| 3 | 5 | No |
| 4 | 5 | No |
| 17 | 17 | Yes |
| 16 | 17 | No |

Collected (right to left):

```text
[2, 5, 17]
```

Reverse:

```text
[17, 5, 2]
```

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute | O(N²) | O(1) |
| Optimal | O(N) | O(1) |

---

# Interview Flow

- Brute: For every element, check all elements on its right.
- Optimal: Traverse from right to left while maintaining the maximum element seen so far. If the current element is greater than or equal to the maximum, it is a leader.
````
