#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int  main(){
	char dept[11][10]={"sales","sales","sales","systems","systems","systems","systems","marketing","marketing","secretary","secretary"};
    char status[11][10]={"senior","junior","junior","junior","senior","junior","senior","senior","junior","senior","junior"};
    char age[11][10]={"31-35","26-30","31-35","21-25","31-35","26-30","41-45","36-40","31-35","46-50","26-30"};
    char salary[11][10]={"46-50","26-30","31-35","46-50","66-70","46-50","66-70","46-50","41-45","36-40","26-30"};
    int count[11]={30,40,40,20,5,3,3,10,4,4,6} ;

    float n = 0 ;
    for(int i=0 ; i<11 ; i++) n += count[i] ;

    float c1 = 0 , c2 = 0 ;
	for(int i=0 ; i<11 ; i++){
		if(strcmp(status[i],"senior") == 0) c1 += count[i] ;
		else c2 += count[i] ; 
		// printf("%s",status[i]) ;
	}
	// printf("%f %f",c1,c2) ;

	float p_c1 = c1/n ;
	float p_c2 = c2/n ;
	printf("PROBABILITIY THAT (STATUS == SENIOR) IS %f\n",p_c1) ;
	printf("PROBABILITIY THAT (STATUS == JUNIOR) IS %f\n",p_c2) ;

	float c_x11 = 0 , c_x21 = 0 , c_x31 = 0 , c_x12 = 0 , c_x22 = 0 , c_x32 = 0 ;
	for(int i=0 ; i<11 ; i++){
		if(strcmp(status[i],"senior") == 0){
			if(strcmp(dept[i],"systems") == 0) c_x11 += count[i] ;
			if(strcmp(age[i],"26-30") == 0) c_x21 += count[i] ;
			if(strcmp(salary[i],"46-50") == 0) c_x31 += count[i] ;
		}
		else{
			if(strcmp(dept[i],"systems") == 0) c_x12 += count[i] ;
			if(strcmp(age[i],"26-30") == 0) c_x22 += count[i] ;
			if(strcmp(salary[i],"46-50") == 0) c_x32 += count[i] ;
		}
	}

	float p_x11 = c_x11/c1 , p_x21 = c_x21/c1 , p_x31 = c_x31/c1 ;
	float p_x12 = c_x12/c2 , p_x22 = c_x22/c2 , p_x32 = c_x32/c2 ;

	// LAPLACE CORRECTION
	if(p_x11 == 0) p_x11 = (c_x11+1)/(c1+4) ; 
	if(p_x21 == 0) p_x21 = (c_x21+1)/(c1+4) ; 
	if(p_x31 == 0) p_x31 = (c_x31+1)/(c1+4) ; 

	if(p_x12 == 0) p_x12 = (c_x12+1)/(c2+4) ; 
	if(p_x22 == 0) p_x22 = (c_x22+1)/(c2+4) ; 
	if(p_x32 == 0) p_x32 = (c_x32+1)/(c2+4) ; 

	printf("P(dept=systems/status=senior) = %f\n",p_x11);
	printf("P(age=26-30/status=senior) = %f\n",p_x21);
	printf("P(salary=46-50/status=senior) = %f\n",p_x31);

	printf("P(x=systems/status=junior) = %f\n",p_x12);
	printf("P(age=26-30/status=junior) = %f\n",p_x22);
	printf("P(salary=46-50/status=junior) = %f\n\n",p_x32);

	float p_X_c1 = (p_x11)*(p_x21)*(p_x31) ;
	float p_X_c2 = (p_x12)*(p_x22)*(p_x32) ;

	printf("P(X/status=senior) = %f\n",p_X_c1);
	printf("P(X/status=junior) = %f\n\n",p_X_c2);

	float p_c1_X = p_X_c1 * p_c1,   p_c2_X = p_X_c2 * p_c2;

	printf("P(status=senior/X) = %f\n",p_c1_X);
	printf("P(status=junior/X) = %f\n\n",p_c2_X);

	if(p_c1_X > p_c2_X)
	printf("Given Data Tuple belongs to status = senior\n\n");
	else if(p_c1_X < p_c2_X)
	printf("Given Data Tuple belongs to status = junior\n\n"); 

	return 0 ;
}
