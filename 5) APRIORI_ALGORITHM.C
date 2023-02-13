#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max(int a,int b){
	return a > b ? a : b ;
}

int main(){
	int n ;
	printf("ENTER NUMBER OF ID'S\n") ;
	scanf("%d",&n) ;
	int t ;
	printf("ENTER NUMBER OF TRANSACTIONS\n") ;
	scanf("%d",&t) ;
	int g[t] , a[t][n] ;
	for(int i=0 ; i<t ; i++){
		scanf("%d",&g[i]) ;
		for(int j=0 ; j<g[i] ; j++){
			scanf("%d",&a[i][j]) ;
		}
	}

	float min_supp ;
	printf("ENTER MINIMUM SUPPORT\n") ;
	scanf("%f",&min_supp) ;

	// FOR C1 
	int c1[n+1] = {0}  ;
	for(int i=0 ; i<t ; i++)
		for(int j=0 ; j<g[i] ; j++)
			c1[a[i][j]]++ ;

	printf("C1 \n") ;	
	for(int i=1 ; i<=n ; i++)
		printf("%d - %d\n",i,c1[i]) ;

	int maxi = 0 ;
	for(int i=1 ; i<=n ; i++) maxi = max(maxi , c1[i]) ;

	// CHECKING FOR THE FREQUENCIES IF THERE ARE ANY LESS THAN MIN SUPPORT
	// for(int i=1 ; i<=n ; i++){
		// double k = c1[i]/(double)maxi ;
		// if(k < min_supp) c1[i] = -1 ;
	// }

	// ASSUMING MINIMUM SUPPORT TO BE 2 
	min_supp = 2 ;

	// FOR L1 
	int l1[n+1] = {0} ;
	printf("L1 \n") ;
	for(int i=1 ; i<=n ; i++){
		if(c1[i] >= min_supp){
			l1[i] = c1[i] ;
			printf("%d - %d\n",i,l1[i]) ;
		}
		else l1[i] = -1 ;
	}

	// FOR C2
	int c2[n+1][n+1] , l2[n+1][n+1] ;
	for(int i=0 ; i<=n ; i++)
		for(int j=0 ; j<=n ; j++)
			c2[i][j] = -1 ; 

	for(int i=1 ; i<=n ; i++){
		if(l1[i] == -1) continue ;
		for(int j=i+1 ; j<=n ; j++){
			if(l1[j] == -1) continue ;
			int cnt = 0 ;
			for(int k=0 ; k<t ; k++){
				int f=0 ; 
				for(int p=0 ; p<g[k] ; p++){
					if(a[k][p] == i) f++ ;
					if(a[k][p] == j) f++ ;
				}
				if(f >= 2) cnt++ ;
			}
			c2[i][j] = cnt ;
		}
	}

	printf("C2\n") ;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++) printf("%d ",c2[i][j]) ;
		printf("\n") ;
	}

	printf("L2 \n") ;
	for(int i=1 ; i<=n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			if(c2[i][j] >= min_supp){
				l2[i][j] = c2[i][j] ;
				printf("%d,%d - %d\n",i,j,l2[i][j]) ;
			}
			else l2[i][j] = -1 ;
		}
	}

	printf("L3 \n") ;
	int total = 0 ;
	for(int i=1 ; i<=n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			for(int k=j+1 ; k<=n ; k++){
				if(l2[i][j] < min_supp || l2[i][k] < min_supp || l2[j][k] < min_supp) 
					continue ;
				int cnt = 0 ;
				for(int p=0 ; p<t ; p++){
					int f = 0 ;
					for(int q=0 ; q<g[p] ; q++){
						if(a[p][q] == i) f++ ;
						if(a[p][q] == j) f++ ;
						if(a[p][q] == k) f++ ;
					}
					if(f == 3) cnt++ ;
				}
				if(cnt >= min_supp){
					printf("%d,%d,%d - %d\n",i,j,k,cnt) ;
					total++ ;
				}
			}
		}
	}
	printf("THERE ARE TOTAL OF %d FREQUENT ITEM SETS\n",total) ;

	return 0 ;
}
