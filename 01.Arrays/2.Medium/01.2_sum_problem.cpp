
# 📌 LeetCode 1 — Two Sum

---

## 🏷️ Details
- Difficulty: Easy  
- Topic: Arrays, Hashing  
- Pattern: Hash Map (Complement)  
- Companies: Amazon, Google, Microsoft, Meta  

---

## 📄 Problem
Given an array `nums` and an integer `target`, return indices of the two numbers such that they add up to target.

You may assume exactly one solution exists.

---

## 💡 Intuition
For every number, we ask:

👉 “What do I need to reach the target?”

That is:
```

need = target - current

````

If this “need” is already seen before → we found the answer.

---

## 🐢 Brute Force Approach

### Idea
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

* Time: O(n²)
* Space: O(1)

---

## 🚀 Optimal Approach (Hash Map)

### Idea

Store numbers while traversing and check if complement exists.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

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

### Complexity

* Time: O(n)
* Space: O(n)

---

## 🎯 Key Idea

```
need = target - num
```

Check if need already exists in map.

---

## 🧩 Pattern

* Pair sum problem
* Unsorted array
* Use Hash Map

---

## 📝 Quick Revision

* Try pairs → Brute force
* Use map → store visited numbers
* Check complement while iterating

---

## 🔥 One Line Rule

Unsorted array + pair sum → Hash Map

```

---

If you want next step, I can make:
👉 **:contentReference[oaicite:0]{index=0}**  
👉 Or :contentReference[oaicite:1]{index=1}
```

