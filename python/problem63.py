def PowStrs(bmax, pmax):
  for b in range(bmax):
    for p in range(pmax):
      q = b**p
      if p == len(str(q)):
        yield '%d**%d:%d' % (b, p, q)

def main():
  r = [s for s in PowStrs(50, 50)]
  print r
  print len(r)

if __name__ == '__main__':
  main()
