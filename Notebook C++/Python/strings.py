sls = s.lstrip() # Removes space from left end
srs = s.rstrip() # Removes space from right end
ss = s.strip() # Removes space from both ends but not from the middle

# Joining list of strings to single string
# Without any delimeter
x = "".join(["I", "am", "learning", "python"]) # Returns "Iamlearningpython"
# With delimeter
x = " ".join(["I", "am", "learning", "python"]) # Returns "I am learning python"

lower_case_s = s.lower()
upper_case_s = s.upper()

# To check if string has all characters as either digit or alphabet
x = s.isalnum()

# To check if string has all alphabets
x = s.isalpha()

# To check if string has all digits
x = s.isnum()

# To check if string has all spaces
x = isspace()

# Get unicode/ascii representation of character
x = ord("b") # Returns 98

# Slicing
x = s[2:4] # Return "sa"

# Sorting
x = sorted(s) # Returns ['a', 's', 't', 'u', 'v']
x = sorted(s, reverse=True) # Returns ['v', 'u', 't', 's', 'a']

# Membership check
"a" in "utsav" # Returns True

# Prefix and Suffix Check
s = "prefix"

# To check if string contains pre as prefix
x = s.startswith("pre") #Returns True

# To check if string contains fix as suffix
x = s.endswith("fix") #Returns True

# Finding substring
s1 = "hello world programming"
subs1 = "world"
start_index = s1.find(subs1) # Returns 6
