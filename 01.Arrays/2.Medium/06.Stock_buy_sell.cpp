 
# Best Time to Buy and Sell Stock

> Problem: You are given an array `prices` where `prices[i]` is the price of a stock on the `iᵗʰ` day. Find the maximum profit you can achieve by buying one stock and selling one stock. You must buy before you sell.

 LeetCode 121 -  best-time-to-buy-and-sell-stock/

---

# 1. Brute Force

### Idea

Try every possible pair of buying and selling days and calculate the profit.

### Algorithm

1. Choose every day as the buying day.
2. Choose every later day as the selling day.
3. Compute the profit.
4. Update the maximum profit.

### Time Complexity

- O(N²)

### Space Complexity

- O(1)

### C++ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxProfit = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }

        return maxProfit;
    }
};
```

---

# 2. Optimal Approach

### Intuition

To maximize profit, we should buy at the lowest price seen so far and sell at the current price if it gives a better profit.

### Algorithm

1. Initialize `minPrice` as the first day's price.
2. Traverse the array from left to right.
3. Calculate the profit by selling on the current day.
4. Update the maximum profit.
5. Update the minimum price seen so far.
6. Return the maximum profit.

### Time Complexity

- O(N)

### Space Complexity

- O(1)

### C++ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            maxProfit = max(maxProfit, prices[i] - minPrice);

            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
```

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|------------------|
| Brute | O(N²) | O(1) |
| Optimal | O(N) | O(1) |

---

# Interview Flow

- Brute: Try every possible buying and selling pair.
- Optimal: Maintain the minimum buying price seen so far and compute the maximum profit in a single traversal.

---

# Follow-up: Print the Buy and Sell Days

### Idea

Store the day when the minimum price occurs and update the buy/sell days whenever a better profit is found.

### C++ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int buyDay = 0, sellDay = 0;
        int minDay = 0;
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
                buyDay = minDay;
                sellDay = i;
            }

            if(prices[i] < minPrice) {
                minPrice = prices[i];
                minDay = i;
            }
        }

        cout << "Buy on Day: " << buyDay << endl;
        cout << "Sell on Day: " << sellDay << endl;

        return maxProfit;
    }
};
```

### Example

Input:

```text
prices = [7,1,5,3,6,4]
```

Output:

```text
Maximum Profit = 5
Buy on Day = 1
Sell on Day = 4
```
````
