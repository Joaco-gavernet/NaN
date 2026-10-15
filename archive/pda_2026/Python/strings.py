sls = s.lstrip() # Removes space from left end
srs = s.rstrip() # Removes space from right end
ss = s.strip() # Removes space from both ends but not from the middle
x = "".join(["I", "am", "learning", "python"]) # Returns "Iamlearningpython"
x = " ".join(["I", "am", "learning", "python"]) # With delimeter # Returns "I am learning python"

lower_case_s = s.lower()
upper_case_s = s.upper()
x = s.isalnum() # To check if string has all characters as either digit or alphabet
x = s.isalpha() # To check if string has all alphabets
x = s.isnum() # To check if string has all digits
x = isspace() # To check if string has all spaces
x = ord("b") # Returns 98 # Get unicode/ascii representation of character
x = s[2:4] # Return "sa" # Slicing
x = sorted(s) # Returns ['a', 's', 't', 'u', 'v']
x = sorted(s, reverse=True) # Returns ['v', 'u', 't', 's', 'a']
"a" in "utsav" # Returns True
s = "prefix"
x = s.startswith("pre") #Returns True
x = s.endswith("fix") #Returns True
s1 = "hello world programming"
subs1 = "world"
start_index = s1.find(subs1) # Returns 6
