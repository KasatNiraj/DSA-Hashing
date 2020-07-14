// return the maximum length of the subarray
// with equal 0s and 1s
// variation of largest subarray with 0 sum problem
int maxLen(int arr[], int n)
{
    int sum=0,max_len=0;
    unordered_map<int,int> presum;
    //replace all 0's in array by -1
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            arr[i]=-1;
    }
    //now find the length of largest subarray with 0 sum
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)
            max_len=i+1;
        if(presum.find(sum)!=presum.end())
            max_len=max(max_len,i-presum[sum]);
        else
            presum.insert(pair<int,int>(sum,i));
    }
    return max_len;
}
