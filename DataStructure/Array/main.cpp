#include <iostream>

using namespace std;

void show_array(int arr[], int size);

int main(){
    //un-initialized array
    int arr1[5];
    int sizearray = (sizeof(arr1) / sizeof(int));
    show_array(arr1, sizearray);
    //initialized array
    int arr2[] = {1, 2, 3, 4, 5};
    sizearray = (sizeof(arr1) / sizeof(int));
    show_array(arr2, sizearray);


}

void show_array(int arr[], int size){
    cout << "Array elements: " << endl;
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}