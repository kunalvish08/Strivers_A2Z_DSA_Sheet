# Spiral Matrix

> Problem: Given an `m × n` matrix, return all elements of the matrix in spiral order.

**LeetCode:** [https://leetcode.com/problems/spiral-matrix/](https://leetcode.com/problems/spiral-matrix/)

### Example 1

Input:

```text
matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

Output:

```text
[1,2,3,6,9,8,7,4,5]
```

### Example 2

Input:

```text
matrix =
[
 [1,2,3,4],
 [5,6,7,8],
 [9,10,11,12]
]
```

Output:

```text
[1,2,3,4,8,12,11,10,9,5,6,7]
```

---

## 1. Brute Force

### Idea

Use a separate `visited` matrix and simulate movement in four directions:

* Right
* Down
* Left
* Up

Whenever the next cell is out of bounds or already visited, change the direction.

### Algorithm

1. Create a `visited` matrix.
2. Start from `(0,0)` moving right.
3. Visit every cell exactly once.
4. Change direction whenever necessary.
5. Continue until all cells are visited.

### Time Complexity

* O(M × N)

### Space Complexity

* O(M × N)

---

## 2. Optimal Approach

### Idea

Maintain four boundaries:

* `top`
* `bottom`
* `left`
* `right`

Traverse layer by layer in the following order:

1. Left → Right
2. Top → Bottom
3. Right → Left
4. Bottom → Top

Shrink the boundaries after every traversal.

### Algorithm

1. Initialize:

   * `top = 0`
   * `bottom = m - 1`
   * `left = 0`
   * `right = n - 1`
2. Traverse the top row.
3. Traverse the right column.
4. Traverse the bottom row (if `top <= bottom`).
5. Traverse the left column (if `left <= right`).
6. Repeat until boundaries cross.

### Time Complexity

* O(M × N)

### Space Complexity

* O(1) (excluding output array)

### C++ Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> ans;

        while(top <= bottom && left <= right) {

            // Left -> Right
            for(int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Top -> Bottom
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Right -> Left
            if(top <= bottom) {
                for(int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Bottom -> Top
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
```

---

## Dry Run

Example:

```text
matrix =
[
 [1,2,3],
 [4,5,6],
 [7,8,9]
]
```

Traversal:

```text
Top Row     → 1 2 3
Right Col   ↓ 6 9
Bottom Row  ← 8 7
Left Col    ↑ 4
Center      → 5
```

Answer:

```text
[1,2,3,6,9,8,7,4,5]
```

---

# Complexity Comparison

| Approach                     | Time Complexity | Space Complexity |
| ---------------------------- | --------------- | ---------------- |
| Brute (Visited Matrix)       | O(M × N)        | O(M × N)         |
| Optimal (Boundary Traversal) | O(M × N)        | O(1)             |

---

## Interview Flow

* Brute: Simulate movement using a visited matrix and four directions.
* Optimal: Maintain four boundaries (`top`, `bottom`, `left`, `right`) and traverse the matrix layer by layer in spiral order using O(1) extra space.
