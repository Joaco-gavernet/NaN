import random
x = random.randint(1,10) # (including 1 and 10)

choices = ["apple", "banana", "cherry"]
x = random.choice(choices) # Returns random element from list

x = 5 % -2   # -1 (because 5 - (-3 * -2) = 5 - 6 = -1)
x = -5 % 2   # 1 (because -5 - (-3 * 2) = -5 - (-6) = 1)

# Remember, the Opposite of `insert` is `pop` and not `remove`, because `insert` and `pop` works at the index level, while `remove` works at the value level.
l = list() # Defining empty list (l = [])
l.extend([2,3]) # Extending an existing list
l.insert(1, 100) # Inserting at specific index
x = l.pop()
x = l.pop(2) # Removing from specific index
x = l + [4,5] # Merging two lists (does not change existing list)
l.remove(2) # Removing first occurance of an element
l = [0,1,2,3,4,5,6]
l1 = l[2:4]  # Getting sublist, returns [2,3]
l1 = l[:] # Quickly make a copy of list
l[0], l[2] = l[2], l[0] # Swapping two elements
l = list({"a"})  # Initializing, from set -> ["a"]
d = {"a": 1, "c": 2}
l = list(d) # From dict keys -> ["a", "c"]
l = list(d.keys()) # From dict keys -> ["a", "c"]
l = list(d.values()) # From dict values -> [1,2]
l = list(d.items()) # From dict key-values -> [("a", 1), ("c", 2)]
l = [1]*n # List with 1 repeated n times
l = list(range(10)) # Returns [0,1,2,3..,8,9]
l = [x+1 for x in nums] # Preparing list from another iterable

nums = [5,1,4,9,8]
for i, n in enumerate(nums): # Iterating with index
    print(f"Index: {i} , number: {n}")
for i in range(0,n,2): # Iterating over range with step size = 2
    print(i)
# Iterating in reverse
for i in range(len(nums)): # Option 1
    print(nums[~i])
for i in range(len(nums), -1, -1): # Option 2
    print(nums[i])
for i in range(len(nums)//2): # Two pointer (left and right end) iteration
    print(i) # 0,1,2
    print(~i) # -1 (i.e. 4), -2 (i.e. 3), -3(i.e. 2)
for x, y in zip(l1, l2): # Iterate over two lists
    print(x)
    print(y)
for i, (x, y) in enumerate(zip(l1,l2)):
    print(f"Index: {i}, x: {x}, y: {y}")
nums = [1,2,3,4]
# NEVER remove an element while iterating over a list. 
# If required, copy a list and then remove it from the original one :)
for n in nums[:]: # Safely removing element from list while iterating
    if n % 2 == 0:
        nums.remove(n)

nums = [5,1,4,9,8]
nums.sort() # In-place sorting
nums.sort(reverse=True) # Descending order
new_nums = sorted(nums) # Getting new sorted list
new_nums = sorted(nums, reverse=True) # Descending order
# Sorting list with custom lambda function (supported by sort and sorted)
nums = [1,-1,3,2,-3,-4]
nums.sort(key=abs) # Sort based on absolute value
nums = ["apple", "banana", "cherry"]
nums.sort(key=len) # Sort based on length
nums = [(0,1), (3,1), (1,2)]
nums.sort(key = lambda x : x[1]) # Sorts based on first element
nums = [{"age": 18, "name": "x"}, {"age": 12, "name": "y"}]
nums.sort(key = lambda x: x["age"]) # Sorts based age

from collections import Counter
c = Counter([1,2,4,1,2,5]) # Counter({1: 2, 2: 2, 4: 1, 5: 1})
for k, v in c.items():
    print(f"Element: {k}, Frequency: {v}")
x = 1 in c # Membership checking
c[1] = 1 # Updating frequency
del c[1] # Removing character

from bisect import bisect_left, bisect_right # Equivalent to lower_bound and upper_bound
l = [1,2,2,3,4]
x = bisect_left(l, -1) # Returns 0
x = bisect_right(l, -1) # Returns 0
x = bisect_left(l, 10) # Returns 5
x = bisect_right(l, 10) # Returns 5
x = bisect_left(l, 2) # Returns 1 (index of first occurence of 2)
x = bisect_right(l, 2) # Returns 3 (1 + index of last occurence of 2)

output = all(x%2 == 0 for x in nums) # Check if list has all even numbers
output = any(x == 0 for x in nums) # Check if list has one or more zero value
is_pal = all(s[i] == s[~i] for i in range(len(s)//2) # Check if string is palindrome

from itertools import permutations, combinations
items = ["A", "B", "C"]
# Iterate over all combinations of length 2, same as nC2 : Picking 2 elements out of given elements
for c in combinations(items, 2):
    print(c) # Prints ("A", "B"), ("A", "C"), ("B", "C")
for p in permutations(items): # Iterate over all permutations
    print(p)
for p in permutations(items, 2): # Iterate over all permutations of length 2
    print(p)

d = dict() # Defining empty dict, also d = {}
d["a"] = 1 # Add/Update value against key
x = d["a"] # Raises KeyError if key is not present
x = d.get("a", None) # Returns default value if key is not present
if "a" in d: # Get a value and delete key
   x = d.pop("a")
if "a" in d: # Delete key
  del d["a"]
sorted_Keys = sorted({"x": 1, "a": 2}) # Returns ["a", "x"]
d.pop(next(iter(d))) # Pop first inserted key
# defaultdict returns a default value if the key is not present, rather than raising KeyError
from collections import defaultdict
d = defaultdict(int) # initializes non-present key with value 0
d = defaultdict(lambda : 1) # initializes non-present key with value 1
d = defaultdict(list) # initializes non-present key with empty list ([])
d = defaultdict(dict) # initializes non-present key with empty dict ({})
d = { x : x%2 == 0 for x in nums } # Dictionary comprehension : Preparing dict from another iterable
d = dict(['()', '[]', '{}']) # Returns {'(': ')', '[': ']', '{': '}'} # Create a dictionary from list/tuple of 2 length strings

# Tuples are immutable and can be used as dictionary keys or set elements.# Whenever a function returns multiple values, it is returned as a tuple of values. 
# Hence, the caller can unpack those values. # From the functions aspect, Tuple supports the same functions as List.
t = (1, 2, 3) # Initialize tuple
t = (1,) # Make sure to add a comma to initialize single element tuple correctly # Otherwise it is treated as integer
t[0] = 4 # As tuples are immutable, this will raise a TypeError
d = {(1, 2): 'value'} # Tuple as dict keys
s = {(1, 2), (3, 4)}  # Tuple as set elements
def multi_value_func(): # Unpacking
    return 1, 2, 3
x, y, z = multi_value_func()
# A set stores unique elements. # Set in Python are implemented using hash tables. # So insertion, lookup, and deletion have (amortized) have time complexity of O(1). # From python 3.7 onwards, Set maintains insertion order. # So iterating over it returns elements in the same order as they were inserted.
s = set() # Defining an empty set
s.add(1) # Adding element
size = len(s) # Getting size of set
s.update([1,2,3]) # Adding multiple elements to set
if 1 in s: # Removing already added element
  s.remove(1)
else:
  print("Removing an element that does not exist in set, throws KeyError.")
s.discard(1) # Removing element irrespective of whether it exists in set or not
if len(s) == 0: # Checking whether set is empty
  print("Set is empty")
if not s:
  print("Set is either empty or s is None")
s = set([1,2])
for i, x in enumerate(s): # Iterating over set
    print(f"Insertion Index {i} : Element : {x}")
s1 = {1,2,3}, s2 = {3,4,5}
union_set = s1 | s2 # {1,2,3,4,5}
intersection_set = s1 & s2 # {3}
diff_set = s1 - s2 # {1,2}
sym_diff_set = s1 ^ s2 # {1,2,4,5} (Just like XOR,returns what is not present in both)
s1 <= s2 # Subset test (True)
s1 >= s2 # Superset test (False)

stack = [] # In python, List can be used as Stack.
stack.append(1) # Push
x = stack[-1] # Top / Peek
x = stack.pop() # Pop
size = len(stack) # # Getting size of stack

from collections import deque
dq = deque() # Defining an empty deque
dq.append(1) # Appending element at rear/back
dq.appendleft(1) # Appending element at front/head
x = dq.pop() # Removing and getting element from rear/back
x = dq.popleft() # Removing and getting element from front/head
size = len(dq) # Getting length/size of deque
x = dq[-1] # Accessing element at rear
x = dq[0] # Accessing element at front
x = dq[3] # Accessing element at any index
if len(dq) == 0: # Checking whether deque is empty
  print("Deque is empty")
if 1 in dq: # Looking for an element
  print("1 is part of deque")
for i, x in enumerate(dq): # Iterating over deque
    print(f"Index {i} : Element : {x}")
l1 = sorted(dq) # Sorted operation returns new list which is sorted