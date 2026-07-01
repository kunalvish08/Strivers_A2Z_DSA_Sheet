For **Sort Colors (LeetCode 75)**, the notes should naturally progress from **Brute Force → Better → Optimal (Dutch National Flag Algorithm)** because this problem has three meaningful approaches.

This makes it much easier to understand *why* the optimal solution exists instead of memorizing it.

I would structure it like this:

---

````md
# 📌 LeetCode 75 — Sort Colors

---

## 🏷️ Details

- Difficulty: Medium
- Topic: Arrays
- Pattern: Dutch National Flag Algorithm (Three Pointers)

---

## 📄 Problem

Given an array `nums` containing only `0`, `1`, and `2`, sort the array in-place without using the library sort function.

---

## 🧠 Intuition

The array contains only **three distinct values**.

So first ask yourself:

- Can I simply sort it?
- Can I do better without sorting?
- Can I solve it in one traversal?

Let's build the solution step by step.

---

# 🐢 Approach 1 — Brute Force

## 💭 Hint

The easiest idea is to use the built-in sorting algorithm.

Although it works, the problem explicitly asks us not to use it.

### 💻 Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```

### ⏱ Complexity

Time: **O(n log n)**

Space: **O(1)**

---

# ⚡ Approach 2 — Better

## 💭 Hint

There are only three numbers:

- 0
- 1
- 2

Instead of sorting,

count how many 0s, 1s and 2s are present.

Then overwrite the array.

### 💻 Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero = 0, one = 0, two = 0;

        for(int x : nums){
            if(x == 0) zero++;
            else if(x == 1) one++;
            else two++;
        }

        int i = 0;

        while(zero--) nums[i++] = 0;
        while(one--) nums[i++] = 1;
        while(two--) nums[i++] = 2;
    }
};
```

### ⏱ Complexity

Time: **O(n)**

Space: **O(1)**

---

# 🚀 Approach 3 — Optimal (Dutch National Flag)

## 💭 Hint

Can we sort the array in **one traversal**?

Maintain three regions.

```
0s | 1s | Unknown | 2s
```

Use three pointers:

- low
- mid
- high

Initially,

```
Unknown = Entire Array
```

As we scan,

move elements into their correct region.

---

## 💡 Rules

### If nums[mid] == 0

Swap with low

Both `low` and `mid` move forward.

---

### If nums[mid] == 1

Already in correct position.

Only move `mid`.

---

### If nums[mid] == 2

Swap with high.

Decrease `high`.

Don't move `mid` because the swapped element is still unchecked.

---

### 💻 Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

### ⏱ Complexity

Time: **O(n)**

Space: **O(1)**

---

# 🎯 Key Insight

Think in terms of regions.

```
0s | 1s | Unknown | 2s
```

Only the **Unknown** region needs processing.

---

# 🧩 Pattern

- Three Pointers
- Dutch National Flag Algorithm
- In-place Array Partitioning

---

# 📝 Revision Notes

- Brute → Sort the array
- Better → Count frequencies
- Optimal → Three pointers
- If 0 → swap with low
- If 1 → move mid
- If 2 → swap with high
- Never increment `mid` after swapping with `high`

---

# 🔥 One Line Rule

When an array contains only **three unique values**, think **Dutch National Flag Algorithm**.
````

