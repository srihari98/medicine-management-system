#include<Stdio.h>
#include<conio.h>
#include<string.h>
void entry_menu();
void display();
void search();
void insert();
void delete1();
void update();
void bill();

 main()
{ 
int c;
	printf("\t\t\t\t\t            WELCOME        \n");
        printf("\n\t\t\t\t\t#Medicine Management Record System#");
        printf("\n\t\t\t\t\t==================================\n\n");
        printf("\n");
        getch();
        

		printf("\n\n\tMain menu");
		printf("\n\t1.ENTRY/EDIT");
		printf("\n\t2.exit\n");
		printf("\nchoose your number(1-2)");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			        entry_menu();
			        break;
			case 2:	
			       printf("your exit");
		}	
}
struct details
{
	char name[50];
	char type[50];
	float rate;
	int manufacture;
	int expiry;
	int quantity;
}x;
void entry_menu()
{  
system("cls");
    int c2;
  printf("\n\n\n\t\tENTRY MENU");
  printf("\n\t\t\t1.DISPLAY ALL MEDICINES\n");
  printf("\n\t\t\t2.INSERT MEDICINES\n");
  printf("\n\t\t\t3.SEARCH MEDICINE\n");
  printf("\n\t\t\t4.DELETE MEDICINE\n");
  printf("\n\t\t\t5.UPDATE MEDICINE\n");
  printf("\n\t\t\t6.CREATE BILL");
   printf("\n\t\t\t7.EXIT MENU");
  printf("\n\n\tPlease Enter Your Choice (1-5)");
  scanf("%d",&c2);
  switch(c2)
  {
    case 1: 
    {
            display();
            break;
    }
  case 2:
  {
  	insert();
  	break;
  }
  case 3:
  	{
  		search();
  		break;
  	}
  case 4:
  	{
  		delete1();
  		break;
  	}
  case 5:
  	{
  	    update();
  	    break;
  	}
  	
  	case 6:
  		{
  				bill();
  				break;
		  }
		  
		  	case 7:
  		{
  				printf("YOUR EXIT");
  				break;
		  }
  default :
            printf("you choose wrong option");	
   }
}
void insert()
{
  int i,n;
  
	FILE *s;
	s=fopen("medicine.txt","a");
	printf("\n");
	printf("Enter Name: \n");
	scanf("%s",x.name);
	printf("Medicine type: \n");
	scanf("%s",x.type);
	printf("Enter Rate: \n");
	scanf("%f",&x.rate);
	printf("Enter Manufacture date yy: \n");
	scanf("%d",&x.manufacture);
	printf("Enter Expiry yy: \n");
	scanf("%d",&x.expiry);
	printf("Enter Quantity: \n");
	scanf("%d",&x.quantity);
	fwrite(&x,sizeof(x),2,s);
	fclose(s);
	printf("medicine has inserted");
	getch();
	entry_menu();
}
void display()
{
   FILE *s;
   s=fopen("medicine.txt","r");
   if(s==NULL)
   {
   	printf("NOTHING TO SHOW");
   }
   else
   {	
   	while((fread(&x,sizeof(x),2,s)))
   	{
			printf("\nMEDICINE NAME:%s",x.name);
			printf("\nMEDICINE TYPE:%s\n",x.type);
			printf("RATE:%f\n",x.rate);
			printf("MANUFACTURE:%d\n",x.manufacture);
			printf("EXPIRY:%d\n",x.expiry);
			printf("QUANTITY%d\n",x.quantity);
   		}
   		fclose(s);
  }	
}
void search()
{
	char m[20];
	printf("enter name of medicine you want to serch");
	scanf("%s",m);
	FILE *s;
	s=fopen("medicine.txt","r");
	while(fread(&x,sizeof(x),2,s))
	{
		if(stricmp(m,x.name)==0)
		{	
			printf("\nName:%s",x.name);
			printf("\nMEDICINE TYPE:%s",x.type);
			printf("\nRate:%f",x.rate);
			printf("\nManufacture:%d",x.manufacture);
			printf("\nExpiry:%d",x.expiry);
			printf("\nQuantity:%d",x.quantity);
		}
	}
}
void delete1()
{
  FILE *s,*p;
  char n[20];
  s=fopen("medicine.txt","r");
  p=fopen("delete.txt","w");
  printf("ENTER MEDICINE YOU WANT TO DELETE");
  scanf("%s",n);
  while(fread(&x,sizeof(x),2,s))
  {
  	if(stricmp(n,x.name)!=0)
  	{
  		fwrite(&x,sizeof(x),2,p);
  	}
  }	
  fclose(s);
  fclose(p);
  s=fopen("medicine.txt","w");
  p=fopen("delete.txt","r");
  while(fread(&x,sizeof(x),2,p))
  {
  	fwrite(&x,sizeof(x),2,s);
  }
  fclose(s);
  fclose(p);
  
  
  }
  
  void update()
{
  FILE *s,*p;
  char n[20];
  s=fopen("medicine.txt","r");
  p=fopen("delete.txt","w");
  printf("ENTER MEDICINE YOU WANT TO UPDATE");
  scanf("%s",n);
  while(fread(&x,sizeof(x),2,s))
  {
  	if(stricmp(n,x.name)!=0)
  	{
  		fwrite(&x,sizeof(x),2,p);
  	}
  	
  	else
  	{
  	printf("Enter the name : ");
    scanf("%s",x.name);
	printf("Enter the type of medicine : ");
	scanf("%s",x.type);
	printf("Enter the rate of the medicine :  ");
	scanf("%f",&x.rate);
    printf("Enter the units of the medicine : ");
    scanf("%d",&x.quantity);
    printf("Enter the manufacturing date : ");
    scanf("%d",&x.manufacture);
    printf("Enter the expiry date : ");
    scanf("%d",&x.expiry);
    fwrite(&x,sizeof(x),2,p);	
	  }
  }	
  fclose(s);
  fclose(p);
  s=fopen("medicine.txt","w");
  p=fopen("delete.txt","r");
  while(fread(&x,sizeof(x),2,p))
  {
  	fwrite(&x,sizeof(x),2,s);
  }
  fclose(s);
  fclose(p);
  printf("UPDATED SUCCESSFULLY");
  
  getch();
  entry_menu();  
  
  }
  
  
void bill()
{
	int sum=0,n,t;
	
	abc:
		system("cls");
	printf("\n\n\n1.select medicine\n2.create bill : ");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1 :
			{	char m[20];
	printf("enter name of medicine you want to serch");
	scanf("%s",m);
	FILE *s;
	s=fopen("medicine.txt","r");
	while(fread(&x,sizeof(x),2,s))
	{
		if(stricmp(m,x.name)==0)
		{	
			printf("\nName:%s",x.name);
			printf("\nMEDICINE TYPE:%s",x.type);
			printf("\nRate:%f",x.rate);
			printf("\nManufacture:%d",x.manufacture);
			printf("\nExpiry:%d",x.expiry);
			printf("\nQuantity:%d",x.quantity);
			printf("\n\t\t\t\thow many units do you want : ");
			scanf("%d",&t);
			sum=sum+t*(x.rate);
	        goto abc;
		}
	}
			}
		
	 case 2 :	
		{
		  printf("\n\n\t\t\t\tTOTAL COST : %d",sum);
		}
		
		
	}

	
	
	
	
	
	
	
	
	
	
	
	
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  



