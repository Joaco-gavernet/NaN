# Swapping values of two variables
a, b = 5, 3
a, b = b,a

import random

# Returns random integer between 1 and 10 (including 1 and 10)
x = random.randint(1,10)

# Returns randomly selected element from list
choices = ["apple", "banana", "cherry"]
x = random.choice(choices)

# Check if number is ODD
if a & 1 == 1:
  print(f"{a} is odd")
else:
  print(f"{a} is even")

x = 5 % -2   # -1 (because 5 - (-3 * -2) = 5 - 6 = -1)
x = -5 % 2   # 1 (because -5 - (-3 * 2) = -5 - (-6) = 1)

# Defining empty list
l = []
l = list()

# Extending an existing list
l.extend([2,3]) # Changes l to [1,2,3]

# Inserting an element at specific index
l.insert(1, 100)

# Removing a single element from the end
x = l.pop()

# Removing an element from specific index
x = l.pop(2)

# Merging two lists (does not change existing list)
x = l + [4,5] # Returns [1,2,3,4,5]

# Removing first occurance of an element
l.remove(2)

# Getting sublist
l = [0,1,2,3,4,5,6]
l1 = l[2:4]  # Returns [2,3]

# Quickly make a copy of list
l1 = l[:]

# Swapping two elements
l[0], l[2] = l[2], l[0]

# Remember, the Opposite of `insert` is `pop` and not `remove` 
# because `insert` and `pop` works at the index level 
# while `remove` works at the value level.

# Initializing
l = list({"a"}) # From set -> ["a"]

d = {"a": 1, "c": 2}
l = list(d) # From dict keys -> ["a", "c"]
l = list(d.keys()) # From dict keys -> ["a", "c"]
l = list(d.values()) # From dict values -> [1,2]
l = list(d.items()) # From dict key-values -> [("a", 1), ("c", 2)]
l = [1]*n # List with 1 repeated n times
l = list(range(10)) # Returns [0,1,2,3..,8,9]

# List comprehension : Preparing list from another iterable
l = [x+1 for x in nums]

nums = [5,1,4,9,8]

# Iterating with index
for i, n in enumerate(nums):
    print(f"Index: {i} , number: {n}")

# Iterating over range with step size = 2
for i in range(0,n,2):
    print(i)

# Iterating in reverse

# Option 1
for i in range(len(nums)):
    print(nums[~i])

# Option 2
for i in range(len(nums), -1, -1):
    print(nums[i])
    
# Two pointer (left and right end) iteration
for i in range(len(nums)//2):
    print(i) # 0,1,2
    print(~i) # -1 (i.e. 4), -2 (i.e. 3), -3(i.e. 2)

# Iterate over two lists
for x, y in zip(l1, l2):
    print(x)
    print(y)
for i, (x, y) in enumerate(zip(l1,l2)):
    print(f"Index: {i}, x: {x}, y: {y}")

# Safely removing element from list while iterating
nums = [1,2,3,4]
for n in nums[:]:
    if n % 2 == 0:
        nums.remove(n)

# NEVER remove an element while iterating over a list. 
# If required, copy a list and then remove it from the original one :)

nums = [5,1,4,9,8]

# In-place sorting
nums.sort() # Ascending order
nums.sort(reverse=True) # Descending order

# Getting new sorted list
new_nums = sorted(nums) # Ascending order
new_nums = sorted(nums, reverse=True) # Descending order

# Sorting list with custom lambda function (supported by sort and sorted)

# Example 1
nums = [1,-1,3,2,-3,-4]
nums.sort(key=abs) # Sort based on absolute value

# Example 2
nums = ["apple", "banana", "cherry"]
nums.sort(key=len) # Sort based on length

# Example 3 (list of tuples)
nums = [(0,1), (3,1), (1,2)]
nums.sort(key = lambda x : x[1]) # Sorts based on first element

# Example 4 (list of dictionaries)
nums = [{"age": 18, "name": "x"}, {"age": 12, "name": "y"}]
nums.sort(key = lambda x: x["age"]) # Sorts based age

from collections import Counter

c = Counter([1,2,4,1,2,5]) # Counter({1: 2, 2: 2, 4: 1, 5: 1})
for k, v in c.items():
    print(f"Element: {k}, Frequency: {v}")

# Membership checking
x = 1 in c

# Updating frequency
c[1] = 1

# Removing character
del c[1]

from bisect import bisect_left, bisect_right

l = [1,2,2,3,4]
x = bisect_left(l, -1) # Returns 0
x = bisect_right(l, -1) # Returns 0

x = bisect_left(l, 10) # Returns 5
x = bisect_right(l, 10) # Returns 5

x = bisect_left(l, 2) # Returns 1 (index of first occurence of 2)
x = bisect_right(l, 2) # Returns 3 (1 + index of last occurence of 2)

# For normal binary search usecases, use following code
target = 3
x = bisect_left(l, target)
if x != len(l) and l[x] == target:
    print(f"Target : {target} is found at index : {x}")

# Check if list has all even numbers
output = all(x%2 == 0 for x in nums)

# Check if list has one or more zero value
output = any(x == 0 for x in nums)

# Check if string is palindrome
is_pal = all(s[i] == s[~i] for i in range(len(s)//2)

from itertools import permutations, combinations

items = ["A", "B", "C"]

# Iterate over all combinations of length 2
# This is same as nC2 : Picking 2 elements out of given elements
for c in combinations(items, 2):
    print(c) # Prints ("A", "B"), ("A", "C"), ("B", "C")

# Iterate over all permutations
for p in permutations(items):
    print(p)

# Iterate over all permutations of length 2
for p in permutations(items, 2):
    print(p)

# Defining empty dict
d = {}
d = dict()

# Add/Update value against key
d["a"] = 1

# Get value of key
x = d["a"] # Raises KeyError if key is not present
x = d.get("a", None) # Returns default value if key is not present

# Get a value and delete key
if "a" in d:
   x = d.pop("a")

# Delete key
if "a" in d:
  del d["a"]

# Sorting returns sorted keys
sorted_Keys = sorted({"x": 1, "a": 2}) # Returns ["a", "x"]

# Pop first inserted key
d.pop(next(iter(d)))


# defaultdict returns a default value if the key is not present 
# rather than raising KeyError

from collections import defaultdict

# initializes non-present key with value 0
d = defaultdict(int)

# initializes non-present key with value 1
d = defaultdict(lambda : 1)

# initializes non-present key with empty list ([])
d = defaultdict(list)

# initializes non-present key with empty dict ({})
d = defaultdict(dict)

# Dictionary comprehension : Preparing dict from another iterable
d = { x : x%2 == 0 for x in nums }

# Create a dictionary from list/tuple of 2 length strings
d = dict(['()', '[]', '{}']) # Returns {'(': ')', '[': ']', '{': '}'}

# Tuples are immutable and can be used as dictionary keys or set elements.
# Whenever a function returns multiple values, it is returned as a tuple of values. 
# Hence, the caller can unpack those values.
# From the functions aspect, Tuple supports the same functions as List.

# Initialize tuple
t = (1, 2, 3)

# Make sure to add a comma to initialize single element tuple correctly
# Otherwise it is treated as integer
t = (1,)

# As tuples are immutable, this will raise a TypeError
t[0] = 4

# Allowed
d = {(1, 2): 'value'} # Tuple as dict keys
s = {(1, 2), (3, 4)}  # Tuple as set elements

# Unpacking
def multi_value_func():
    return 1, 2, 3
x, y, z = multi_value_func()

# A set stores unique elements.
# Set in Python are implemented using hash tables. 
# So insertion, lookup, and deletion have (amortized) have time complexity of O(1).
# From python 3.7 onwards, Set maintains insertion order. 
# So iterating over it returns elements in the same order as they were inserted.

s = set() # Defining an empty set
s.add(1) # Adding element
size = len(s) # Getting size of set

# Adding multiple elements to set
s.update([1,2,3])

# Removing already added element
if 1 in s:
  s.remove(1)
else:
  print("Removing an element that does not exist in set, throws KeyError.")

# Removing element irrespective of whether it exists in set or not
s.discard(1)

# Checking whether set is empty
if len(s) == 0:
  print("Set is empty")
if not s:
  print("Set is either empty or s is None")

# Looking for an element
if 1 in s:
  print("1 is part of set")

# Iterating over set
s = set([1,2])
for i, x in enumerate(s):
    print(f"Insertion Index {i} : Element : {x}")

s1 = {1,2,3}
s2 = {3,4,5}

union_set = s1 | s2 # {1,2,3,4,5}

intersection_set = s1 & s2 # {3}

diff_set = s1 - s2 # {1,2}

sym_diff_set = s1 ^ s2 # {1,2,4,5} (Just like XOR,returns what is not present in both)

s1 = {1,2,3}
s2 = {1,2,3,4}

s1 <= s2 # Subset test (True)
s1 >= s2 # Superset test (False)

# In python, List can be used as Stack.
# Initializing
stack = []

stack.append(1) # Push
x = stack[-1] # Top / Peek
x = stack.pop() # Pop
size = len(stack) # # Getting size of stack

if len(stack) == 0:
   print("Stack is empty")

from collections import deque

dq = deque() # Defining an empty deque

# Appending element at rear/back
dq.append(1)

# Appending element at front/head
dq.appendleft(1)

# Removing and getting element from rear/back
x = dq.pop()

# Removing and getting element from front/head
x = dq.popleft()

size = len(dq) # Getting length/size of deque

x = dq[-1] # Accessing element at rear
x = dq[0] # Accessing element at front
x = dq[3] # Accessing element at any index

# Checking whether deque is empty
if len(dq) == 0:
  print("Deque is empty")

# Looking for an element
if 1 in dq:
  print("1 is part of deque")

# Iterating over deque
for i, x in enumerate(dq):
    print(f"Index {i} : Element : {x}")

l1 = sorted(dq) # Sorted operation returns new list which is sorted
