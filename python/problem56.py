def Solution():
  sums = []
  for a in range(100):
    for b in range(100):
      sums.append(sum(int(ch) for ch in str(a**b)))
  return max(sums)

def main():
  print Solution()

if __name__ == '__main__':
  main()
