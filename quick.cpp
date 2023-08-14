//#include <bits/stdc++.h>
#include<iostream>
#include<time.h>
using namespace std;

int partition(int arr[], int lb,int up)
{   
   int pivot=arr[lb];
  int start=lb;
    int end=up;
   while (start<end)
   {
    while(arr[start]<=pivot)
        start++;
    while(arr[end]>pivot)
        end--;
    if(start<end)
    swap(arr[start],arr[end]);
   }
   swap(arr[lb],arr[end]);
   return end;

}
void quick(int arr[],int lb,int up){
    if(lb<up){
        int loc=partition(arr,lb,up);
        quick(arr,lb,loc-1);
        quick(arr,loc+1,up);
    }
}
int main()
{
    

    int ch;
    cout<<"enter 1 for user input and 2 for random generated input"<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:
    {
        clock_t s1,e1;
        int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    int arr[n];
  
    cout << "enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } 
     s1=clock();
    quick(arr,0,n-1);
    e1=clock();
    cout << "the sorted arrray is: ";
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"time taken for quick is:"<<(double)(e1-s1)/CLOCKS_PER_SEC;
        break;
    }
    case 2:
        {
        clock_t s2,e2;
        int arr1[1000];
        for(int i=0;i<1000;i++)
            {
                arr1[i]=(rand()%301);
            }
     s2=clock();
    quick(arr1,0,999);
    e2=clock();
    cout << "the sorted arrray is: ";
    
    for (int i = 0; i < 1000; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    double timeTaken=(double)(e2-s2)/(double)CLOCKS_PER_SEC;
    cout<<"time taken for quick is:"<<timeTaken;
        break;
        }
    default:
    cout<<"Invalid"<<endl;
        break;
    }
    // int n;
    // cout << "enter the size of array" << endl;
    // cin >> n;
    // int arr[n];
  
    // cout << "enter the elements of array" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }       

    // s1=clock();
    // quick(arr,0,n-1);
    // e1=clock();
    // cout << "the sorted arrray is: ";
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout<<"time taken for quick is:"<<(double)(e1-s1)/CLOCKS_PER_SEC;
}