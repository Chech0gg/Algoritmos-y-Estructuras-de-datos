def recoger(n, k):
    if n == 0:
        return 0
    if n % 2 == 0:
         return k + recoger(n - 1, k + 1)
    return recoger(n - 1, k)
print(recoger(5, 1))