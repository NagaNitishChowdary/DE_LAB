// 1)E) GIVE THE FIVE NUMBER SUMMARY OF DATA 
// FIVE NUMBER SUMMARY ( MIN NO , FIRST QUARTILE , MEDIAN , THIRD QUARTILE , MAX NO)

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
    double iqr = q3 - q1 ;
    printf("THE 5 NUMBER SUMMARY OF DATA IS :\n") ;
    printf("%d  %.2f  %.2f  %.2f  %d\n",arr[0],q1,iqr,q3,arr[n-1]) ;

    return 0 ;
}
