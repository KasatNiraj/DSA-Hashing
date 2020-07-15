int longestSpan(int arr[],int brr[],int n){
    //substracting two arrays and converting the problem to
    //find the largest subarray with zero sum
    for(int i=0;i<n;i++)
        arr[i]-=brr[i];
    unordered_map<int,int> hash;
    int max_len=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)
            max_len=i+1;
        if(arr[i]==0 && max_len==0)
            max_len=1;
        if(hash.find(sum)!=hash.end())
            max_len=max(max_len,i-hash[sum]);
        else
            hash.insert(pair<int,int>(sum,i));
    }
    return max_len;
}
