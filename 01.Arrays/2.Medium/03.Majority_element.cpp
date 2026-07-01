
# 📌 LeetCode 169 — Majority Element

## 🏷️ Details

- **Difficulty:** Easy
- **Topic:** Arrays
- **Pattern:** Boyer-Moore Voting Algorithm

## 📄 Problem

Given an integer array `nums` of size `n`, return the **majority element**.

A majority element is an element that appears **more than ⌊n/2⌋ times**.

You may assume that the majority element always exists.

---

# 🧠 Intuition

The majority element appears more than **n/2** times.

So no matter how many other elements try to "cancel" it, it will still remain in the end.

Let's solve it step by step.

---

# 🐢 Approach 1 — Brute Force

## 💭 Hint

For every element,

count how many times it appears.

If its frequency is greater than `n/2`, return it.

---

### 💻 Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j])
                    count++;
            }

            if(count > n / 2)
                return nums[i];
        }

        return -1;
    }
};
```

### ⏱ Complexity

- **Time:** O(n²)
- **Space:** O(1)

---

# ⚡ Approach 2 — Better (Hash Map)

## 💭 Hint

Instead of counting the frequency every time,

store the frequency of each element in a Hash Map.

Then check which element has frequency greater than `n/2`.

---

### 💻 Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> freq;

        for(int num : nums)
            freq[num]++;

        for(auto it : freq) {
            if(it.second > nums.size() / 2)
                return it.first;
        }

        return -1;
    }
};
```

### ⏱ Complexity

- **Time:** O(n)
- **Space:** O(n)

---

# 🚀 Approach 3 — Optimal (Boyer-Moore Voting Algorithm)

## 💭 Hint

Think of every different element as cancelling one occurrence of the majority element.

Since the majority element appears more than `n/2` times,

it can never be completely cancelled.

The last remaining candidate will always be the majority element.

---

## 💡 Algorithm

- Maintain a **candidate** and a **count**.
- If `count == 0`, choose the current element as the new candidate.
- If the current element is the candidate, increment `count`.
- Otherwise, decrement `count`.

At the end, the candidate is the majority element.

---

### 💻 Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for(int num : nums) {

            if(count == 0)
                candidate = num;

            if(num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};
```

### ⏱ Complexity

- **Time:** O(n)
- **Space:** O(1)

---

# 🎯 Key Insight

Every non-majority element cancels one occurrence of the majority element.

Since the majority element appears **more than n/2 times**,

it will always survive in the end.

---

# 🧩 Pattern

- Frequency counting
- Hashing
- Boyer-Moore Voting Algorithm

---

# 📝 Revision Notes

- Brute → Count frequency of every element
- Better → Store frequencies using Hash Map
- Optimal → Candidate + Count
- Same element → count++
- Different element → count--
- If count becomes 0 → choose a new candidate

---

# 🔥 One Line Rule

If a problem guarantees an element appears **more than n/2 times**, think **Boyer-Moore Voting Algorithm**.
````
