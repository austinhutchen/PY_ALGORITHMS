# Python program to find the resultant
# product matrix for a given pair of matrices
# using Divide and Conquer Approach
import sys
ROW_1 = 4
COL_1 = 4
ROW_2 = 4
COL_2 = 4


def get_c(cmdline):
    # read from stdout and then 
    sensor_bytes = sys.stdin.read(BUFFER_SIZE)
    
    
    
    print ("A * B =")

#Function to print the matrix
def printMat(a, r, c):
	for i in range(r):
		for j in range(c):
			print(a[i][j], end = " ")
		print()
	print()

#Function to print the matrix
def printt(display, matrix, start_row, start_column, end_row,end_column):
	print(display + " =>\n")
	for i in range(start_row, end_row+1):
		for j in range(start_column, end_column+1):
			print(matrix[i][j], end=" ")
		print()
	print()

#Function to add two matrices
def add_matrix(matrix_A, matrix_B, matrix_C, split_index):
	for i in range(split_index):
		for j in range(split_index):
			matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j]

#Function to initialize matrix with zeros
def initWithZeros(a, r, c):
	for i in range(r):
		for j in range(c):
			a[i][j] = 0

#Function to multiply two matrices
def multiply_matrix(matrix_A, matrix_B):
	col_1 = len(matrix_A[0])
	row_1 = len(matrix_A)
	col_2 = len(matrix_B[0])
	row_2 = len(matrix_B)

	if (col_1 != row_2):
		print("\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n")
		return 0

	result_matrix_row = [0] * col_2
	result_matrix = [[0 for x in range(col_2)] for y in range(row_1)]

	if (col_1 == 1):
		result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0]

	else:
		split_index = col_1 // 2

		row_vector = [0] * split_index
		result_matrix_00 = [[0 for x in range(split_index)] for y in range(split_index)]
		result_matrix_01 = [[0 for x in range(split_index)] for y in range(split_index)]
		result_matrix_10 = [[0 for x in range(split_index)] for y in range(split_index)]
		result_matrix_11 = [[0 for x in range(split_index)] for y in range(split_index)]
		a00 = [[0 for x in range(split_index)] for y in range(split_index)]
		a01 = [[0 for x in range(split_index)] for y in range(split_index)]
		a10 = [[0 for x in range(split_index)] for y in range(split_index)]
		a11 = [[0 for x in range(split_index)] for y in range(split_index)]
		b00 = [[0 for x in range(split_index)] for y in range(split_index)]
		b01 = [[0 for x in range(split_index)] for y in range(split_index)]
		b10 = [[0 for x in range(split_index)] for y in range(split_index)]
		b11 = [[0 for x in range(split_index)] for y in range(split_index)]

		for i in range(split_index):
			for j in range(split_index):
				a00[i][j] = matrix_A[i][j]
				a01[i][j] = matrix_A[i][j + split_index]
				a10[i][j] = matrix_A[split_index + i][j]
				a11[i][j] = matrix_A[i + split_index][j + split_index]
				b00[i][j] = matrix_B[i][j]
				b01[i][j] = matrix_B[i][j + split_index]
				b10[i][j] = matrix_B[split_index + i][j]
				b11[i][j] = matrix_B[i + split_index][j + split_index]

		add_matrix(multiply_matrix(a00, b00),multiply_matrix(a01, b10),result_matrix_00, split_index)
		add_matrix(multiply_matrix(a00, b01),multiply_matrix(a01, b11),result_matrix_01, split_index)
		add_matrix(multiply_matrix(a10, b00),multiply_matrix(a11, b10),result_matrix_10, split_index)
		add_matrix(multiply_matrix(a10, b01),multiply_matrix(a11, b11),result_matrix_11, split_index)

		for i in range(split_index):
			for j in range(split_index):
				result_matrix[i][j] = result_matrix_00[i][j]
				result_matrix[i][j + split_index] = result_matrix_01[i][j]
				result_matrix[split_index + i][j] = result_matrix_10[i][j]
				result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j]

	return result_matrix

# Driver Code
matrix_A = [ [1, 1, 1, 1],
			[2, 2, 2, 2],
			[3, 3, 3, 3],
			[2, 2, 2, 2] ]

print("Array A =>")
printMat(matrix_A,4,4)

matrix_B = [ [1, 1, 1, 1],
			[2, 2, 2, 2],
			[3, 3, 3, 3],
			[2, 2, 2, 2] ]

print("Array B =>")
printMat(matrix_B,4,4)

result_matrix = multiply_matrix(matrix_A, matrix_B)

print("Result Array =>")
printMat(result_matrix,4,4)
