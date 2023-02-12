// 1)D) FIND THE FIRST QUARTILE AND THIRD QUARTILE OF DATA 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    printf("ENTER NO OF VALUES\n") ;
    int n ;
    scanf("%d" , &n) ;
    printf("enter %d values\n",n) ;
    int i , arr[n] ;
    for(i=0 ; i<n ; i++) scanf("%d",&arr[i]) ;  

    double q1 = arr[(n+1)/4] ;
    double q3 = arr[3*(n+1)/4] ;
    printf("%.2f %.2f \n",q1,q3) ;
    // INTER QUARTILE RANGE (WHICH IS ALSO MEDIAN)
    printf("IQR IS : %.2f\n",q3-q1) ;

    return 0 ;
}
