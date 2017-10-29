//
// Created by chaitanya on 10/2/17.
//

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

bool binarysearch(int array[1000],int elementtobeSearched){
    //array a is sorted

    int first=0;
    int last=999;

    int middle = (first+last)/2;

    while(first<=last){
        if (array[middle]<elementtobeSearched){
            first=middle+1;
        }
        else if (array[middle]==elementtobeSearched){
            return true;
        }
        else{
            last = middle - 1;
        }

        middle = (first+last)/2;

        if (first>last)
            return false;
    }

}

int ternarysearch(int array[1000],int sizeofarray,int left,int right,int elementtobesearched){
    //array is sorted

    if (left<0 || right>sizeofarray-1 || left>right){
        return -1;
    }

    if (elementtobesearched == array[left]){
        return left;
    }

    if (elementtobesearched == array[right]){
        return right;
    }

    if (elementtobesearched < array[left]){
        return ternarysearch(array,sizeofarray,left-1,right,elementtobesearched);
    }
    else if(elementtobesearched > array[left] && elementtobesearched < array[right]){
        return ternarysearch(array,sizeofarray,left+1,right-1,elementtobesearched);
    }

    if (elementtobesearched>array[right]){
        return ternarysearch(array,sizeofarray,left,right+1,elementtobesearched);
    }

}

int fourwaysearch(int array[1000],int sizeofarray, int elementtobesearched,int low,int high){
    //array is sorted

    int one = (low+high)/4;
    int two = one*2;
    int three = one*3;

    if(low<0 || high>sizeofarray-1 || one>two || two>three || one>three){
        return -1;
    }

    if (elementtobesearched==array[low]){
        return low;
    }
    if (elementtobesearched==array[high]){
        return high;
    }

    if (elementtobesearched==one){
        return one;
    }

    if (elementtobesearched==two){
        return two;
    }

    if (elementtobesearched==three){
        return three;
    }

    if (elementtobesearched<array[one]){
        return fourwaysearch(array,sizeofarray,elementtobesearched,low,one-1);
    }

    if (elementtobesearched>one && elementtobesearched<two){
        return fourwaysearch(array,sizeofarray,elementtobesearched,one+1,two-1);
    }

    if (elementtobesearched>two && elementtobesearched<three){
        return fourwaysearch(array,sizeofarray,elementtobesearched,two+1,three-1);
    }

    if (elementtobesearched>three && elementtobesearched<high){
        return fourwaysearch(array,sizeofarray,elementtobesearched,three+1,high);
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
