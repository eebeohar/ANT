/*EESHAN BEOHAR Assignment-2 QUESTION-1 and QUESTION-2 */

#include<stdio.h>
#include<math.h>
#define pi (4.0*atan(1.0))

float f1(float x){
	return sin(pi*x);
}

float f2(float x){
	return log10((3*x)-1);
}

float f3(float x){
	return cbrt(x-1);
}

float f4(float x){
	return exp(2*x)-x;
}

float f5(float x){
	return pow(3,x);
}

float f6(float x){
	return sqrt(x);
}

float f7(float x){
	return (x-exp(-x));
}

//function for Lagrange Polynomials of degree p

float lag_pol(int n, float x[n],float y[n],float p,float a)

{
    float s=1.0,t=0.0,k=0.0;
    int i,j;
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

//function for Neville Polynomials of degree n=4

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

		return z5;}


//function for Neville Polynomials of degree n=5

float neville_poly5(int n, float u[n], float v[n], float a){

	float k,x1[2],y1[2],z1[n-1],z11[n-1],z2[2],z3[n-2],z4[n-3],z5[n-4],z6[n-5];
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
	 z2[0] = u[2];z2[1] = u[4];
	 z11[0]=z1[2];z11[1]=z1[3];
	 z3[2]= lag_pol(2,z2,z11,2,a);
	 
	 z2[0] = u[0]; z2[1] = u[3];
	 z4[0] = z3[0]; z4[1] = z3[1];
	 z5[0] = lag_pol(2,z2,z4,2,a);
	 z2[0] = u[1]; z2[1] = u[4];
	 z4[0] = z3[1]; z4[1] = z3[2];
	 z5[1] = lag_pol(2,z2,z4,2,a);
	 
	 z2[0] = u[0]; z2[1] = u[4];
	 z6[0] = lag_pol(2,z2,z5,2,a);
	 
	 return z6[0];}
	 
 
 main(){
//QUESTION-1

 	int n,i;
 	float a,x1[3],x2[7],y1[3],y2[7];
 	
 	FILE *fp = NULL;
	fp = fopen("prob_2.txt","w");
	x1[0] = 0.5;x1[1] = 5;x1[2] = 10;
	y1[0] = 2;y1[1] = 0.2;y1[2] = 0.1;
	
 	x2[0] = 0.5;x2[1] = 1;x2[2] = 2;x2[3] = 4;x2[4] = 5;x2[5] = 8;x2[6] = 10;
 	y2[0] = 2;y2[1] = 1;y2[2] = 0.5;y2[3] = 0.25;y2[4] = 0.2;y2[5] = 0.125;y2[6] = 0.1;
 	
 	for (a=0.5;a<=10;a+=0.1){
 	fprintf(fp,"%f\t%f\t%f\t%f\n",a,1/a,lag_pol(3,x1,y1,3,a),lag_pol(7,x2,y2,7,a));}
 	
// QUESTION-2: PROBLEM -1
 		
 		n = 3;
 		float u[n],v1[n],v2[n],v3[n],v4[n];
// Initializing X-vector

    	u[0] = 1;
    	u[1] = 1.25;
    	u[2] = 1.6;
     
// Initializing Y-vector        
        for(i=0; i<n; i++){
        	v1[i] = f1(u[i]);
        	v2[i] = f2(u[i]);
        	v3[i] = f3(u[i]);
        	v4[i] = f4(u[i]);
		}
		
    	a = 1.4; // Point of x at which the functions are to be approximated.
    	printf("\nPROBLEM-1\n");
		printf("(a)\n");
    	printf("\nP1(1.4) = %f",lag_pol(n,u,v1,2,a));
    	printf("\nP2(1.4) = %f\n",lag_pol(n,u,v1,3,a));
    	printf("\n(c)\n");
    	printf("\nP1(1.4) = %f",lag_pol(n,u,v2,2,a));
    	printf("\nP2(1.4) = %f\n",lag_pol(n,u,v2,3,a));
    	printf("\n(b)\n");
    	printf("\nP1(1.4) = %f",lag_pol(n,u,v3,2,a));
    	printf("\nP2(1.4) = %f\n",lag_pol(n,u,v3,3,a));
    	printf("\n(d)\n");
    	printf("\nP1(1.4) = %f",lag_pol(n,u,v4,2,a));
    	printf("\nP2(1.4) = %f\n",lag_pol(n,u,v4,3,a));  	
    	
// PROBLEM-2
    	
    	n=5;
    	printf("PROBLEM-2\n");
    	float v5[n],v6[n],u1[n],u2[n];
    	
// Initializing X-vector    	
    	u1[0] = -2;
    	u1[1] = -1;
    	u1[2] = 0;
    	u1[3] = 1;
    	u1[4] = 2;
// Initializing Y-vector   	
    	for(i=0; i<n; i++){
        	v5[i] = f5(u1[i]);}
    
    	printf("\nf(4)_0 for f(x)=3^x at x = 0.5: %f\n",neville_poly5(5,u1,v5,0.5));
// Initializing X-vector      	
    	u2[0] = 0;
    	u2[1] = 1;
    	u2[2] = 2;
    	u2[3] = 4;
    	u2[4] = 5;
    	
// Initializing Y-vector      	
    	for(i=0; i<n; i++){
        	v6[i] = f6(u2[i]);}
        	       	
		printf("\nf(4)_0 for f(x)= sqrt(x) at x = 3: %f\n",neville_poly5(5,u2,v6,3));
        	
// PROBLEM-3: Basically applying Neville's Algorithm
    	a = 1.5;
    	float P01, P12, P123,P012, x[2],y[2],P0123;
    	P01 = 1+a;P12 = 3*a -1;P123 = 4;
    	x[0] =0; y[0] = P01;x[1] = 2;y[1] = P12;
    	P012 = lag_pol(2,x,y,2,a);
    	x[0] =0; y[0] = P012;x[1] = 3;y[1] = P123;
    	P0123 = lag_pol(2,x,y,2,a);
    	printf("\nPROBLEM-3\n");
    	printf("P0123 = %f\n",P0123);
    	
// PROBLEM-3: applying Neville's Algorithm by inverting x-y vectors in the function call
			
		n =4; a =0;
		float u3[n],v7[n];
		u3[0] = 0.3;
    	u3[1] = 0.4;
    	u3[2] = 0.5;
    	u3[3] = 0.6;
    	
		for(i=0; i<n; i++){
        	v7[i] = f7(u3[i]);}
        printf("\nPROBLEM-4\n");
    	printf("p = %f",neville_poly(4,v7,u3,0)); }
    	
/*OUTPUT:
PROBLEM-1
(a)

P1(1.4) = -1.131371
P2(1.4) = -0.918228

(c)

P1(1.4) = 0.522314
P2(1.4) = 0.507122

(b)

P1(1.4) = 1.007937
P2(1.4) = 0.816945

(d)

P1(1.4) = 13.658556
P2(1.4) = 15.269764
PROBLEM-2

f(4)_0 for f(x)=3^x at x = 0.5: 1.708333

f(4)_0 for f(x)= sqrt(x) at x = 3: 1.690607

PROBLEM-3
P0123 = 3.625000

PROBLEM-4
p = 0.567142
--------------------------------*/    	

	
