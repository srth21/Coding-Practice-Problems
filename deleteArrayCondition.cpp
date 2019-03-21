#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

/*
Given an array arr[] and a number k. The task is to delete k elements which are smaller than next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted.

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer n, denoting the size of the array. Next line contains n space separated integers, followed by an integer k, denoting the number of elements to be deleted from the array.

Output:
For each test case, the output is the array arr[] after deleting the k elements from the array if possible, else print the left array as it is.

Constraints:
1<=T<=100
2<=n<=100
1<=k<=100

Example:
Input
4
3
3 100 1
1
5
20 10 25 30 40
2
5
23 45 11 77 18
3
2
2 5
2
Output
100 1
25 30 40
77 18
5

Explanation:
1. arr[0] < arr[1] means 3 is less than 100, so delete 3.
2. First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20 because 25 is moved next to it and it also starts following the condition.
3. We delete 23, 45 and 11 as they follow the condition arr[i] < arr[i+1].
4.  As after deleting 2, we are left with 5 only and hence 5 is the answer.

*/
void check(vector<int>a, int n, int k)
{
    //cout<<"here"<<endl;
    int i=0;
    bool canDelete=true;
    while(i!=k && canDelete)
    {
        vector<int>::iterator it;
        it=a.begin();
        bool stop=true;
        while(stop && it!=a.end())
        {
            int x=*it;
            vector<int>::iterator it1=next(it,1);
            if(it1!=a.end())
            {
                int y=*it1;
            
                if(x<y)
                { 
                //cout<<"deleting "<<x<<"due to "<<y<<endl;
                a.erase(it);
                i++;
                stop=false;
                }    
            }
            
            ++it;
        }
        if(it==a.end())
        {
          bool y=false;
          int h=1;
          vector<int>::iterator it2=a.begin();
          while(it2!=a.end())
          {
            vector<int>::iterator it3=next(it2,1);
            if(it3!=a.end() && *it2<*it3)
            {
              y=true;
            }
            ++it2;
          }
          if(!y)
          {
            canDelete=false;
          }
          else
          {
            it=a.begin();
          }
        }
        //cout<<"end of loop"<<endl;
    }
    for(int m=0;m<a.size();m++)
    {
        cout<<a[m]<<" ";
    }
    cout<<endl;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    vector <int> a;
      //cout<<"before"<<endl;
	    for(int i=0;i<n;i++)
	    {
        int x;
	      cin>>x;
        a.push_back(x);
	    }
      //cout<<"done reading"<<endl;
	    cin>>k;
	    check(a,n,k);
	}
	return 0;
}