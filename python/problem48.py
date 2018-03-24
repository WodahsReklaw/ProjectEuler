import sys

def SelfPow(a):
  res = 1
  for _ in range(a):
    res = a*res % 10**10
  return res

def main(argv):
  print sum(SelfPow(a) for a in range(1, int(argv[1])+1)) % 10**10

if __name__ == '__main__':
  main(sys.argv)
