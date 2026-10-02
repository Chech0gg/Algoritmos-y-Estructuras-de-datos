// temperatura
// calculamos cuantos días hasta que la temperatura sea mayor
// entrada [73,74,75,71,69,72,76,73]
// salida [1,1,4,2,1,1,0,0]
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> diacalormay(vector<int> arr) {
    stack <int> pila;
    int n = arr.size();
    vector<int> res(n,0);
    for (int i = 0 ; i < n ; i++){
        while (!pila.empty() && arr[pila.top()] < arr[i]){
            res[pila.top()] = i -pila.top();
            pila.pop();

        }
        pila.push(i);
    }
    return res;

}
int main() {
    vector<int> result = diacalormay({73,74,75,71,69,72,76,73});
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }   
    cout << endl;
    return 0;
}
