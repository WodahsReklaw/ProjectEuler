from numpy import prod

def Choose(n, k):
  return prod([(n+1-i)/float(i) for i in range(1, k+1)])

def main():
  print Choose(23, 10)
  answer = 0
  for n in range(1, 101):
    for k in range(1, n+1):
      answer += 1 if Choose(n, k) > 1e6 else 0
  print answer

if __name__ == '__main__':
  main()
