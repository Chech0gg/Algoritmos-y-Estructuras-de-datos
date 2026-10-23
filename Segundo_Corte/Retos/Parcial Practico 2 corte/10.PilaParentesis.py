def balanceada(s):
    pareja = {')': '(', ']': '[', '}': '{'}
    pila = []
    for c in s:
        if c in '([{':
            pila.append(c)
        elif c in pareja:
            if not pila or pila.pop() != pareja[c]:
                return False
    # El return debe estar fuera del for para evaluar toda la cadena
    return not pila

print(balanceada("(a[b]{c})"))  # True
print(balanceada("([)]"))      # False
print(balanceada("(("))        # False
print(balanceada(""))          # True
print(balanceada("a)b("))      # False