#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rand_gen021(int n,float Rand1[n]){
	int i;
 
			for( i = 0 ; i < n ; i++ ) {
   				Rand1[i]=((float)rand()/(float)RAND_MAX);//RAND_MAX = 3270
   			}		
}


void rand_gena2b(int n,float y[n],float a, float b){

	rand_gen021(n,y);

	int i;
	for (i=0;i<n;i++){
		y[i] = a + (b-a)*y[i];
	}
}


main(){
	int i,j,k,a,m,ri=1,ri1,n=0,Rand[1000];float Rand1[1000];
	int F[n],Num[n];
	FILE*fp=NULL;
	FILE*fp1=NULL;
	fp = fopen("Freq_Dist.txt","w");
	fp1 = fopen("Freq_Dist1.txt","w");
	
	a=5;m=37;
	do{
		fprintf(fp,"%d\n",ri);
		Rand[n] = ri;
		ri1 = fmod((a*ri),m);
		
		ri = ri1;
		n++;
	}
	while (n<1000);

rand_gen021(1000,Rand1);
for (i=0;i<n;i++){
	fprintf(fp1,"%f\n",Rand1[i]);
}


FILE*fp2=NULL;
FILE*fp3=NULL;
FILE*fp4=NULL;
fp2 = fopen("case1.txt","w");
fp3 = fopen("case2.txt","w");
fp4 = fopen("case3.txt","w");

//case1

n=10000;float r0210[n],ra025[n],rb025[n];

rand_gena2b(n,r0210,0.0,10.0);
for (i=0;i<n;i++){
	fprintf(fp2,"%f\n",r0210[i]);
}

//case2
rand_gena2b(n,ra025,0.0,5.0);
rand_gena2b(n,rb025,0.0,5.0);

for (i=0;i<n;i++){
	ra025[i]+=rb025[i];
	fprintf(fp3,"%f\n",ra025[i]);
}

//case3
float d[n],e[n];

for (j=0;j<=10;j++){
	rand_gen021(n,e);
	
	for (i=0;i<n;i++){
	d[i]+= e[i];
	fprintf(fp4,"%f\n",d[i]);}
}
	return 0;
}
