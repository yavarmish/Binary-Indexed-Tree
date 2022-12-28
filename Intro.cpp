// https://www.youtube.com/watch?v=uSFzHCZ4E-8&ab_channel=StableSort
/*
  Given an array find sum of a given subarray for multiple queries where for each 
  query you we can compute a sub array sum or update a value in the array  
*/
// O(log n)
int getSum(vector<int>& b,int i) {
    i=i+1;
    int ans=0;
    while(i>0) {
        ans+=b[i];
        i-=i&-i;
    }
    return ans;
}
// O(log n)
void update(vector<int>& b,int i,int val) {
    i=i+1;
    while(i<b.size()) {
        b[i]+=val;
        i+=i&-i;
    }    
}
// O(n)
vector<int> bit(vector<int>& a,int n) {
    vector<int> b(n+1);
    for(int i=1;i<=n;i++)
        b[i]=a[i-1];
    for(int i=1;i<=n;i++) {
        int p=i+(i&-i);
        if(p<=n)
            b[p]=b[p]+b[i];    
    }
    return b;
}
int main() {
    vector<int> a={1,7,9,3,2,5,6};
    vector<int> b=bit(a,7);
    cout<<getSum(b,3)<<"\n"; // get sum of the subarray from index 0 to 3
    update(b,0,5);  // increments value at 0th index by 5
    cout<<getSum(b,3);
    return 0;
}
