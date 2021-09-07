#include<stdio.h>
int studentID[100],midterm[100],final[100];

void writeMenu(){
printf("----------------------------------------------------------------\n");
printf("----- Pass Grade : 70 ------ Midterm %40 ------ Final %60 ------\n");
printf("--------------------------------MENU----------------------------\n");
printf("1. Read ID and Midterm Informations of Students From Files\n");
printf("2. Take Final Grades of Students From the User and Write to File\n");
printf("3. Display the Grades\n");
printf("4. Calculate the Course Grade of Students\n");
printf("5. List the Failed Students (Course Grade is less than 70)\n");
printf("6. Display Letter Grades of Students\n");
printf("7. Exit\n");
printf("----------------------------------------------------------------\n\n");
}

void gradesLetter(int a,int id){

	if(a >= 95) printf("Student %d Letter Grade --> AA\n",id);
	else if(a>=90 and a<95) printf("Student %d Letter Grade --> BA\n",id);
	else if(a>=80 and a<90) printf("Student %d Letter Grade --> BB\n",id);
	else if(a>=75 and a<80) printf("Student %d Letter Grade --> CB\n",id);
	else if(a>=70 and a<75) printf("Student %d Letter Grade --> CC\n",id);
	else if(a>=60 and a<70) printf("Student %d Letter Grade --> DC\n",id);
	else if(a>=50 and a<60) printf("Student %d Letter Grade --> DD\n",id);
	else if(a>=35 and a<50) printf("Student %d Letter Grade --> FD\n",id);
	else if(a<35) printf("Student %d Letter Grade --> FF\n",id);
}

int findSize(int c){
		int fSize = 0;
		for(int i=0; i<c; i++){
		fSize++;	
		}	
		return fSize;
}

int readFromFile(FILE *std,int b, int *c){
	int a[100];
	int d= 0;
	while(1){	
		if(feof(std)) {  break;}
		if(b == 0) fscanf(std,"%d",&studentID[d]);
		else fscanf(std,"%d",&midterm[d]);
		d++;

	}
	*c = d;	
	fclose(std);
	
	return a[100];	
}

int main(){

int studentIDs[100],midterms[100],i=0,c=0,a=1,s;
double tn;

writeMenu();
	
while(a==1){

printf("Select Menu Num: ");
scanf(" %d",&s);


switch(s){
	case 1 : {
		studentIDs[100] = readFromFile(fopen("studentID.txt","r"),0,&c);
		midterms[100] = readFromFile(fopen("midterm.txt","r"),1,&c);
		break;	
	}
	case 2 : {
		int fn;
		FILE *ftxt = fopen("final.txt","w");
		for(i=0; i<c; i++){
			printf("The final grade of ID %d:",studentID[i]);
			scanf(" %d",&fn);
			final[i] = fn;
			fprintf(ftxt,"%d\n",fn);
		}
		fclose(ftxt);
		printf("Grades are written to final.txt file\n\n");
				break;
	}
	case 3 : {
		printf("--ID---------Midterm----------Final--\n");
		int fn;
		for(i=0; i<c; i++){
			
			printf("  %d \t \t %d \t \t %d \n",studentID[i],midterm[i],final[i]);
		}
		printf("\n\n",tn);
				break;	
	}
	case 4 : {
		float fn;
		for(i=0; i<c; i++){
			fn = ((4*midterm[i])/10.0)+((6*final[i])/10.0);
			printf("Student %d Course Grade --> %.2f\n",studentID[i],fn);
		}
		printf("\n");
				break;	
	}
	case 5 : {
		float fn;
		for(i=0; i<c; i++){
			fn = ((4*midterm[i])/10.0)+((6*final[i])/10.0);
			if(fn<70)
			printf("ID: %d is failed from the course with %.2f \n",studentID[i],fn);
		}
		printf("\n\n",tn);
				break;	
	}
	case 6 : {
		int fn;
		for(i=0; i<c; i++){
			fn = ((4*midterm[i])/10)+((6*final[i])/10);
			gradesLetter(fn,studentID[i]);
			
		}

				break;	
	}
	case 7 : {
		a = 0;
		break;	
		}
	}
}


return 0;
}
	

