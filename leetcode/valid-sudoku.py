from typing import List

board = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
num = [str(a) for a in range(1, 10)]
num.append(".")

# 1. Duplicate in line
# 2. Duplicate in col
# 3. Duplicate in 3x3

for i in board:
    print(i)

def isValidSudoku(board: List[List[str]]):
    for row in range(9):
        verrep = []
        horrep = []
        trirep = []
        for col in range(9):
            horvalue = board[row][col]
            vervalue = board[col][row]
            if horvalue not in num:
                return False
            # 1
            if horvalue in horrep:
               return False
            # 2
            if vervalue in verrep:
                return False
            if horvalue != ".":
                horrep.append(horvalue)
            if vervalue != ".":
                verrep.append(vervalue)

            # 3
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            trirep = []
            for k in range(3):
                for ll in range(3):
                    if board[i + k][j + ll] in trirep:
                        return False
                    if board[i + k][j + ll] != ".":
                        trirep.append(board[i + k][j + ll])

    return True

print(isValid(board))

