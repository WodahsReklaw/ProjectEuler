# The number, 1406357289, is a 0 to 9 pandigital number
# because it is made up of each of the digits 0 to 9 in
# some order, but it also has a rather interesting
# sub-string divisibility property.

# Let d1 be the 1st digit, d2 be the 2nd digit,
# and so on. In this way, we note the following:

# d2d3d4=406 is divisible by 2
# d3d4d5=063 is divisible by 3
# d4d5d6=635 is divisible by 5
# d5d6d7=357 is divisible by 7
# d6d7d8=572 is divisible by 11
# d7d8d9=728 is divisible by 13
# d8d9d10=289 is divisible by 17
# Find the sum of all 0 to 9 pandigital numbers with this property.

# ans = 16695334890

import permute

def IsSubDiv(s):
  if (int(s[2:5]) % 3 or
      int(s[4:7]) % 7 or
      int(s[5:8]) % 11 or
      int(s[6:9]) % 13 or
      int(s[7:10]) % 17):
    return False
  else:
    return True

def Solution():
  permute_base = '0123456789'
  answer = 0
  for d4 in ['2', '4', '6', '8', '0']:
    d6 = '5'
    this_perm = permute_base.replace(d4, '').replace(d6, '')
    for p in permute.permute(this_perm):
      num_str = p[:3] + d4 + p[3] + d6 + p[4:]
      if IsSubDiv(num_str):
        answer += int(num_str)
  print answer

if __name__ == '__main__':
  Solution()
