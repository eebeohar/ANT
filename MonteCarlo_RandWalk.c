//Assignment-2 On MC Eeshan Beohar 19036762014

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return ((0.375)*(1+x*x));
}

void rand_gen021(int n,float Rand1[n]){
	int i;
	float r;
	/*FILE*fp=NULL;
	fp = fopen("RandNum021.txt","w");*/
 
			for( i = 0 ; i < n ; i++ ) {
   				Rand1[i]=((float)rand()/(float)RAND_MAX);//RAND_MAX;
   				//fprintf(fp,"%f\n",Rand1[i]);
   			}		
}

//QUESTION 1
void rand_gena2b(int n,float y[n],float a, float b){

	//float y[n];
	rand_gen021(n,y);
	//FILE*fp=NULL;
	//fp = fopen("RandNuma2b.txt","w");
	//int a1=0,b1=10;
	int i;
	for (i=0;i<n;i++){
		y[i] = a + (b-a)*y[i];
		//fprintf(fp,"%f\n",y[i]);
	}
	//FreqDist021(10000,y);
	//printf("%d",RAND_MAX);
}

float dN (int n,float h){
	int i;
	float X[n+1];
	

	rand_gen021(n,X);
	X[0] = 0.0;
	for (i=1;i<=n;i++){
		if(X[i]<0.5){
			X[i] = X[i-1]-h;
		}
		else{
				X[i] = X[i-1]+h;
		}		
	}
	return X[n];
}

void TwodRdmWlk (int n,float h, float k,float X[n+1],float Y[n+1]){
	int i;
	//float X[n+1],Y[n+1];
	rand_gen021(n,X);
	X[0] = 0.0;Y[0] = 0.0;
	for (i=1;i<=n;i++){
	
		if(X[i]<=0.25){
			X[i] = X[i-1]-h;
			Y[i] = Y[i-1];
		}
		
		if(X[i]>0.25){
			
			if(X[i]<0.5){
			X[i] = X[i-1]+h;
			Y[i] = Y[i-1];
			}
		}
		
		if(X[i]>0.5){
			
			if(X[i]<0.75){
			Y[i] = Y[i-1]+k;
			X[i] = X[i-1];
			}
			
			else{
			Y[i] = Y[i-1]-k;
			X[i] = X[i-1];
			}			
		}	
		//printf("%d\t%.2f\t%.2f\n",i,X[i],Y[i]);
	}
	//printf("%.2f\t%.2f\n",X[n],Y[n]);
}


main(){

//QUESTION 3

float a,b;
int i, n = 10000; a = -1.0; b = 1.0;
float x[n],y[n];
rand_gena2b(n,x,a,b);

a = 0.0; b = 0.75;
rand_gena2b(n,y,a,b);


FILE*fp=NULL;
fp = fopen("freq_x.txt","w");

for (i=0;i<n;i++){
	if (y[i]<f(x[i])){
	fprintf(fp,"%f\n",x[i]);}
	}


//Random Walk (a)
int n = 1000; int i;float h;
h = 1.0;
float X[n+1];
FILE*fp=NULL;
fp = fopen("1dRdmWalk.txt","w");

rand_gen021(n,X);
X[0] = 0.0;
for (i=1;i<=n;i++){
	if(X[i]<0.5){
		X[i] = X[i-1]-h;
	}
	else{
			X[i] = X[i-1]+h;
	}
	fprintf(fp,"%d\t%f\n",i,X[i]);
}
printf("Acual Distance Travelled d(N) = %.2f\n",X[n]-X[0]);
/*Output: Acual Distance Travelled d(N) = 36.00 */ 

//problem b
int n = 1000; int i;float h;
h = 1.0;
float X[n+1];
FILE*fp=NULL;
fp = fopen("1dRdmWalk.txt","w");

rand_gen021(n,X);
X[0] = 0.0;
for (i=1;i<=n;i++){
	if(X[i]<0.5){
		X[i] = X[i-1]-h;
	}
	else{
			X[i] = X[i-1]+h;
	}
	fprintf(fp,"%d\t%f\n",i,X[i]);
}
//printf("Acual Distance Travelled d(N) = %.2f\n",X[n]-X[0]);

int n;float h=1.0;
FILE*fp;
fp = fopen("d(N).txt","w");
for (n=10;n<=10000;n++){
	fprintf(fp,"%d\t%.2f\n",n,dN(n,h));
}
int n;float h=1.0;
FILE*fp;
fp = fopen("d2(N).txt","w");

for (n=10;n<=10000;n++){
	fprintf(fp,"%d\t%.2f\n",n,pow(dN(n,h),2));
}

int n;int i;float H[5]={0.1,1.0,2.0,10.0,50.0};

FILE*fp;
fp = fopen("d(N)h.txt","w");

	for (n=10;n<=10000;n++){
		fprintf(fp,"%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",n,dN(n,H[0]),dN(n,H[1]),dN(n,H[2]),dN(n,H[3]),dN(n,H[4]));
	}

int n;int i;float H[5]={0.1,1.0,2.0,10.0,50.0};

FILE*fp;
fp = fopen("d2(N)h.txt","w");

	for (n=10;n<=10000;n++){
		fprintf(fp,"%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",n,pow(dN(n,H[0]),2),pow(dN(n,H[1]),2),pow(dN(n,H[2]),2),pow(dN(n,H[3]),2),pow(dN(n,H[4]),2);
	}


int n=100,i,N;float h=1.0,dNavg=0.0;
FILE*fp;
fp = fopen("d(N)avg.txt","w");
for (N=10;N<=10000;N++){
	for (i=1;i<=n;i++){
		dNavg+=dN(N,h);
	}
	fprintf(fp,"%d\t%.2f\n",N,dNavg/n);
}

int n;float h=1.0;
FILE*fp;
fp = fopen("d2(N).txt","w");

for (n=10;n<=10000;n++){
	fprintf(fp,"%d\t%.2f\n",n,pow(dN(n,h),2));
}

int n=100,i,N;float h=1.0,dNavg=0.0,d2Navg=0.0,sig=0.0;
FILE*fp;
fp = fopen("d(N)avg_with_sig.txt","w");
for (N=10;N<=10000;N++){
	for (i=1;i<=n;i++){
		dNavg+=dN(N,h);
		d2Navg+= pow(dN(N,h),2);
	}
	dNavg = dNavg/n; d2Navg = d2Navg/n;
	sig= sqrt(d2Navg-pow(dNavg,2));
	fprintf(fp,"%d\t%.2f\t%.2f\n",N,dNavg,sig);
}

//2d Random Walk

int n = 1000; int i;float h,k;
h = 1.0; k = 1.0;
float X[n+1],Y[n+1];
FILE*fp;
fp = fopen("2dRdmWalk.txt","w");
rand_gen021(n,X);
X[0] = 0.0;Y[0] = 0.0;
for (i=1;i<=n;i++){
	
	if(X[i]<=0.25){
		X[i] = X[i-1]-h;
		Y[i] = Y[i-1];
	}
	
	if(X[i]>0.25){
		
		if(X[i]<0.5){
		X[i] = X[i-1]+h;
		Y[i] = Y[i-1];
		}
	}
	
	if(X[i]>0.5){
		
		if(X[i]<0.75){
		Y[i] = Y[i-1]+k;
		X[i] = X[i-1];
		}
		
		else{
		Y[i] = Y[i-1]-k;
		X[i] = X[i-1];
		}			
	}
	
	
	fprintf(fp,"%d\t%.2f\t%.2f\n",i,X[i],Y[i]);
}

int n;float h=1.0, k=1.0,total,dr;
FILE*fp;
fp = fopen("2dNvsN.txt","w");

for (n=10;n<=10000;n++){
	float X[n+1],Y[n+1];
	TwodRdmWlk(n,h,k,X,Y);
	total = X[n] + Y[n];
	dr = sqrt(X[n]*X[n] + Y[n]*Y[n]);
	//printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",n,X[n],Y[n],total,dr,dr*dr);
	fprintf(fp,"%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",n,X[n],Y[n],total,dr,dr*dr);	
}

int n=100,N,i;float h=0.1, k=0.1,total=0.0,dr=0.0,d2r=0.0,sig,xn,yn;
FILE*fp;
fp = fopen("2dNvsN.txt","w");

for (N=10;N<=100;N++){
	float X[N+1],Y[N+1];
	for (i=1;i<=n;i++){
		
		TwodRdmWlk(N,h,k,X,Y);
		xn+= X[N];yn+= Y[N];
		total+= X[N] + Y[N];
		dr+= sqrt(X[N]*X[N] + Y[N]*Y[N]);
		d2r+= X[N]*X[N] + Y[N]*Y[N];
	//printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",n,X[n],Y[n],total,dr,dr*dr);
	}
	xn=xn/n;yn=yn/n;total=total/n;dr=dr/n;d2r=d2r/n;
	sig = sqrt(d2r-pow(dr,2));
	fprintf(fp,"%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",N,xn,yn,total,dr,d2r,sig);	
}

	return 0;
}
