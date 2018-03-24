def permute(a_list):
  if len(a_list) < 3:
    if len(a_list) == 2:
      yield a_list
      yield a_list[::-1]
    else:
      yield a_list
  else:
    for p in permute(a_list[1:]):
      for i in range(len(p)+1):
        yield p[:i] + a_list[:1] + p[i:]
