def binary_search(roll_numbers, target):
    """Perform binary search to find the target roll number."""
    left, right = 0, len(roll_numbers) - 1
    while left <= right:
        mid = (left + right) // 2
        if roll_numbers[mid] == target:
            return mid  # Return the index if found
        elif roll_numbers[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1  # Return -1 if not found

def fibonacci_search(roll_numbers, target):
    """Perform Fibonacci search to find the target roll number."""
    n = len(roll_numbers)
    fib_m2 = 0  # (m-2)'th Fibonacci number
    fib_m1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m2 + fib_m1  # m'th Fibonacci number

    # Find the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m2, fib_m1 = fib_m1, fib_m
        fib_m = fib_m2 + fib_m1

    offset = -1

    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)

        if roll_numbers[i] < target:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        elif roll_numbers[i] > target:
            fib_m = fib_m2
            fib_m1 -= fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            return i  # Return the index if found

    # Check the last element
    if fib_m1 and offset + 1 < n and roll_numbers[offset + 1] == target:
        return offset + 1

    return -1  # Return -1 if not found

# Example usage
if __name__ == "__main__":
    # Sorted list of roll numbers of students who attended the training program
    roll_numbers = [101, 102, 103, 104, 105, 106, 107, 108, 109, 110]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to search: "))

    # Binary Search
    binary_result = binary_search(roll_numbers, target_roll_number)
    if binary_result != -1:
        print(f"Binary Search: Roll number {target_roll_number} found at index {binary_result}.")
    else:
        print(f"Binary Search: Roll number {target_roll_number} not found.")

    # Fibonacci Search
    fibonacci_result = fibonacci_search(roll_numbers, target_roll_number)
    if fibonacci_result != -1:
        print(f"Fibonacci Search: Roll number {target_roll_number} found at index {fibonacci_result}.")
    else:
        print(f"Fibonacci Search: Roll number {target_roll_number} not found.")