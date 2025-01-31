#User function Template for python3
N = 9
class Solution:
    
    def isPossible(self,grid,row,col,num):
        for i in range(len(grid)):
            if grid[i][col] == num:
                return False
            if grid[row][i] == num:
                return False
            if grid[3 * (row//3) + i//3][3 * (col//3) + i%3] == num:
                return False
        
        return True


    def SolveSudoku(self,grid, row, col):
        if (row == N - 1 and col == N):
            return True
        if col == N:
            row += 1
            col = 0
        if grid[row][col] > 0:
            return self.SolveSudoku(grid, row, col + 1)
        for num in range(1, N + 1, 1):
            if self.isPossible(grid, row, col, num):
                grid[row][col] = num
                if self.SolveSudoku(grid, row, col + 1):
                    return True
            grid[row][col] = 0
        return False
    
    def solveSudoku(self,grid):
        return self.SolveSudoku(grid,0,0)
        
        # for i in range(len(grid)):
        #     for j in range(len(grid[0])):
                
        #         if grid[i][j] == 0:
        #             for k in range(1,len(grid)+1):
        #                 if self.isPossible(grid,i,j,k):
        #                     grid[i][j] = k
        #                     if self.SolveSudoku(grid) == True:
        #                         return True
        #                     else:
        #                         grid[i][j] = 0
            
        #             return False
        # return True
        
    
    #Function to print grids of the Sudoku.    
    def printGrid(self,arr):
        for i in range(len(arr)):
            for j in range(len(arr[0])):
                print(arr[i][j],end=" ")
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    import sys
    input = sys.stdin.read
    data = input().split()

    t = int(data[0])
    index = 1

    for _ in range(t):
        matrix = []
        n = 9
        for i in range(n):
            row = list(map(int, data[index:index + n]))
            matrix.append(row)
            index += n
        obj = Solution()
        obj.solveSudoku(matrix)
        for i in range(n):
            for j in range(n):
                print(matrix[i][j], end=" ")
            print()
        print("~")

# } Driver Code Ends