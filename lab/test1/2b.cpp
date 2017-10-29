
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

int waysearch3(int arr[1000],int sizeofarray,int left,int right,int searchelement){

    if (left<0 || right>SIZE-1 || left>right){
        return -1;
    }

    if (searchelement == arr[left]){
        return left;
    }

    if (searchelement == arr[right]){
        return right;
    }

    if (searchelement < arr[left]){
        return waysearch3(array,sizeofarray,left-1,right,searchelement);
    }
    else if(searchelement > arr[left] && searchelement < arr[right]){
        return waysearch3(arr,SIZE,left+1,right-1,searchelement);
    }

    if (searchelement>arr[right]){
        return waysearch3(array,SIZE,left,right+1,searchelement);
    }

}

int fourwaysearch(int array[1000],int sizeofarray, int searchelement,int small,int big){
    //array is sorted

    int one = (small+big)/4;
    int two = one*2;
    int three = one*3;

    if(small<0 || big>SIZE-1 || one>two || two>three || one>three){
        return -1;
    }

    if (searchelement==arr[small]){
        return small;
    }
    if (searchelement==arr[big]){
        return big;
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
        return waysearch4(array,SIZE,searchelement,low,one-1);
    }

    if (searchelement>one && searchelement<two){
        return waysearch4(array,SIZE,searchelement,one+1,two-1);
    }

    if (searchelement>two && searchelement<three){
        return waysearch4(array,SIZE,searchelement,two+1,three-1);
    }

    if (searchelement>three && searchelement<big){
        return waysearch4(array,SIZE,searchelement,three+1,big);
    }

}

int main(){

int n=80;

    while(n>0) {
        array<int, 1000> arr;

        time_t t;
        srand((unsigned) time(&t));

        for (int i = 0; i < 1000; ++i) {
            arr[i] = rand() % 1000;
            cout << arr[i] << " , ";
        }

        if (!is_sorted(arr.begin(), arr.end())) {
            //sort using inbuilt sort function
            sort(arr.begin(), arr.end());
        }

        cout << "\n\n";

        for (int j = 0; j < 1000; ++j) {
            cout << arr[j] << " , ";
        }

        int ele = arr[rand() % 1000];

        cout << "\n\nThe element picked is " << ele << endl;

        float t1 = clock();
        if (binarysearch(arr.begin(), ele)) {
            cout << "\n Found from 2waysearch" << endl;
        }
        float t2 = clock();

        cout << "Time of 2waySearch is " << t2 - t1 << endl;

        

        int left = 1000 / 3;
        int right = left * 2;

        int t3 = clock();
        if (waysearch3(arr.begin(), 1000, left, right, ele) != -1) {
            cout << "\nFound from 3waysearch " << endl;
        }
        int t4 = clock();

        cout << " Time for 3waysearch is " << t4 - t3 << endl;


       //the main function part of the fourway search
        int small = 0;
        int big = 999;

        int t5 = clock();
        if (fourwaysearch(array1.begin(), 1000, ele, small, big) != 1) {
            cout << "\n Found from 4waysearch " << endl;
        }
        int t6 = clock();

        cout << "Time of 4waysearch is " << t6 - t5 << endl;

        n--;

        cout << "\n\n";
    }
}
