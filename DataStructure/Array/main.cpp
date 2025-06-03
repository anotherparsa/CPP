#include <iostream>

using namespace std;

void show_array(int arr[], int size);
void insert_element(int arr[], int &number, int position, int value);

int main(){
    /*//un-initialized array
    int arr1[5];
    int sizearray = (sizeof(arr1) / sizeof(int));
    show_array(arr1, sizearray);

    //initializing array
    arr1[0] = 10;
    arr1[1] = 20;
    sizearray = (sizeof(arr1) / sizeof(int));
    show_array(arr1, sizearray);
    // pre initialized array
    int arr2[] = {1, 2, 3, 4, 5};
    sizearray = (sizeof(arr1) / sizeof(int));
    show_array(arr2, sizearray);*/
    const int max_size = 5;
    int arr[max_size] = {1, 3};
    int current_number_of_element = 2;
    int size = (sizeof(arr) / sizeof(int));
    cout << "Before inserting an element :" << endl;
    cout << "Number of element : " << current_number_of_element << endl;
    show_array(arr, size);
    insert_element(arr, current_number_of_element, 1, 2);
    cout << "After Inserting an elment: " << endl;
    cout << "Number of element : " << current_number_of_element << endl;
    show_array(arr, size);





}

void show_array(int arr[], int size){
    cout << "Array elements: " << endl;
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert_element(int arr[], int &number, int position, int value){
    for (int i = number - 1; i >= position ; i--){
        arr[i+1] = arr[i];
    }
    arr[position] = value;
    ++number;

}