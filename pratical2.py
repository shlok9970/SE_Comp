def longest_word(s):
    words = s.split()
    longest = max(words, key=len)
    return longest

def character_frequency(s, char):
    return s.count(char)

def is_palindrome(s):
    cleaned_s = ''.join(e for e in s if e.isalnum()).lower()  # Remove non-alphanumeric characters and convert to lower case
    return cleaned_s == cleaned_s[::-1]

def first_substring_index(s, substring):
    return s.find(substring)

def word_occurrences(s):
    words = s.split()
    occurrences = {}
    for word in words:
        occurrences[word] = occurrences.get(word, 0) + 1
    return occurrences

# Example usage
if __name__ == "__main__":
    input_string = "A man a plan a canal Panama"
    substring = "plan"
    character = 'a'

    print("Longest word:", longest_word(input_string))
    print("Frequency of character '{}': {}".format(character, character_frequency(input_string, character)))
    print("Is the string a palindrome?:", is_palindrome(input_string))
    print("First appearance of substring '{}': {}".format(substring, first_substring_index(input_string, substring)))
    print("Word occurrences:", word_occurrences(input_string))
