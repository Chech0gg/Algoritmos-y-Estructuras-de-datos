#include <iostream>
using namespace std;
int f(int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
             c++;
 return c;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
/*Para cada i, j va de i hasta n-1, es decir n - i vueltas.
Total = n + (n-1) + ... + 1 = n(n+1)/2 = (n² + n)/2. Complejidad: O(n²). Comprobación con n =
4: 4 + 3 + 2 + 1 = 10 = 4·5/2. ✔*/
