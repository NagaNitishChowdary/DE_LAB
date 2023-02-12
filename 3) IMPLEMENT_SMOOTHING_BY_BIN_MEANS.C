// 3) IMPLEMENT SMOOTHING BY BIN MEANS TO SMOOTH THE DATA 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ;
    printf("ENTER N VALUE \n",n) ;
    scanf("%d",&n) ;
    int arr[n] ;
    for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]) ;
    int binDepth ;
    printf("ENTER BIN DEPTH\n") ;
    scanf("%d",&binDepth) ;

    float ans[n] ;
    int d1 = n/binDepth , d2 = n%binDepth ;
    for(int i=0 ; i<n ; i+=binDepth){
        float binMean = 0 ;
        for(int j=i ; j<binDepth+i ; j++){
            binMean += arr[j] ;
        }
        binMean /= binDepth ;
        for(int j=i ; j<binDepth+i ; j++) ans[j] = binMean ;
    }

    if(d2 != 0){
        float extra = 0 ;
        for(int i=0,j=n-1 ; i<d2 ; i++,j--) extra += arr[j] ;
        extra /= binDepth ;
        for(int i=0,j=n-1 ; i<d2 ; i++,j--) ans[j] = extra ; 
    }

    for(int i=0 ; i<n ; i++) printf("%.2f ",ans[i]) ;

    return 0 ;
}
