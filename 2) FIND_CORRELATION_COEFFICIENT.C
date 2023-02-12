// 2) CALCULATE THE CORRELATION COEFFICIENT 
// CHECK ARE THESE VALUES ARE POSITIVELY OR NEGATIVELY CORRELATED

// FORMULA ==>
// r = cov(x,y)/(sigmax * sigmay)
// cov(x,y) = sigmaxy - meanx*meany 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ;
    printf("ENTER N VALUE \n",n) ;
    scanf("%d",&n) ;
    int arr1[n] ;
    for(int i=0 ; i<n ; i++) scanf("%d",&arr1[i]) ;
    float arr2[n] ;
    for(int i=0 ; i<n ; i++) scanf("%f",&arr2[i]) ;

    int sumx = 0 , squarex = 0 ;
    float sigmaxy = 0 , squarey = 0 , sumy = 0 ;
    for(int i=0 ; i<n ; i++){
        sumx += arr1[i] ,  sumy += arr2[i] ;
        sigmaxy += arr1[i]*arr2[i] ;
        squarex += (arr1[i]*arr1[i]) ;  squarey += (arr2[i]*arr2[i]) ;
    }
    float meanx = sumx/n ,  meany = sumy/n ;
    float covxy = sigmaxy/n - (meanx*meany) ;
    float sigmax = sqrt((squarex/n) - (meanx*meanx)) ;
    float sigmay = sqrt((squarey/n) - (meany*meany)) ;
    float r = covxy/(sigmax*sigmay) ;
    printf("CORRELATION COEFFICIENT : %f\n",r) ;
    if(n>0) printf("POSITIVELY CORRELATED\n") ;
    else if(n == 0) printf("ZERO CORRELATION\n") ;
    else printf("NEGATIVELY CORRELATED\n") ;

    return 0 ;
}
