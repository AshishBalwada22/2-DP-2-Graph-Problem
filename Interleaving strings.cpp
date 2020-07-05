int Solution::isInterleave(string A, string B, string C) {
    //no. of character present in A and B should be equal and in order of c
    int m=A.length();
    int n=B.length();
    int s=C.length();
    if(m+n!=s) return 0;
    int i=0,j=0;
    for(int k=0;k<s;k++)
    {
        if(C[k]==A[i]) i++;
        if(C[k]==B[j]) j++;
    }
    if(i==m&&j==n) return 1;
    else return 0;
}

