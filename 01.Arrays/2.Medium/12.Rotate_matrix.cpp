# Rotate Image

> Problem: You are given an `n × n` 2D matrix representing an image. Rotate the image by **90 degrees (clockwise)**.

> You have to rotate the image **in-place**, which means you have to modify the input matrix directly without allocating another 2D matrix.

**LeetCode:** [https://leetcode.com/problems/rotate-image/](https://leetcode.com/problems/rotate-image/)

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
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```

### Example 2

Input:

```text
matrix =
[
 [5,1,9,11],
 [2,4,8,10],
 [13,3,6,7],
 [15,14,12,16]
]
```

Output:

```text
[
 [15,13,2,5],
 [14,3,4,1],
 [12,6,8,9],
 [16,7,10,11]
]
```

---

## 1. Brute Force

### Idea

Create a new matrix and place every element in its rotated position.

For every element at `(i, j)`:

```text
temp[j][n - 1 - i] = matrix[i][j]
```

Finally, copy the temporary matrix back to the original matrix.

### Algorithm

1. Create a temporary matrix.
2. Traverse the original matrix.
3. Place every element in its rotated position.
4. Copy the temporary matrix back.

### Time Complexity

* O(N²)

### Space Complexity

* O(N²)

### C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> temp(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = temp;
    }
};
```

---

## 2. Optimal Approach

### Idea

Rotate the matrix in-place using two steps:

1. Transpose the matrix.
2. Reverse every row.

### Why does this work?

Original Matrix

```text
1 2 3
4 5 6
7 8 9
```

After Transpose

```text
1 4 7
2 5 8
3 6 9
```

After Reversing Every Row

```text
7 4 1
8 5 2
9 6 3
```

This is exactly the required 90° clockwise rotation.

### Algorithm

1. Transpose the matrix.
2. Reverse every row.

### Time Complexity

* O(N²)

### Space Complexity

* O(1)

### C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
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

After Transpose

```text
1 4 7
2 5 8
3 6 9
```

After Reversing Every Row

```text
7 4 1
8 5 2
9 6 3
```

Final Answer

```text
[
 [7,4,1],
 [8,5,2],
 [9,6,3]
]
```

---

# Complexity Comparison

| Approach | Time Complexity | Space Complexity |
| -------- | --------------- | ---------------- |
| Brute    | O(N²)           | O(N²)            |
| Optimal  | O(N²)           | O(1)             |

---

## Interview Flow

* Brute: Create a new matrix and place every element at its rotated position.
* Optimal: First transpose the matrix, then reverse every row to achieve a 90° clockwise rotation in-place with O(1) extra space.
