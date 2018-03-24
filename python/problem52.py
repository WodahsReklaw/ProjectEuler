from itertools import permutations
from typing import List, Set

LIMIT = 1000000

def DigitsToConsider():
  for i in range(10, LIMIT):
    if len(str(i*6)) == len(str(i)):
      yield i

def HistDigits(i: 'int') -> List:
  digit_hist = [0] * 10
  for digit in str(i):
    digit_hist[int(digit)] += 1
  return digit_hist

def Solution():
  for i in DigitsToConsider():
    ref_hist = HistDigits(i)
    do_yield = True
    for mult in [6, 5, 4, 3, 2]:
      this_hist = HistDigits(i*mult)
      if this_hist != ref_hist:
        do_yield = False
        break
    if do_yield:
      [print(n*i) for n in range(1,7)]
      return

def main():
  Solution()

if __name__ == '__main__':
  main()
