# 📌 LeetCode 1 — Two Sum

---

## 🏷️ Details
Difficulty: Easy  
Topic: Arrays + Hashing  
Pattern: Complement (Hash Map)

---

## 📄 Problem
Given an array `nums` and a number `target`, find two indices such that:

nums[i] + nums[j] = target

Return their indices.

Only one solution exists.

---

## 💡 Intuition
For every number, think:
What do I need to make target?


need = target - current

If this “need” is already seen before → answer found.

---

## 🐢 Brute Force

Check every pair.

### Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
````

### Complexity

Time: O(n²)
Space: O(1)

---

## 🚀 Optimal Approach

Use Hash Map.

Idea:
Store numbers while moving forward.

For each number:
check if (target - number) exists.

---

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int need = target - nums[i];

            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

---

### Complexity

Time: O(n)
Space: O(n)

---

## 🎯 Key Point

Always think:

```
target - current = required number
```

---

## 🧩 Pattern

* Pair sum
* Hashing
* Unsorted array

---

## 📝 Revision

* Try all pairs → brute force
* Store seen numbers → hashmap
* Check complement while iterating

---

## 🔥 One Line Rule

Unsorted array + pair sum → Hash Map

