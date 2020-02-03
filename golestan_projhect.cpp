#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
struct course{
	char  name[15], score[11],id[11];
	
	int number ,code ;
	float grade; 
};
struct teacher{
	char firstname[11], lastname[11], id[11],pass[11];
	bool b;
	struct course cu[5];
};
struct student{
	char firstname[11],lastname[11],id[11], melicode[11], fildname[22];
	float average;	
	bool b;
	struct course co[5];
};
struct  student st;
struct course cr;
struct teacher te;
void MainMenu();
void Student();
void Teacher();
void Course();
void TopStudent();
void Exite();
void enrollmentstudent();
void editionstudent();
void deletionstudent();
void enrollmentteacher();
void editionteacher();
void deletionteacher();
void liststudent();	
void listteacher();
int main(){
	MainMenu();
//	FILE *p;
	
//	p=fopen("my file.txt","w+");
}
void MainMenu(){
	int x;
	printf("lotfan gozine morede nazar ra vared konid:\n");
	printf("student=1\n");
	printf("teacher=2\n");
	printf("course=3\n");
	printf("top students in the major=4\n");
	printf("exit=5\n");
	scanf("%d",&x);
	do{
	switch(x){
		case 1:
			Student();
			break;
		case 2:
			Teacher();
			break;
		case 3:
			Course();
			break;
		case 4:
			TopStudent();
			break;
		case 5:
			Exite();
			break;
		}
	}while(x>5);
	}
	void Student(){
		int x;
			
		printf("enrollment student=1\n");
		printf("edition student=2\n");
		printf("deletion student=3\n");
		printf("list student=4\n");
		scanf("%d",&x);
		switch(x){
			case 1:{
				enrollmentstudent();
				break;
			}
			case 2:
				editionstudent();	
				break;
			case 3:
				deletionstudent();	
				break;	
			case 4:
				liststudent();
				break;	
		} 
	}
	void enrollmentstudent(){
		struct student st;
		struct course cr;
		int n ,count=0 ;
		float sum=0;
		FILE *in ;
		printf("***welcome to enrollment student***/n");
		in=fopen("my.txt","a+");	
		if(in==NULL)
		printf("Cant");
		int x;
		printf("ad student=1/n");
		printf("ad course=2/n");
		scanf("%d",&x);	
		switch(x){
			case 1:{
					printf("enter a first name:\n");
					scanf("%s",&st.firstname);
					printf("enter a last name:\n");
					scanf("%s",&st.lastname);
					printf("enter a id_student:\n");
					scanf("%s",&st.id);
					printf("enter a meli code:\n");
					scanf("%s",&st.melicode);
					printf("enter a fild name:\n");
					scanf("%s",&st.fildname);
					printf("***shoma ba mofaghiat sabte nam kardid***\n");
					fprintf(in,"%-11s %-11s %-15s %-15s %-22s\n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname);
				break;
			}
			case 2:{
				
				while(feof(in)==0){
					printf("enter a number course :\n");
					scanf("%d",n);
					for(int i=0 ;i<n ;i++){
						Course();
						count+=cr.number;
						sum=(sum+cr.grade)*cr.number;
					
					}
					st.average=sum/count;
					fprintf(in,"%f",st.average);
				}
				break;
			}
		}
	
		fclose(in);
	}
void editionstudent()
{
	struct student st;
	FILE *in;
	in=fopen("my.txt","r+");
	FILE *file;
	file=fopen("my1.txt","w");
	printf("***welcome to edition student***\n");
	char ch[11];
	while(feof(in)==0){
		fscanf(in,"%s %s %s %s %s",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname);
		fprintf(file,"%-11s %-11s %-15s %-15s %-22s  \n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname);							
	}
	fclose(in);
	fclose(file);
	in=fopen("my.txt","w");
	file=fopen("my1.txt","r+");
	printf("enter id_student:\n");
	scanf("%s",&ch);
	fscanf(file,"%s %s %s %s %s",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname);
	while(feof(file)==0)
	{
		if(strcmpi(ch,st.id)==0)
		{
			printf("enter a new first name:\n");
			scanf("%s",st.firstname);
			printf("enter a new last name:\n");
			scanf("%s",st.lastname);
			printf("enter a new id_student:\n");
			scanf("%s",st.id);
			printf("enter a new meli code:\n");
			scanf("%s",st.melicode);
			printf("enter a new fild name:\n");
			scanf("%s",st.fildname);
		}
		fprintf(in,"%-11s %-11s %-15s %-15s %-22s \n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname);	
		fscanf(file,"%s %s %s %s %s",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname );
	}
	fclose(in);
	fclose(file);
}
void deletionstudent()
{
	struct student st;
	FILE *in;
	in=fopen("my.txt","r+");
	FILE *file;
	file=fopen("my1.txt","w+");
	printf("***welcome to deletions student***\n");
	char ch[11];
	
	while(feof(in)==0){
		fscanf(in,"%s %s %s %s %s",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname);
		fprintf(file,"%-11s %-11s %-15s %-15s %-22s \n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname);							
	}
	fclose(in);
	fclose(file);
	in=fopen("my.txt","w+");
	file=fopen("my1.txt","r+");
	printf("enter id_student:\n");
	scanf("%s",&ch);
	while(feof(file)==0){
		if(strcmpi(ch,st.id)==0){
			st.b=0;	
		}
		else
			st.b=1;
	}
	fclose(in);
	fclose(file);
	in=fopen("my.txt","w+");
	file=fopen("my1.txt","r+");
	while(feof(file)==0){
		if(st.b==0)
			continue;
		else{
			fscanf(file,"%s %s %s %s %s",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname);
			fprintf(in,"%-11s %-11s %-15s %-15s %-22s \n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname);								
		}	
	}
	fclose(in);
	fclose(file);
}
void liststudent()
{
	FILE *in;
	in=fopen("my file.txt","r");
	float sum=0 ,ave;
	int count=0 ,n;
	struct student st;
	struct course co[5];
	while(feof(in)==0){
		fscanf(in,"%s %s %s %s %s ",&st.firstname ,&st.lastname ,&st.id ,&st.melicode ,&st.fildname);
		printf("%-12s %-12s %-15s %-15s %-22s %f\n",st.firstname ,st.lastname ,st.id ,st.melicode ,st.fildname ,st.average);
	}
	fclose(in);
}
void Teacher()
{
	int x;	
	printf("enrollment teacher=1\n");
	printf("edition teacher=2\n");
	printf("deletion teacher=3\n");
	printf("list teacher=3\n");
	scanf("%d",&x);	
	switch(x)
	{
		case 1:
			enrollmentteacher();
			break;
		case 2:
			editionteacher();
			break;
		case 3:
			deletionteacher();
			break;
		case 4:
			listteacher();	
			break;	
	}
}
void enrollmentteacher()
{
	int n ,y;
	FILE *in1;
	in1=fopen("E:\teacher.txt","a+");
	printf("***welcome to enrollment teacher***");
	printf("ad teacher=1/n");
	printf("ad course=2/n");
	scanf("%d",&y);
	switch(y){
		case 1:{
				printf("enter a first name:\n");
				scanf("%s",&te.firstname);
				printf("enter a last name:\n");
				scanf("%s",&te.lastname);
				printf("enter a id_teacher:");
				scanf("%s",&te.id);
				printf("***shoma ba mofaghiat sabte nam kardid***\n");
				fprintf(in1,"%-11s %-11s %-15s",te.firstname ,te.lastname ,te.id);
			}
			break;
		case 2:{
			printf("enter a number course:/n");
			scanf("%d",&n);
			while(feof(in1)==0){
				for(int i=0 ;i<n ;i++){
					
				}
			}
			break;
		}
	}
	
	fclose(in1);
}
void editionteacher()
{
	struct teacher te;
	FILE *in1;
	in1=fopen("teacher.txt","r+");
	FILE *file;
	file=fopen("my file1.txt","w");
	printf("***welcome to edition teacher***\n");
	char ch[11];
	printf("enter id_teacher:\n");
	scanf("%s",&ch);
	fscanf(in1,"%s %s %s",te.firstname ,te.lastname ,te.id);
	while(feof(in1)==0){
		
		fprintf(file,"%-11s %-11s %-15s",te.firstname ,te.lastname ,te.id);
		fscanf(in1,"%s %s %s",te.firstname ,te.lastname ,te.id);
	}
	fclose(in1);
	fclose(file);
	in1=fopen("teacher.txt","w");
	file=fopen("my1.txt","r+");
	fscanf(file,"%s %s %s ",&te.firstname ,&te.lastname ,&te.id);
	while(feof(file)==0)
	{
		if(strcmpi(ch,te.id)==0)
		{
			printf("enter a new first name:\n");
			scanf("%s",&te.firstname);
			printf("enter a new last name:\n");
			scanf("%s",&te.lastname);
			printf("enter a new id_student:\n");
			scanf("%s",&te.id);
			fprintf(in1,"%-11s %-11s %-15s\n",te.firstname ,te.lastname ,te.id);
		}
		else{
			fprintf(in1,"%-11s %-11s %-15s\n",te.firstname ,te.lastname ,te.id);
		
			}
				fscanf(file,"%s %s %s ",&te.firstname ,&te.lastname ,&te.id);	
	}
	fclose(in1);
	fclose(file);
}
void deletionteacher()
{
	struct teacher te;
	FILE *in1;
	in1=fopen("E:\teacher.txt","r+");
	FILE *file;
	file=fopen("my file1.txt","w+");
	printf("***welcome to deletions teacher***\n");
	char ch[11];
	printf("enter id_teacher:\n");
	scanf("%s",&ch);
	while(feof(in1)==0)
	{
		fscanf(in1,"%s %s %s ",&te.firstname ,&te.lastname ,&te.id);
		fprintf(file,"%-11s %-11s %-15s\n",te.firstname ,te.lastname ,te.id);							
	}
	fclose(in1);
	fclose(file);
	in1=fopen("E:\teacher.txt","w+");
	file=fopen("my file1.txt","r+");
	while(feof(file)==0)
	{
		if(strcmpi(ch,te.id)==0)
		{
			te.b=0;	
		}
		else
			te.b=1;
	}
	while(feof(in1)==0)
	{
		if(te.b==0)
			continue;
		else
		{
			fscanf(file,"%s %s %s ",&te.firstname ,&te.lastname ,&te.id);
			fprintf(in1,"%-11s %-11s %-15s\n",te.firstname ,te.lastname ,te.id);								
		}	
	}
}
void listteacher()
{
	FILE *in1;
	in1=fopen("my file.txt","r");
	float sum=0 ,ave;
	int count=0 ,n;
	struct teacher te;
	while(feof(in1)==0)
	{
		fscanf(in1,"%s %s %s  ",&te.firstname ,&te.lastname ,&te.id );
		printf("%-12s %-12s %-15s\n",te.firstname ,te.lastname ,te.id );
	}
	fclose(in1);
}
void Course()
{
	int x;
	printf("course number:\n");
	printf("math:1\n");
	printf("fizik:2\n");
	printf("mabai:3\n");
	printf("az math:4\n");
	printf("az fizik:5\n");	
	switch(x)
	{
		case 1:
		{
			FILE *co;
			co=fopen("course.txt","a+");
			int y;
			cr.code=1;
			printf("math code=%d",cr.code);
			cr.number=3;
			printf("math number=%d",cr.number);
			printf("enter course grade:\n");
			scanf("%f",&cr.grade);
			printf("student:1\n");
			printf("teacher:1\n");
			scanf("%d",y);
				switch(y)
				{
					case 1:
					{
						printf("enter a student_id:\n");
						scanf("%s",&st.id);
						break;
					}
					case 2:
					{
						printf("enter a teacher_id:\n");
						scanf("%s",te.id);
						break;
					}
				}
			fprintf(co,"%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
			fclose(co);
			break;
		}
		case 2:
		{
			FILE *co;
			co=fopen("course.txt","a+");
			int y;
			cr.code=2;
			printf("fizik code=%d",cr.code);
			cr.number=3;
			printf("fizik number=%d",cr.number);
			printf("enter course grade:\n");
			scanf("%f",&cr.grade);
			printf("student:1\n");
			printf("teacher:1\n");
			scanf("%d",y);
			switch(y){
				case 1:{
					printf("enter a student_id:\n");
					scanf("%s",&st.id);
					break;
				}
				case 2:{
					printf("enter a teacher_id:\n");
					scanf("%s",te.id);
					break;
				}
			}
			fprintf(co,"%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
			fclose(co);
			break;
		}
		case 3:
		{
			FILE *co;
			co=fopen("course.txt","a+");
			int y;
			cr.code=3;
			printf("mabani code=%d",cr.code);
			cr.number=3;
			printf("mabani number=%d",cr.number);
			printf("enter course grade:\n");
			scanf("%f",&cr.grade);
			printf("student:1\n");
			printf("teacher:1\n");
			scanf("%d",y);
			switch(y){
				case 1:{
					printf("enter a student_id:\n");
					scanf("%s",&st.id);
					break;
				}
				case 2:{
					printf("enter a teacher_id:\n");
					scanf("%s",te.id);
					break;
				}
			}
			fprintf(co,"%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
			fclose(co);
			break;
		}
		case 4:
		{
			FILE *co;
			co=fopen("course.txt","a+");
			int y;
			cr.code=4;
			printf("az math code=%d",cr.code);
			cr.number=1;
			printf("az math number=%d",cr.number);
			printf("enter course grade:\n");
			scanf("%f",&cr.grade);
			printf("student:1\n");
			printf("teacher:1\n");
			scanf("%d",y);
			switch(y){
				case 1:{
					printf("enter a student_id:\n");
					scanf("%s",&st.id);
					break;
				}
				case 2:{
					printf("enter a teacher_id:\n");
					scanf("%s",te.id);
					break;
				}
			}
			fprintf(co,"%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
			fclose(co);
			break;
		}
		case 5:
		{
			FILE *co;
			co=fopen("course.txt","a+");
			int y;
			cr.code=5;
			printf("az fizik code=%d",cr.code);
			cr.number=1;
			printf("az fizik number=%d",cr.number);
			printf("enter course grade:\n");
			scanf("%f",&cr.grade);
			printf("student:1\n");
			printf("teacher:1\n");
			scanf("%d",y);
			switch(y){
				case 1:{
					printf("enter a student_id:\n");
					scanf("%s",&st.id);
					break;
				}
				case 2:{
					printf("enter a teacher_id:\n");
					scanf("%s",te.id);
					break;
				}
			}
			fprintf(co,"%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
			fclose(co);
			break;
		}
	}
	FILE *co;
	co=fopen("course.txt","r+");
	while(feof(co)==0)
	{
		fscanf(co,"%-5d %-4d %-8f %-11s",&cr.code ,&cr.number ,&cr.grade ,&st.id);
		printf("%-5d %-4d %-8f %-11s",cr.code ,cr.number ,cr.grade ,st.id);
	}
	fclose(co);	
}
void TopStudent()
{
	struct course cr;
	char name[30];	
	FILE *co;
	float max1,max2,max3;
	scanf("%s",name);
	co=fopen("course.txt","r+");
	fscanf(co,"%s %s %f",cr.name,cr.code,cr.grade);
	if(strcmp(name,cr.name)==0)
	{
		max1=cr.grade;
		max2=cr.grade;
		max3=cr.grade;	
	}	
	while(feof(co)==0)
	{
		if(strcmp(name,cr.name)==0)
		{
			if(cr.grade>max1)
			{
				max1=cr.grade;	
			}
				if(cr.grade<=max1&&cr.grade>max2)
			{
				max2=cr.grade;	
			}
				if(cr.grade<=max1&&cr.grade<=max2&&cr.grade>max3)
			{
				max3=cr.grade;	
			}	
		}	
	}
		printf("top1:%f\ntop2:%f\ntop3:%f",max1,max2,max3);
}
void Exite()
{
	exit(0);
}
/////////////////////////////////////////////////////////////////////
void check(){
	int truee=0;
	char pass[30];
	char id[30];
	FILE *p;
	for(;;)
	{
		scanf("%s",id);
		scanf("%s",pass);
	//	p=open("passwords.txt","r+");	
		while(feof(p)==0)
		{
			fscanf(p,"%s %s",te.id,te.pass);
			if(strcmp(te.id,id)==0&&strcmp(te.pass,pass)==0)
			{
				truee=1;
				break;
			}
		}
		if(truee==1)
		//showscores();	
		printf("hi");
	}
}
showscores()
{
	FILE *p;
	//p=fopen("course.txt","r+");
	printf("1:math");
	printf("2:programming");
	printf("3:english");
	char c;
	c=getchar();
	switch(c)
	{
		case 1:
		{
			while(feof(p)==0)
			{
				fscanf("%s %s %f",cr.name,cr.id,&cr.score);
				if(strcmp(cr.name,"math")==0)
					printf("%s %f\n",cr.id,cr.score);
			}	
			break;
		}
		case 2:
		{	
			while(feof(p)==0)
			{
				fscanf("%s %s %f",cr.name,cr.id,&cr.score);
				if(strcmp(cr.name,"programing")==0)
					printf("%s %f\n",cr.id,cr.score);
			}
			break;
		}
		case 3:
		{
			while(feof(p)==0)
			{
				fscanf("%s %s %f",cr.name,cr.id,&cr.score);
				if(strcmp(cr.name,"english")==0)
					printf("%s %f\n",cr.id,cr.score);
			}
			break;
		}
	}	
}
	
	
