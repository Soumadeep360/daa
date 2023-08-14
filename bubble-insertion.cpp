#include <bits/stdc++.h>
using namespace std;

void bubble(int arr[], int n)
{
    int flag, temp;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << "the sorted arrray is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert(int arr[],int n){
    int temp,j;
    for (int i = 1; i < n; i++)
    {
        temp=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
     cout << "the sorted arrray is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}
int main()
{
    clock_t s,e,s1,e1;
    int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    int arr[n];
    int arr1[n];
    cout << "enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr1[i]=arr[i];
    }
    s=clock();
    bubble(arr, n);
    e=clock();
    
     cout<<"time taken for bubble is:"<<(double)(e-s)/CLOCKS_PER_SEC<<endl;

    s1=clock();
    insert(arr1,n);
    e1=clock();
    cout<<"time taken for insert is:"<<(double)(e1-s1)/CLOCKS_PER_SEC<<endl;
}