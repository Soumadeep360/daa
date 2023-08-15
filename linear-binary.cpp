#include<bits/stdc++.h>
using namespace std;

void linear(vector<int>&a,int key){
   cout<<"using Linear Search: "<<endl;
   int f=0;
    for(int i=0;i<a.size();i++)
    {
        if(key==a[i])
        {
            cout<<"Found at index: "<<i<<endl;
            f=1;
            break;
        }
    }
    if(f==0)
    cout<<"Key not found!"<<endl;
}
void binary(vector<int>&a,int key){

     cout<<"using binary Search: "<<endl;
     sort(a.begin(),a.end());
     int low=0,high=a.size()-1;
     int f=0;
     while(low<=high)
     {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            f=1;
            cout<<"Found at index: "<<mid<<endl;
            break;
        }
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
     }
     if(f==0)
        cout<<"Not Found!"<<endl;

}
int main(){
    int n;
    cout<<"enter the number of elements: "<<endl;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        a.push_back(el);
    }
    int key;
    cout<<"enter the key: "<<endl;
    cin>>key;

    clock_t s,e,s1,e1;
     s=clock();
    linear(a,key);
    e=clock();
     cout<<"time taken for linear is:"<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
    s1=clock();
    binary(a,key);
    e1=clock();
    cout<<"time taken for binary is:"<<(double)(e-s)/CLOCKS_PER_SEC<<endl;
}