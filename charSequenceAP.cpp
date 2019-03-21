#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Archana is very fond of strings. She likes to solve many questions related to strings. She comes across a problem which she is unable to solve. Help her to solve. The problem is as follows:-

Given is a string of length L. Her task is to find the longest string from the given string with characters arranged in descending order of their ASCII code and in arithmetic progression. She wants the common difference should be as low as possible(at least 1) and the characters of the string to be of higher ASCII value.  

Input:
The first line of input contains an integer T denoting the number of test cases. Each test contains a string s of length L.

Output:
For each test case print the longest string.

Constraints:
1<= T <= 100
3<= L <=1000
A<=s[i]<=Z
The string contains minimum three different characters.

Example:
Input:
2
ABCPQR
ADGJPRT
Output:
RQP
JGDA

Explanation:
Case 1:
Two strings of maximum length are possible- “CBA” and “RPQ”. But he wants the string to be of higher ASCII value therefore, the output is “RPQ”


*/
struct node
{
    int pos;
    int max;
    int i;
    node() {};
    node(int pos, int max, int i): pos(pos), max(max), i(i) {};
};
void check(string s)
{
    int **arr=new int*[13];
    for(int i=0;i<13;i++)
    {
        arr[i]=new int[s.size()];
        arr[i][0]=1;
        
    }
    for(int j=1;j<13;j++)
    {
        for(int i=1;i<s.size();i++)
        {
            if(int(s.at(i))-int(s.at(i-1))==j)
            {
                arr[j][i]=arr[j][i-1]+1;
            }
            else
            {
                arr[j][i]=1;
            }
        }    
    }
   
    queue<node> q;
    
    int mainMax=0;
    for(int i=1;i<13;i++)
    {
        int maxVal=-1;
        int maxPos=-1;
        int max=-1;
        for(int j=0;j<s.size();j++)
        {
            if(arr[i][j]>=max && (int)s.at(j)>maxVal)
            {
                max=arr[i][j];
                maxPos=j;
            }
        }
        //cout<<"for diff "<<i<<" max len :"<<max<<" from pos "<<maxPos<<endl;
        if(i==1)
        {
            q.push(node(maxPos,max,i));
        }
        else
        {
            node top=q.front();
            if(max>top.max)
            {
                while(!q.empty())
                {
                    q.pop();
                }
                q.push(node(maxPos,max,i));
            }
            if(max==top.max)
            {
                q.push(node(maxPos,max,i));
            }
        }
        
    }
    
    int maxPos=-1;
    int maxLen=-1;
    int diff=14;
    while(!q.empty())
    {
        node t=q.front();
        if(t.i<diff)
        {
            diff=t.i;
            maxPos=t.pos;
            maxLen=t.max;
        }
        q.pop();
    }
    
    for(int i=0;i<maxLen;i++)
    {
        cout<<s[maxPos-i];
    }
    cout<<endl;
    delete arr;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin>>s;
	    check(s);
	}
	return 0;
}