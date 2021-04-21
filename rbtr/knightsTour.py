"""
TEMPLATE FOR BACKTRACKING

follow steps 1 to 6 to solve any backtracking problem with given constraints

Permutations: For backtracking sol to use against permute problems, just remove isSafe! Since every comb is valid!

"""


class Solution:
    def knightTour(self, N):
        # Check that i,j is not out of chessboard and is not visited
        def isSafe(i, j):
            if 0 <= i < N and 0 <= j < N and board[i][j] == -1:
                return True
            return False

        def solve(cur_x, cur_y, moveCount):
            # 1.) Base Case: All m  oves done
            if moveCount == N*N:
                return True

            # 2.) Breadth : --> Considering all possible moves

            for i in range(8):
                next_x = cur_x + move_x[i]
                next_y = cur_y + move_y[i]

                # 3.) Checking if this move can be taken
                if isSafe(next_x, next_y):
                    # 4.) Take this move
                    board[next_x][next_y] = moveCount

                    # 5.) Check if this move leads to a solution from all recurring moves
                    if solve(next_x, next_y, moveCount+1):
                        return True

                    # 6.) Backtrack this move as it didn't worked
                    board[next_x][next_y] = -1

            return False

        # Initializing chess board
        board = [[-1 for i in range(N)] for j in range(N)]

        # Possible moves
        move_x = [2, 1, -1, -2, -2, -1, 1, 2]
        move_y = [1, 2, 2, 1, -1, -2, -2, -1]

        board[0][0] = 0  # knight starts from this block
        solve(0, 0, 0+1)

        return board


s = Solution()
print(s.knightTour(8))
