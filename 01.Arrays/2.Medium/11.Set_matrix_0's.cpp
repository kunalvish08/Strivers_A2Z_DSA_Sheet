# Set Matrix Zeroes

> Problem: Given an `m × n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`.
> You must do it **in-place**.
**LeetCode:** [https://leetcode.com/problems/set-matrix-zeroes/](https://leetcode.com/problems/set-matrix-zeroes/)

### Example 1
Input``
matrix = [
 [1,1,1],
 [1,0,1],
 [1,1,1]
]
```

Output:```
[
 [1,0,1],
 [0,0,0],
 [1,0,1]
]
```

### Example 2

Input:```
matrix = [
 [0,1,2,0],
 [3,4,5,2],
 [1,3,1,5]
]
```

Output:

```
[
 [0,0,0,0],
 [0,4,5,0],
 [0,3,1,0]
]
```

---

## 1. Brute Force

### Idea

Whenever a `0` is found, mark all elements in its row and column with a special value (`-1`) so they are not processed as original zeros. Finally, convert all `-1`s to `0`.

> This approach assumes the matrix does not initially contain `-1`.

### Algorithm

1. Traverse the matrix.
2. If a cell is `0`:

   * Mark all non-zero elements in its row as `-1`.
   * Mark all non-zero elements in its column as `-1`.
3. Traverse the matrix again.
4. Convert all `-1` values to `0`.

### Time Complexity

* O((M × N) × (M + N))

### Space Complexity

* O(1)

### C++ Code

```cpp
class Solution {
public:
    void markRow(vector<vector<int>>& matrix, int row, int n) {

        for(int j = 0; j < n; j++) {
            if(matrix[row][j] != 0)
                matrix[row][j] = -1;
        }
    }

    void markCol(vector<vector<int>>& matrix, int col, int m) {

        for(int i = 0; i < m; i++) {
            if(matrix[i][col] != 0)
                matrix[i][col] = -1;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {
                    markRow(matrix, i, n);
                    markCol(matrix, j, m);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};
```

---

## 2. Better Approach

### Idea

Store the rows and columns containing `0` in two separate arrays.

### Algorithm

1. Create two arrays:

   * `row[m]`
   * `col[n]`
2. Traverse the matrix.
3. If a cell is `0`:

   * Mark its row.
   * Mark its column.
4. Traverse the matrix again.
5. If either the row or column is marked, make the cell `0`.

### Time Complexity

* O(M × N)

### Space Complexity

* O(M + N)

### C++ Code

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
```

---

## 3. Optimal Approach

### Idea

Use the first row and first column of the matrix itself as markers.

Since `matrix[0][0]` cannot represent both the first row and the first column, use an extra variable `col0` to track whether the first column should be set to `0`.

### Algorithm

1. Initialize `col0 = 1`.
2. Traverse the matrix.
3. If a cell is `0`:

   * Mark its row using `matrix[i][0]`.
   * Mark its column using `matrix[0][j]`.
   * If it is in the first column, set `col0 = 0`.
4. Traverse the matrix from bottom-right.
5. Set a cell to `0` if its row or column is marked.
6. Finally, update the first column using `col0`.

### Time Complexity

* O(M × N)

### Space Complexity

* O(1)

### C++ Code

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        for(int i = 0; i < m; i++) {

            if(matrix[i][0] == 0)
                col0 = 0;

            for(int j = 1; j < n; j++) {

                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--) {

            for(int j = n - 1; j >= 1; j--) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
```

---

## Complexity Comparison

| Approach | Time Complexity      | Space Complexity |
| -------- | -------------------- | ---------------- |
| Brute    | O((M × N) × (M + N)) | O(1)             |
| Better   | O(M × N)             | O(M + N)         |
| Optimal  | O(M × N)             | O(1)             |

---

## Interview Flow

* Brute: Mark affected rows and columns using a temporary marker (`-1`), then convert them to `0`.
* Better: Store rows and columns containing `0` in two separate arrays.
* Optimal: Use the first row and first column as markers, along with one extra variable (`col0`) for the first column, achieving O(1) extra space.
