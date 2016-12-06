#include <iostream>

using namespace std;


void quickSort(int arr[], int left, int right);

int main(int argc, char *argv[]){
      int arr[9] = {8,3,11,839,77,63,11, 57,0};
      int len_a = (sizeof(arr))/(sizeof(*arr));
      quickSort(arr,0,len_a);
      for(int i = 0; i < len_a ; i++){
            cout << arr[i] << endl;
      } 


} 


void quickSort(int arr[], int left, int right) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


