int maxLen(int arr[], int n)
{
    int sum=0,max_len=0;
    unordered_map<int,int> presum;
    for(int i=0;i<n;i++){
        sum+=arr[i]; //prefix sum
        if(sum==0)
            max_len=i+1;
        if(arr[i]==0 && max_len==0)
            max_len=1;
        if(presum.find(sum)!=presum.end()){ //checking if the same presum is present
            max_len=max(max_len,i-presum[sum]);
        }
        else
            presum.insert(pair<int,int>(sum,i)); //if not found then insert it in unordered_map
    }
    return max_len;
}
