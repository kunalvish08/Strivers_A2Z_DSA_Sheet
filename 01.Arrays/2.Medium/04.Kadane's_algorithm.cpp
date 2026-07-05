# Kadane's Algorithm | Maximum Subarray Sum
LeetCode 53: maximum-subarray

  
## 1. Brute Force

### Idea

Generate every possible subarray, calculate its sum, and keep track of the maximum.

### Algorithm

1. Start from every index `i`.
2. Extend the subarray to every index `j`.
3. Compute the sum of elements from `i` to `j`.
4. Update the maximum sum.

### Time Complexity

* **O(N³)** (if the sum is calculated from scratch for every subarray)

### Space Complexity

* **O(1)**

### C++ Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                int sum = 0;

                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
```

---

# 2. Better Approach

### Idea

Instead of calculating the sum again for every subarray, keep adding the next element while extending the subarray.

### Algorithm

1. Fix the starting index `i`.
2. Initialize `sum = 0`.
3. Extend the ending index `j`.
4. Add `nums[j]` to `sum`.
5. Update the maximum.

### Time Complexity

* **O(N²)**

### Space Complexity

* **O(1)**

### C++ Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
```

---

# 3. Optimal Approach (Kadane's Algorithm)

### Intuition

If the running sum becomes negative, it will only decrease the sum of any future subarray. So, discard it and start a new subarray.

### Algorithm

1. Initialize `sum = 0` and `maxi = INT_MIN`.
2. Traverse the array.
3. Add the current element to `sum`.
4. Update `maxi`.
5. If `sum < 0`, reset `sum = 0`.
6. Return `maxi`.

### Time Complexity

* **O(N)**

### Space Complexity

* **O(1)**

### C++ Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            maxi = max(maxi, sum);

            if(sum < 0)
                sum = 0;
        }

        return maxi;
    }
};
```

---

# Complexity Comparison

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Brute              | **O(N³)**       | **O(1)**         |
| Better             | **O(N²)**       | **O(1)**         |
| Optimal (Kadane's) | **O(N)**        | **O(1)**         |

### Interview Flow

* **Brute:** Check every subarray and compute its sum from scratch.
* **Better:** Reuse the running sum while extending the subarray.
* **Optimal:** Use Kadane's Algorithm to discard negative-prefix sums and find the maximum subarray in a single traversal.
