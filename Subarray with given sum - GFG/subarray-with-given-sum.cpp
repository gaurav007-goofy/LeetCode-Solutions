//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        
        int curr_sum = 0;
        int i=0;
        int j=0;
        
        vector<int>res;
        while(j<n)
        {
            curr_sum += arr[j];
            
            while(i<j&& curr_sum>s)
            {
                curr_sum -= arr[i];
                i++;
            }
            if(curr_sum == s)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            
            j++;
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends