#include <iostream>

using namespace std;

int main(){
    int arr[5];
    int sizearray = (sizeof(arr) / sizeof(int));
    for (int i = 0 ; i < sizearray ; i++){
        cout << arr[i]<< " ";
    }
    cout << endl;
}