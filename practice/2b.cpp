
#include <iostream>
#include <algorithm>

using namespace std;

int waysearch2(int arr[1000],int searchelement){
    

    int beg=0;
    int end=999;

    int mid = (beg+end)/2;

    while(beg<=end){
        if (arr[mid]<searchelement){
            beg=mid+1;
        }
        else if (arr[mid]==searchelement){
            return 1;
        }
        else{
            end = mid - 1;
        }

        mid = (beg+end)/2;

        if (beg>end)
            return 0;
    }

}

int ternarysearch(int array[1000],int sizeofarray,int left,int right,int searchelement){

    if (left<0 || right>sizeofarray-1 || left>right){
        return -1;
    }

    if (searchelement == array[left]){
        return left;
    }

    if (searchelement == array[right]){
        return right;
    }

    if (searchelement < array[left]){
        return ternarysearch(array,sizeofarray,left-1,right,searchelement);
    }
    else if(searchelement > array[left] && searchelement < array[right]){
        return ternarysearch(array,sizeofarray,left+1,right-1,searchelement);
    }

    if (searchelement>array[right]){
        return ternarysearch(array,sizeofarray,left,right+1,searchelement);
    }

}

int fourwaysearch(int array[1000],int sizeofarray, int searchelement,int small,int big){
    //array is sorted

    int one = (low+high)/4;
    int two = one*2;
    int three = one*3;

    if(low<0 || high>sizeofarray-1 || one>two || two>three || one>three){
        return -1;
    }

    if (searchelement==array[low]){
        return low;
    }
    if (searchelement==array[high]){
        return high;
    }

    if (searchelement==one){
        return one;
    }

    if (searchelement==two){
        return two;
    }

    if (searchelement==three){
        return three;
    }

    if (searchelement<array[one]){
        return fourwaysearch(array,sizeofarray,searchelement,low,one-1);
    }

    if (searchelement>one && searchelement<two){
        return fourwaysearch(array,sizeofarray,searchelement,one+1,two-1);
    }

    if (searchelement>two && searchelement<three){
        return fourwaysearch(array,sizeofarray,searchelement,two+1,three-1);
    }

    if (searchelement>three && searchelement<high){
        return fourwaysearch(array,sizeofarray,searchelement,three+1,high);
    }

}

int main(){

int n=80;

    while(n>0) {
        array<int, 1000> array1;

        time_t t;
        srand((unsigned) time(&t));

        for (int i = 0; i < 1000; ++i) {
            array1[i] = rand() % 1000;
            cout << array1[i] << " , ";
        }

        if (!is_sorted(array1.begin(), array1.end())) {
            //sort using inbuilt sort function
            sort(array1.begin(), array1.end());
        }

        cout << "\n\n";

        for (int j = 0; j < 1000; ++j) {
            cout << array1[j] << " , ";
        }

        int elementfromtheArray = array1[rand() % 1000];

        cout << "\n\nRandom element picked is " << elementfromtheArray << endl;

      //implementing binary search

        float t1 = clock();
        if (binarysearch(array1.begin(), elementfromtheArray)) {
            cout << "\n Found from binary search!" << endl;
        }
        float t2 = clock();

        cout << "Time of Binary Search is " << t2 - t1 << endl;

        //the main function part for ternary search

        int left = 1000 / 3;
        int right = left * 2;

        float t3 = clock();
        if (ternarysearch(array1.begin(), 1000, left, right, elementfromtheArray) != -1) {
            cout << "\nFound from ternary search !!" << endl;
        }
        float t4 = clock();

        cout << " Time of ternary search is " << t4 - t3 << endl;


       //the main function part of the fourway search
        int low = 0;
        int high = 999;

        float t5 = clock();
        if (fourwaysearch(array1.begin(), 1000, elementfromtheArray, low, high) != 1) {
            cout << "\n Found from fourway search !!" << endl;
        }
        float t6 = clock();

        cout << "Time of fourway search is " << t6 - t5 << endl;

        n--;

        cout << "\n\n";
    }
}
