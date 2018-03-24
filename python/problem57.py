# 1 + 1/(2 + 1/2) N = 1 Save 1/(2 + 1/2) -> 2/5
# 1 + 1/(2 + 1/(2 + 1/2)) N = 2, Save 1/(2 + 2/5) -> 5/12
# 1 + 1/(2 + 1/(2 + 1/2)) N = 3, Save 1/(2 + 5/12) -> 12/29 -> 41/29
# First iteration -> 2 + 1/2 -> 1/(5/2) -> 1 + 2/5 -> 7/5
# Second iteration -> 1/(2 + 1/(5/2)) ->  2 + 2/5 -> 12/5 -> 1 + 5/12 -> 17/12

import typing

from collections import namedtuple

def GCD(a: int, b: int) -> int:
  if b == 0:
    return a
  while (b):
    tmp = b
    b = a % b
    a = tmp
  return a

class Fraction(object):

  def __init__(self, n: int, d: int):
    gcd = GCD(n, d) if n > d else GCD(d, n)
    n = n//gcd
    d = d//gcd
    if d == 0:
      raise ValueError('Cannot create a fraction with a 0 denominator')

    self._num = n
    self._denom = d

  @property
  def num(self) -> int:
    return self._num

  @property
  def denom(self) -> int:
    return self._denom

  def recip(self):
    return Fraction(self._denom, self._num)

  def add(self, f):
    n = self._num * f._denom + f._num * self._denom
    d = f._denom * self._denom
    return Fraction(n, d)

  def __str__(self):
    return '%d/%d' % (self._num, self._denom)

def IterSqrt():
  # Iterations of the fraction
  frac = Fraction(2, 5)
  two = Fraction(2, 1)
  fracts = [frac]
  for _ in range(1000):
    fracts.append(fracts[-1].add(two).recip())

  res = [f.add(Fraction(1, 1)) for f in fracts]
  answer = sum(1 for f in res if len(str(f.num)) > len(str(f.denom)))
  print(answer)

def main():
  IterSqrt()

if __name__ == '__main__':
  main()
