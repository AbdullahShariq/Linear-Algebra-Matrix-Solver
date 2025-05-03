#include <stdio.h>
#include <math.h>
#include <string.h>

int i,j,l,m,n,p;
int cofactorF[3][3];
int cofactor(int mat[3][3]);
int minor(int matrix[3][3]);
int main()
{
	printf("-----------------Welcome to our program of Linear Algebra Matrix Solutions---------------------\n");
	printf("\n\n\n");
	char choice;
	int adjoint[10][10];
	float Det=0, inverse[10][10];
	while(choice!='e'){
	printf("Enter i for finding inverse of a matrix\nEnter t to transpose a matrix\nEnter c to find the cofactor matrix\nEnter m to find the minor matrix\nEnter g for using gauss jordan methods\nEnter e to exit program\n");
	scanf(" %c", &choice);
	switch(choice){
		case 'i':
			//This switch case helps us to find the inverse matrix of a user input matrix
			{
			printf("\nEnter rows and columns of your matrix to find its inverse\n");
			scanf("%d",&m);
			int mat[m][m];
			if(m==2){
				printf("Enter elements of 2x2 Matrix : \n");
				for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }//scanning elements of a 2x2 matrix.
    Det=(mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
    if(Det==0)
    {
        printf("Determinant = 0, Inverse of Matrix is not possible\n");
        printf("\n");
        break;
    }//Inverse of a matrix with determinant=0 is not possible.
    adjoint[0][0]=mat[1][1];
    adjoint[1][1]=mat[0][0];
    adjoint[0][1]=-mat[0][1];
    adjoint[1][0]=-mat[1][0];
    //Shifting places of 1st and 4th element and signs of 2nd and 3rd element.
    printf("Matrix is : \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    //printing the original matrix.
    printf("Inverse of Matrix is : \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            inverse[i][j]=(adjoint[i][j])/Det;
            //dividing each element by the determinant to find the inverse.
            printf("%.1f\t",inverse[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	break;
			}
			else if(m==3){
	int imat[3][3];
	float det=0;
	float adj[3][3],inv[3][3]; 
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter element %d,%d\n", i+1,j+1);
			scanf("%d", &imat[i][j]);
		}
	}
	det=det+((imat[0][0]*(imat[1][1]*imat[2][2])-(imat[1][2]*imat[2][1])))-((imat[0][1])*((imat[1][0]*imat[2][2])-(imat[1][2]*imat[2][0])))+((imat[0][2])*((imat[1][0]*imat[2][1])-(imat[1][1]*imat[2][0])));
    //this calculates the determinant of the 3x3 matrix.
    if(det==0)
    {
        printf("Determinant = 0, Inverse of Matrix is not possible\n");
        printf("\n");
        break;
    }//Inverse of a matrix with determinant=0 is not possible.
	cofactor(imat);
	// one step is to find the cofactor matrix of the unput matrix so we call the already defined function we used. 
for (i=0;i<3;i++){
      for (j=0;j<3;j++){
         adj[j][i] = cofactorF[i][j];
     }
 }
 //we then have to transpose the cofactor matrix in order to divide it by the determinant.
 for (i=0;i<3;i++){
      for (j=0;j<3;j++){
        inv[i][j]=(adj[i][j]/det);
     }
 }
 //dividing each element by the determinant to find the inverse matrix.
 printf("Inverse of the input matrix:\n");
 for (i=0;i<3;i++){
      for (j=0;j<3;j++){
    printf("%.3f\t", inv[i][j]);
     }
     printf("\n");
 }
 printf("\n");
			break;
		}
	}
		case 'c':
			//this case helps us to find the cofactor matrix of a user input matrix.
			{
	int cmat[3][3];
	printf("\nEnter 3x3 matrix to find the cofactor of an element\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		printf("Enter element %d,%d of matrix\n",i+1,j+1);
			scanf("%d", &cmat[i][j]);
		}
	}
	//scanning elements of a 3x3 matrix.
	cofactor(cmat);
	//calling the function.
	printf("The cofactor matrix of the input matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t", cofactorF[i][j]);
		}
			printf("\n");
	}
	printf("\n");
	break;
	}
	case 'm':
		//this case helps us to find the minor matrix of a matrix.
		{
			int cmat[3][3];
		printf("\nEnter 3x3 matrix to find the minor of an element\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		printf("Enter element %d,%d of matrix\n",i+1,j+1);
			scanf("%d", &cmat[i][j]);
		}
	}
	//scanning elements of a 3x3 matrix.
	minor(cmat);
	//calling the minor function.
	printf("\n");
	break;
		}
	case 't':
		//This case helps us to transpose a matrix (Interchanching the rows into columns and vice versa)
		{
	printf("\nEnter rows of your matrix:\n");
   scanf("%d",&m);
   printf("Enter columns of your matrix:\n");
   scanf("%d",&n);
   int tmat[m][n], tmat2[n][m];
   //creating 2 matices, 1 with rowsXcolumns and other with columnsXrows.
   printf("Enter elements of the matrix\n");
   for (i=0;i<m;i++){
      for (j=0;j<n;j++){
         scanf("%d", &tmat[i][j]);
     }
 }
 printf("\n");
 printf("Matrix before transposing\n");
 for(i=0;i<m;i++){
 	for(j=0;j<n;j++){
 		printf("%d\t", tmat[i][j]);
	 }
	 printf("\n");
 }
   for (i=0;i<m;i++){
      for (j=0;j<n;j++){
         tmat2[j][i] = tmat[i][j];
     }
 }
   printf("Transpose of the matrix:\n");
   for (i=0;i<n;i++) {
      for (j=0;j<m;j++){
         printf("%d\t", tmat2[i][j]);
}
printf("\n");
}
printf("\n");
break;
}
case 'g':
	//This case helps us using Gauss Jordans methods to reduce the matrix to an upper triangular matrix and using it to solve simultaneous equations.
	{
	float matg[10][10];
	float s,x[10];
	printf("\nEnter the number of rows of your matrix\n");
    scanf("%d",&p);
    printf("Enter Elements of the matrix:\n");
    //The number of columns are 1 greater than the number of rows as we usually have 3 variables adding up to make one answer. eg. (x1+x2+x3=Y)
    //so its 3 rows for 3 equations and 4 columns for each variable and answer.
    for(i=1;i<=p;i++)
    {
        for(j=1;j<=(p+1);j++)
        {
            printf("Enter element %d,%d: ", i,j);
            scanf("%f",&matg[i][j]);
        }
    }
    for(j=1; j<=p; j++)
    {
        for(i=1; i<=p; i++)
        {
            if(i!=j)
            {
            	//to make an upper triangular matrix we have to make the 4th, 7th and 8th element equals to 0.
            	//this loops helps us in doing that as the first time i=0 and j=0, the loop wont run and i increases.
            	//its i=1 and j=0 now meaning its the 4th element. Same happens for the other elements as well.
                s=matg[i][j]/matg[j][j]; //finds the ratio of the 4th element adn 1st element. //1 2 3 9  ratio= 4/1.
				                                                                               //4 5 6 7
				                                                                              //7 8 9  8
                for(l=1; l<=p+1; l++)
                {
                	//the formula to make the elements 0 is to subtract the element with multiply the value of the element to the ratio of the element and the first element.
                    matg[i][l]=matg[i][l]-s*matg[j][l]; //i=2,l=1,j=1. 4=4-(4/1)(1). makes element 4 = 0., 
                                                        //Does same for other elements (7th and 8th).
                }
            }
        }
    }
    //This loop makes 3 variables and 1 answer in the first row.
    //2 variables and 1 answer int the 2nd row.
    //1 variable and 1 answer in the 3rd row.
    
    // 1 2 3 9
    // 0 5 6 7
    // 0 0 9 8, 9z=8, z=8/9. This is used in the second row to find 6y then in the 1st to find X. 
    printf("The solution of the matrix is:\n");
    for(i=1; i<=p; i++)
    {
        x[i]=matg[i][p+1]/matg[i][i];
        if(i==1){
        printf("\nx=%.3f\n",x[i]);
    }
    else if (i==2){
    	printf("\ny=%.3f\n",x[i]);
	}
	else if(i==3){
		printf("\nz=%.3f\n",x[i]);
	}
    }
    printf("\n");
    break;
	}
	case 'e':
		{
		printf("Thank you for using our program\n");
		return 0;
	}
}
}
}



int cofactor(int arr[3][3]){
	int k[9];
	//Traversing the matrix element by element and applying the formula to find the cofactor.
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		if(i==0 && j==0){
		//this ignores the 1st row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).
		l= (arr[1][1]*arr[2][2])-(arr[1][2]*arr[2][1]);
		//the formula to find the cofactor is to multiply the determinant by 1 to the power of(i+1)+(j+1), we use i+2 and j+2 because in our compiler starts from the 0th element.
		//so we have to use +2 to make it equal to the original formulas +1. 
		k[0]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[0];
	}
		if(i==0 && j==1){
		//this ignores the 1st row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).
		l= (arr[1][0]*arr[2][2])-(arr[1][2]*arr[2][0]);
		k[1]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[1];
	}
		if(i==0 && j==2){
		//this ignores the 1st row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).
		l= (arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0]);
		k[2]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[2];
	}
		if(i==1 && j==0){
		//this ignores the 2nd row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).
		l= (arr[0][1]*arr[2][2])-(arr[0][2]*arr[2][1]);
		k[3]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[3];
	}
		if(i==1 && j==1){
		//this ignores the 2nd row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).
		l= (arr[0][0]*arr[2][2])-(arr[0][2]*arr[2][0]);
		k[4]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[4];
	}
		if(i==1 && j==2){
		//this ignores the 2nd row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).	
		l= (arr[0][0]*arr[2][1])-(arr[0][1]*arr[2][0]);
		k[5]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[5];
	}
		if(i==2 && j==0){
		//this ignores the 3rd row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).		
		l= (arr[0][1]*arr[1][2])-(arr[0][2]*arr[1][1]);
		k[6]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[6];
	}
		if(i==2 && j==1){
		//this ignores the 3rd row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).	
		l= (arr[0][0]*arr[1][2])-(arr[0][2]*arr[1][0]);
		k[7]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[7];
	}
		if(i==2 && j==2){
		//this ignores the 3rd row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).	
		l= (arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]);
		k[8]= pow(-1,(i+2)+(j+2))*l;
		cofactorF[i][j]=k[8];
	}
}}
printf("\n");
}

int minor(int matrix[3][3]){
	int minorF[3][3];
	int k[9];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
	if(i==0 && j==0){
	//this ignores the 1st row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[0]= (matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1]);
		minorF[i][j]=k[0];
	}
		if(i==0 && j==1){
		//this ignores the 1st row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).
		k[1]= (matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0]);
		minorF[i][j]=k[1];
	}
		if(i==0 && j==2){
		//this ignores the 1st row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).
		k[2]= (matrix[1][0]*matrix[2][1])-(matrix[1][1]*matrix[2][0]);
		minorF[i][j]=k[2];	
	}
		if(i==1 && j==0){
		//this ignores the 2nd row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).
		k[3]= (matrix[0][1]*matrix[2][2])-(matrix[0][2]*matrix[2][1]);
		minorF[i][j]=k[3];
	}
		if(i==1 && j==1){
		//this ignores the 2nd row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[4]= (matrix[0][0]*matrix[2][2])-(matrix[0][2]*matrix[2][0]);
		minorF[i][j]=k[4];
	}
		if(i==1 && j==2){
		//this ignores the 2nd row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[5]= (matrix[0][0]*matrix[2][1])-(matrix[0][1]*matrix[2][0]);
		minorF[i][j]=k[5];
	}
		if(i==2 && j==0){
		//this ignores the 3rd row and 1st column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[6]= (matrix[0][1]*matrix[1][2])-(matrix[0][2]*matrix[1][1]);
		minorF[i][j]=k[6];
	}
		if(i==2 && j==1){
		//this ignores the 3rd row and 2nd column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[7]= (matrix[0][0]*matrix[1][2])-(matrix[0][2]*matrix[1][0]);
		minorF[i][j]=k[7];
	}
		if(i==2 && j==2){
		//this ignores the 3rd row and 3rd column and finds the determinant using the leftover elements (this is the minor of an element).	
		k[8]= (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
		minorF[i][j]=k[8];
	}	
}}
printf("\n");
printf("The minor matrix of the input matrix:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t", minorF[i][j]);
		}
			printf("\n");
	}
}
