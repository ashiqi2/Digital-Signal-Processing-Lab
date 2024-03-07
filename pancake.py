
from collections import deque


def flip(pancakes, i):
    return pancakes[:i+1][::-1] + pancakes[i+1:]


def is_sorted(pancakes):
    return all(pancakes[i] <= pancakes[i+1] for i in range(len(pancakes)-1))


def pancake_sort(pancakes):
    visited = set()
    queue = deque([(pancakes, 0)])

    while queue:
        current_pancakes, flips = queue.popleft()

        if is_sorted(current_pancakes):
            return current_pancakes, flips

        for i in range(1, len(current_pancakes)+1):
            new_state = flip(current_pancakes, i)
            if tuple(new_state) not in visited:
                visited.add(tuple(new_state))
                queue.append((new_state, flips + 1))

    return None


# Example usage:
initial_pancakes = [1, 10, 9, 2, 6, 5, 3, 5]
sorted_pancakes, flips_needed = pancake_sort(initial_pancakes)

print("Initial Pancakes:", initial_pancakes)
print("Sorted Pancakes:", sorted_pancakes)
print("Flips Needed:", flips_needed)
