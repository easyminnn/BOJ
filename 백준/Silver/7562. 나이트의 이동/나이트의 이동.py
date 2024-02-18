def is_valid_move(x, y, l):
    return 0 <= x < l and 0 <= y < l

def min_moves_to_destination(l, current_x, current_y, target_x, target_y):
    # Possible moves for a knight
    moves = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]
    
    visited = [[False for _ in range(l)] for _ in range(l)]
    queue = [(current_x, current_y, 0)]
    
    while queue:
        x, y, moves_count = queue.pop(0)
        
        if x == target_x and y == target_y:
            return moves_count
        
        for dx, dy in moves:
            new_x, new_y = x + dx, y + dy
            if is_valid_move(new_x, new_y, l) and not visited[new_x][new_y]:
                visited[new_x][new_y] = True
                queue.append((new_x, new_y, moves_count + 1))
    
    return -1

# Read number of test cases
test_cases = int(input())

for _ in range(test_cases):
    l = int(input())  # Chessboard size
    current_x, current_y = map(int, input().split())  # Current position of knight
    target_x, target_y = map(int, input().split())  # Target position

    # Calculate minimum moves
    result = min_moves_to_destination(l, current_x, current_y, target_x, target_y)
    print(result)
