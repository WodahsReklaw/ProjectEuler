# The nth term of the sequence of triangle numbers is given by:
# tn =1/2n(n+1); so the first ten triangle numbers are:
#   1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

# By converting each letter in a word to a number corresponding
# to its alphabetical position and adding these values we
# form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

# Using words.txt (right click and 'Save Link/Target As...'),
# a 16K text file containing nearly two-thousand common English
# words, how many are triangle words?

INPUT_FILE = '../data/p042_words.txt'
CH_OFFSET = ord('A') - 1

def main():
  word_val_dict = {}
  triangle_nums = set(int(0.5*n*(n+1)) for n in range(1, 25))
  with open(INPUT_FILE) as fh:
    words = fh.read().split(',')
  for word in words:
    word = word.replace('"', '')
    word_val_dict[word] = sum([ord(ch) - CH_OFFSET for ch in word])
  print sum([1 for val in word_val_dict.values() if val in triangle_nums])

if __name__ == '__main__':
  main()
