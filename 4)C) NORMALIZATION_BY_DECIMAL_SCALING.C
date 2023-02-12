// 4)B) IMPLEMENT NORMALIZATION BY DECIMAL SCALING 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ;
    printf("ENTER N VALUE \n",n) ;
    scanf("%d",&n) ;
    float arr[n] ;
    for(int i=0 ; i<n ; i++) scanf("%f",&arr[i]) ;

    // STEP 1 --- FIND THE LARGEST ABSOLUTE VALUE IN THE DATA SET 
    float max_abs = 0 ;
    for(int i=0 ; i<n ; i++){
        if(fabs(arr[i]) > max_abs) max_abs = fabs(arr[i]) ;
    }

    // STEP 2 --- DETERMINE THE POWER 10 TO SCALE THE DATA BY 
    int power = floor(log10(max_abs)) ;
    double scale = pow(10,-power) ;

    // STEP 3 --- SCALE THE DATA 
    for(int i=0 ; i<n ; i++) arr[i] *= scale ;

    for(int i=0 ; i<n ; i++) printf("%.3f ",arr[i]) ; 
    printf("\n") ;

    return 0 ;
}
