#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main (){  int i=0,j=0,m[12];
              float as1,as2,as3,as4,as5,c1,c2,c3;         
            float a[12],ansx,ansy,ansz;
               m[0]=1;  m[1]=1;  m[2]=1;  m[3]=1;
			   m[4]=2;  m[5]=2 ; m[6]=2;  m[7]=2;
			   m[8]=3;  m[9]=3 ; m[10]=3; m[11]=4;
			char x[12];
           x[0]='a';  x[1]='b';  x[2]='c';  x[3]='d'; 
           x[4]='a';  x[5]='b';  x[6]='c';  x[7]='d';
           x[8]='a';  x[9]='b';  x[10]='c'; x[11]='d';
             printf("a1.x+b1.y+c1.z=d1\na2.x+b2.y+c2.z=d2\na3.x+b3.y+c3.z=d3\n");
             printf("enter equation coefficient and constant one by one\n");
             fflush(stdin);
     for(i=0;i<12;i++){
	        printf("enter data for %c%d:  ",x[i],m[i]); 
	         scanf("%f",&a[i]); } 
	  system("cls");
	  printf("\n(%f)x+(%f)y+(%f)z=(%f)\n(%f)x+(%f)y+(%f)z=(%f)\n(%f)x+(%f)y+(%f)z=(%f)\n"
		 ,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]);
		 
		 as1=(((a[3]*a[4])-(a[7]*a[0]))*((a[5]*a[8])-(a[9]*a[4])));  
		 as2=(((a[7]*a[8])-(a[11]*a[4]))*((a[1]*a[4])-(a[5]*a[0])));  
		 as3=(((a[2]*a[4])-(a[6]*a[0]))*((a[5]*a[8])-(a[9]*a[4])));  
		 as4=(((a[6]*a[8])-(a[10]*a[4]))*((a[1]*a[4])-(a[5]*a[0]))); 
		 ansz= ((as1-as2)/(as3-as4));
		 as5= (((a[7]*a[8])-(a[11]*a[4]))- ((a[6]*a[8])-(a[10]*a[4])*ansz));
		 ansy=((as5)/((a[5]*a[8])-(a[9]*a[4])));
		 ansx= (((a[3])-(a[1]*ansy)-(a[2]*ansz))/(a[0]));
		 printf("x is %f\n",ansx);
		  printf("y is %f\n",ansy);
		   printf("z is %f\n",ansz);
		  c1 = ((a[0]*ansx)+(a[1]*ansy)+(a[2]*ansz));
		  c2 = ((a[4]*ansx)+(a[5]*ansy)+(a[6]*ansz));
		  c3 = ((a[8]*ansx)+(a[9]*ansy)+(a[10]*ansz));	
		  printf("\nc1 == %f",c1);
		  printf("\nc2 == %f",c2);	
		  printf("\nc3 == %f",c3);		 
    
}
	
	                           
             
