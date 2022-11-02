//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        // code here
        int i=1;
        while(i<n-1)
        {
            if(i%2!=0)
            {
                if(arr[i-1]>arr[i])
                    swap(arr[i-1],arr[i]);
                if(arr[i+1]>arr[i])
                    swap(arr[i+1],arr[i]);
            }
            
            else
            {
                if(arr[i-1]<arr[i])
                    swap(arr[i-1],arr[i]);
                if(arr[i+1]<arr[i])
                    swap(arr[i+1],arr[i]);
            }
            i++;
            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends