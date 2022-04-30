//Linear Equations Assignment-4 Eeshan Beohar 

#include<stdio.h>
#include<math.h>


float chop(int dig, float a){
	return (floor(pow(10,dig)*a)/pow(10,dig));
}


float Round(int dig, float a){
	return (round(pow(10,dig)*a)/pow(10,dig));
}

void gauss(int m, int n, float a[m][n], float x[n-1]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                for(j=0;j<n;j++){                
                    float temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        for(k=i+1;k<m;k++){
            float  term=a[k][i]/a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
         
    }
    for(i=m-1;i>=0;i--){
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
             
}

void gauss_round(int m, int n, float a[m][n], float x[n-1]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                for(j=0;j<n;j++){                
                    float temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        for(k=i+1;k<m;k++){
            float  term=Round(3,a[k][i])/Round(3,a[i][i]);
            for(j=0;j<n;j++){
                3,a[k][j]=Round(3,a[k][j])-Round(3,term*a[i][j]);
            }
        }
         
    }
    for(i=m-1;i>=0;i--){
        x[i]=Round(3,a[i][n-1]);
        for(j=i+1;j<n-1;j++){
            x[i]=Round(3,x[i])-Round(3,a[i][j])*Round(3,x[j]);
        }
        x[i]=Round(3,x[i])/Round(3,a[i][i]);
    }
             
}

void gauss_chop(int m, int n, float a[m][n], float x[n-1]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                for(j=0;j<n;j++){                
                    float temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        for(k=i+1;k<m;k++){
            float  term=chop(3,a[k][i])/ chop(3,a[i][i]);
            for(j=0;j<n;j++){
                a[k][j]=chop(3,a[k][j])-chop(3,term*a[i][j]);
            }
        }
         
    }
    for(i=m-1;i>=0;i--){
        x[i]=chop(3,a[i][n-1]);
        for(j=i+1;j<n-1;j++){
            x[i]=chop(3,x[i])-chop(3,a[i][j])*chop(3,x[j]);
        }
        x[i]=chop(3,x[i])/chop(3,a[i][i]);
    }
             
}

void gaussJordan(int m, int n, float a[m][n], float x[n-1]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            if(fabs(a[i][i])<fabs(a[k][i])){
                for(j=0;j<n;j++){                
                    float temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
	}	
        
        for(k=i+1;k<m;k++){
        	if (i!=k){
			
            float  term=a[k][i]/a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }}
         
    for(i=m-1;i>=0;i--){
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
             
}


void gaussinv(int n,float a[10][10]){
		float x[10], ratio;
		 int i,j,k;
		 for(i=0;i<n;i++)
		 {
			  for(j=0;j<n;j++)
			  {
				   if(i==j)
				   {
				    	a[i][j+n] = 1;
				   }
				   else
				   {
				    	a[i][j+n] = 0;
				   }
			  }
		 }
		 /* Applying Gauss Jordan Elimination */
		 for(i=0;i<n;i++)
		 {
			  if(a[i][i] == 0.0)
			  {
				   printf("Matrix is Non-Invertible");
				   return(0);
				   
			  }
			  
			  
			  for(j=0;j<n;j++)
			  {
				   if(i!=j)
				   {
					    ratio = a[j][i]/a[i][i];
					    for(k=1;k<=2*n;k++)
					    {
					     	a[j][k] = a[j][k] - ratio*a[i][k];
					    }
				   }
			  }
		 }
		 
		 for(i=0;i<n;i++)
		 {
			  for(j=n+1;j<2*n;j++)
			  {
			   	a[i][j] = a[i][j]/a[i][i];
			  }
		 }
		 
		 printf("\nInverse Matrix\n");
		 for(i=0;i<n;i++)
		 {
			  for(j=n+1;j<2*n;j++)
			  {
			   	printf("%0.4f\t",a[i][j]);
			  }
			  printf("\n");
		 }

}


//problem1

int main(){
    int n;
    float x[n];
    int i,j;
    float a1[4][5] = {{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
    float a2[5][6] = {{2,1,-1,1,-3,7},{1,0,2,-1,1,2},{0,-2,-1,1,-1,-5},{3,1,-4,0,5,6},{1,-1,-1,-1,1,3}};
    printf("\nProblem-1\n");
    
    n=4;
    gauss(n,n+1,a1,x);
    printf("\nsolution via Gauss Elimination:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
        
    n=5;
    gauss(n,n+1,a2,x);
    printf("\nsolution via Gauss Elimination:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
    
//problem 3
	float a3[2][3] = {{58.9,0.03,59.2},{-6.10,5.31,47.0}};
	float a4[3][4] = {{3.3330,15920,10.333,7953},{2.2220,16.710,9.6120,0.965},{-1.5611,5.1792,-1.6855,2.714}};
	printf("\nProblem-3\n");
// 1st matrix	
	n=2;
	
	gauss_chop(n,n+1,a3,x); 
    printf("\nsolution via 3-digit chopping:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
    
    
    gauss_round(n,n+1,a3,x);
    printf("\nsolution via 3-digit rounding:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
    
    
    gauss(n,n+1,a3,x);
    printf("\nsolution via Gauss Elimination:\n\n");
	for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
        
//2nd matrix
        
    n=3;
    gauss_chop(n,n+1,a4,x);
    printf("\nsolution via 3-digit chopping:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
        
    
     gauss_round(n,n+1,a4,x);
    printf("\nsolution via 3-digit rounding:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
    
    gauss(n,n+1,a4,x);
    printf("\nsolution via Gauss Elimination:\n\n");
	for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
    
//problem 5
	n=4;
	gaussJordan(n,n+1,a1,x);
	printf("\nProblem-5\n");

	printf("\nsolution via Gauss-Jordan:\n\n");
    for(i=0;i<n;i++){
        printf("x[%d]= %f\n",i+1,x[i]);}
	

//problem 6
		printf("\nProblem-6\n");
		float a[10][10],b[10][10];
		n = 3;
	    a[0][0] = 1;
	    a[0][1] = 2;
	    a[0][2] = -1;
	    a[1][0] = 2;
	    a[1][1] = 1;
	    a[1][2] = 0;
	    a[2][0] = -1;
	    a[2][1] = 1;
	    a[2][2] = 2;
    
		gaussinv(n,a);
		
		n=4;
		
	    b[0][0] = 1;
	    b[0][1] = 1;
	    b[0][2] = -1;
	    b[0][3] = 1;
	    
	    
	    b[1][0] = 1;
	    b[1][1] = 2;
	    b[1][2] = -4;
	    b[1][3] = -2;
	    
	    b[2][0] = 2;
	    b[2][1] = 1;
	    b[2][2] = 1;
		b[2][3] = 5;
		
		b[3][0] = -1;
	    b[3][1] = 0;
	    b[3][2] = -2;
		b[3][3] = -4;
		
		gaussinv(n,b);
}

/* OUTPUT:
Problem-1

solution via Gauss Elimination:

x[1]= -7.000001
x[2]= 3.000000
x[3]= 2.000000
x[4]= 2.000000

solution via Gauss Elimination:

x[1]= 1.918129
x[2]= 1.964912
x[3]= -0.988304
x[4]= -3.192982
x[5]= -1.134503

Problem-3

solution via 3-digit chopping:

x[1]= 1.000153
x[2]= 10.000188

solution via 3-digit rounding:

x[1]= 1.000000
x[2]= 10.000376

solution via Gauss Elimination:

x[1]= 1.000000
x[2]= 10.000376

solution via 3-digit chopping:

x[1]= 5.780912
x[2]= 0.500000
x[3]= -1.000197

solution via 3-digit rounding:

x[1]= 1.000000
x[2]= 0.500000
x[3]= -1.000197

solution via Gauss Elimination:

x[1]= 1.001050
x[2]= 0.500000
x[3]= -1.000197

Problem-5

solution via Gauss-Jordan:

x[1]= -7.000001
x[2]= 3.000000
x[3]= 2.000000
x[4]= 2.000000

Problem-6

Inverse Matrix
0.5556  -0.1111
-0.1111 0.2222
0.3333  0.3333
Matrix is Non-Invertible
--------------------------------
*/

