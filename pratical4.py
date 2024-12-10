def linear_search(roll_numbers, target):
    """Perform linear search to find the target roll number."""
    for index, roll in enumerate(roll_numbers):
        if roll == target:
            return index  # Return the index if found
    return -1  # Return -1 if not found

def sentinel_search(roll_numbers, target):
    """Perform sentinel search to find the target roll number."""
    n = len(roll_numbers)
    if n == 0:
        return -1  # Return -1 if the list is empty

    # Store the last element
    last = roll_numbers[-1]
    roll_numbers[-1] = target  # Set the last element to the target

    index = 0
    while roll_numbers[index] != target:
        index += 1

    # Restore the last element
    roll_numbers[-1] = last

    # Check if the target was found
    if index < n - 1 or roll_numbers[-1] == target:
        return index  # Return the index if found
    return -1  # Return -1 if not found

# Example usage
if __name__ == "__main__":
    # List of roll numbers of students who attended the training program
    roll_numbers = [101, 102, 103, 104, 105, 106, 107, 108, 109, 110]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to search: "))

    # Linear Search
    linear_result = linear_search(roll_numbers, target_roll_number)
    if linear_result != -1:
        print(f"Linear Search: Roll number {target_roll_number} found at index {linear_result}.")
    else:
        print(f"Linear Search: Roll number {target_roll_number} not found.")

    # Sentinel Search
    sentinel_result = sentinel_search(roll_numbers, target_roll_number)
    if sentinel_result != -1:
        print(f"Sentinel Search: Roll number {target_roll_number} found at index {sentinel_result}.")
    else:
        print(f"Sentinel Search: Roll number {target_roll_number} not found.")