//QUESTION -3 Assignment-3 Eeshan Beohar
#include<stdio.h>

float lag_pol(int n, float x[n],float y[n],float p,float a)

{
    float s=1.0,t=0.0,k=0.0;
    int i,j,d=1;
        for(i=0; i<p; i++)
        {
            s=1;
            t=1;
            for(j=0; j<p; j++)
            {
                if(j!=i)
                {
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }
return k;}

float neville_poly(int n, float u[n], float v[n], float a){

float k,x1[2],y1[2],z1[n-1],z11[n-1],z2[2],z3[n-2],z5;
int i,j;
	   
     for (i=0;i<n-1;i++){
     	x1[0]=u[i];y1[0]=v[i];
     	x1[1]=u[i+1];y1[1]=v[i+1];
     	z1[i]=lag_pol(2,x1,y1,2,a);}
     	
	 z2[0]=u[0];z2[1]=u[2];
	 z11[0]=z1[0];z11[1]=z1[1];
	 
	 z3[0]=lag_pol(2,z2,z11,2,a);
	 z2[0] = u[1];z2[1] = u[3];
	 z11[0]=z1[1];z11[1]=z1[2];
	 
	 z3[1]= lag_pol(2,z2,z11,2,a);
	 z2[0] = u[0]; z2[1] = u[3];
	 
	 z5 = lag_pol(2,z2,z3,2,a);
	 
	printf("\nNeville's Polynomials for x =%f\n",a);
	printf("\nf(0)_1 = %f\tf(1)_1 = %f\tf(2)_1 = %f\nf(0)_2 = %f\tf(1)_2 = %f\nf(0)_3 = %f\n",z1[0],z1[1],z1[2],z3[0],z3[1],z5);
	printf("P(1) = %f\n",lag_pol(4,u,v,2,a));
	printf("P(2) = %f\n",lag_pol(4,u,v,3,a));
	printf("P(3) = %f\n",lag_pol(4,u,v,4,a));
	//Conditions for Lag Pol and Nevillie pol equivalence
	if (lag_pol(4,u,v,2,a) == z1[0]){
		printf("f(0)_1 = P(1)\n");}
		
	if (lag_pol(4,u,v,3,a) == z3[0]){
		printf("f(0)_2 = P(2)\n");}
		
	if (lag_pol(4,u,v,4,a) == z5){
		printf("f(0)_3 = P(3)\n");}
}
 
 main(){
 	int i;
 	float a,x1[4],y1[4];
	x1[0] = 1;x1[1] = 4;x1[2]=5;x1[3] = 10;
	y1[0] = 1;y1[1] = 0.25;y1[2]=0.2; y1[3] = 0.1;
   
    for (a=0;a<=10;a+=0.1){
    	neville_poly(4,x1,y1,a);
	}}
	
/* Sample Output
Neville's Polynomials for x =8.999998

f(0)_1 = -1.000000      f(1)_1 = 0.000000       f(2)_1 = 0.120000
f(0)_2 = 0.999999       f(1)_2 = 0.100000
f(0)_3 = 0.200000
P(1) = -1.000000
P(2) = 0.999999
P(3) = 0.200000
f(0)_1 = P(1)
f(0)_2 = P(2)
f(0)_3 = P(3) */


