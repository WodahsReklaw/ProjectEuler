import sys

MAX_LIMIT = 50

def IsLychrel(num):
  for _ in range(MAX_LIMIT+1):
    num = num + int(str(num)[::-1])
    if str(num) == str(num)[::-1]:
      return False
  return True


def main(argv):
  upper_range = int(argv[1])
  res = sum(1 for n in range(1, upper_range) if IsLychrel(n))
  print res


if __name__ == '__main__':
  main(sys.argv)
