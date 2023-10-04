import re
import numpy as np
def parse_matrix(input_str):
    # Extract the numbers using regular expressions
    numbers = re.findall(r'-?\d+', input_str)

    # Determine the number of rows and columns
    num_rows = input_str.count('{')
    num_cols = len(numbers) // num_rows

    # Create an empty matrix
    matrix = []

    # Fill the matrix with the parsed numbers
    for i in range(num_rows):
        row = []
        for j in range(num_cols):
            index = i * num_cols + j
            row.append(int(numbers[index]))
        matrix.append(row)

    return matrix
if __name__ == "__main__":
# Input string containing the numbers in the specified format
 input_str= ""
 input_str2= ""
 A = parse_matrix(input_str)
 B = parse_matrix(input_str2)

# Print the resulting matrix
 print("MATRIX A:")
 for row in A:
     print(row)
 print("MATRIX B:")
 for row in B:
     print(row)
 resultant = np.matmul(A,B)
 sum=0
 for row in resultant:
  for i in row:
   sum+=i
 print(sum)


# 1. 117
# 2. 137
# 3. 185
# 4. -2388
# 5. 24548
# 6.