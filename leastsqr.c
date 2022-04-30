// NOTE: index: 0->N

#include<stdio.h>
#include<math.h>

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



//poly of degree n, (n+1) coefficients a[n+1]
float Pn (int n,float x,float a[n+1]){
	int i;
	float S=0;
	for (i=0;i<=n;i++){
		S+= pow(x,i)*a[i];
	}
	return S;
}

//weight = sum(1/sig[i]) for m x-values
float weight (int m,float sig[m]){
	float w; int i;	
	for(i=0;i<=m-1;i++)
    {
    	w+=1/pow(sig[i],2);}
   	return w;
}

// x_bar/y_bar of degree n of m x/y-values x/y[m]
float x_bar (int n,int m, float x[m]){//, float sig[m]){
	int i;
	float x_bar = 0;
	for (i=0;i<=m-1;i++){
		x_bar+= pow(x[i],n);///pow(sig[i],2);

	}
	return (x_bar);///weight(m,sig));
}

// xy_bar of degree n (xi^n) of m x-values x[m]
float xy_bar (int n,int m, float x[m],float y[m]){//,float sig[m]){
	int i;
	float xy_bar = 0;
	for (i=0;i<=m-1;i++){
		xy_bar+= (pow(x[i],n)*y[i]);///pow(sig[i],2);
	}
	return (xy_bar);///weight(m,sig));
}

main()
{
	/*float x[10] = {1,2,3,4,5,6,7,8,9,10},y[10] = {2.8,3.6,2.8,3.5,4.2,5.1,6.6,8.6,10.8,14.2},sig[10] ={0.3,0.5,0.55,0.6,0.65,0.7,0.75,0.9,1.1,1.3};
	printf("%f\n",x_bar(0,10,x,sig));
	printf("%f",pow(2,0));
 */
     int /*degree of fit Poly*/ p,/*# data points*/m,/*dummy deg*/deg=0,i,j;
    //float x[5] = {0,0.25,0.50,0.75,1},y[5] = {1,1.284,1.6487,2.1170,2.7183};//sig[10] ={1,1,1,1,1};
   	
   	// INIT Data X and Y vectors
   	
   	//m=5;
   	//float x[5] = {1,1.25,1.50,1.75,2},y[5] = {5.10,5.79,6.53,7.45,8.46};
   	
   	m=5;
   	float x[5]={-1,-0.5,0,0.5,1}, y[5]={-1,-0.4375,0,0.4375,1},w;
   	
   	
   	//For y = b*exp(a*x), y->logy, b-->logb s.t. logy = logb + ax
   	//For y = b*x^a, y->logy, b-->logb, x^a -> a*logx or x-->logx, s.t. logy = logb + a*logx
   	
   	// INIT y->logy
   	/*for (i=0;i<m;i++){
   		y[i] = log(y[i]);
	   }
	
	// INIT x->logx
   	for (i=0;i<m;i++){
   		x[i] = log(x[i]);
	   }*/
	
	
	// INIT Normal Matrix: A(n)(n+1)
	
	p=3;
	
	/*Dim. Normal Matrix*/int n=p+1;
	float A[n][n+1],/*Poly. Coeff. 0 to p dim(p+1=n)*/a[n];
	
    for (i=0;i<=n-1;i++){
    	for (j=0;j<=n;j++){
    		
    			if (j!=n){
    			A[i][j] = x_bar(j+deg,m,x);
				}//,sig);
				
				if (j==n){
					A[i][j] = xy_bar(i,m,x,y);
				}//,sig);		
		} 
		deg+=1;
	}
	
	for (i=0;i<=n-1;i++){
		for (j=0;j<=n;j++){
			printf("%f\t",A[i][j]);}
			printf("\n");
		
	}
	
    gauss(n,n+1,A,a);
    
    for (i=0;i<=n-1;i++){
    	printf("%f\t",a[i]);
    }
    
    //Poly coeff for y = b exp(ax)
    //printf("\n%f\t%f\n",exp(a[0]),a[1]);
    
    //Poly coeff for y = b*x^a
    //printf("\n%f\t%f\n",exp(a[0]),a[1]);
    
    	FILE*fp2;
    	fp2 = fopen("CubicPol.txt","w");
    
    for(w=-1;w<=1;w+=0.1){
	fprintf(fp2,"%.2f\t%.2f\n",w,Pn(3,w,a));
	}
}

