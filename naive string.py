def naive_string_match(text, pattern):
    positions = []
    for i in range(len(text) - len(pattern) + 1):
        if text[i:i + len(pattern)] == pattern:
            positions.append(i)
    return positions


text = input("Enter the text string: ")
pattern = input("Enter the pattern string: ")

if len(pattern) > len(text):
    print("Error: Pattern length cannot be greater than text length.")
elif not text or not pattern:
    print("Please enter both text and pattern.")
else:
    matches = naive_string_match(text, pattern)
    if matches:
        print("Pattern found at starting indices:", matches)
    else:
        print("No match found.")