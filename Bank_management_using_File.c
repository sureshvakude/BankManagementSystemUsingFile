#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//#include<windows.h>
struct Acc
{
    char acn[10];
    char Fname[50];
    char Lname[50];
    char atype[100];
    int bal;
    char pass[5];
    char phone[11];
    char add[100];
};

struct Acc *temp;
char user[25]="admin";
char pass[25]="1111";
void BankReg();
void show();
int SearchAcc();
void withdrawal(int (*p)());
void deposit(int (*q)());
void AccDel(int (*q)());
int login();
void signup();
void fordelay(int j);

int main()
{

    system("color A");
    int j,num;
    int mchoice,choice; 
    int i = 3; // No. of Attempts for Login
    int l;
    
    while(1)
    {
    	rk:

        printf("\n\t\t****WELCOME****\n");
        printf("\n\t1.LOGIN\n");
        printf("\n\t2.SIGNUP\n");
        printf("\n\t3.EXIT\n");
        printf("\n\nSELECT YOUR CHOICE : ");
        scanf("%d",&mchoice);
        switch(mchoice)
        {


        case 1:
            system("cls");
            printf("\n\t\t****WELCOME****\n");
            num = login();
            if(num == -1)
            {
                goto rk;
            }
            system("cls");
            printf("\n\t\t****WELCOME TO OUR BANK SERVICES****\n\n");
            printf("\t1.New Registration\n");
            printf("\t2.Withdrawal\n");
            printf("\t3.Deposit\n");
            printf("\t4.Display Account Details\n");
            printf("\t5.Search Account Details\n");
            printf("\t6.Account Deletion\n");
            printf("\t7.Exit\n");
            printf("\n Select Your Choice : ");
            scanf("%d",&choice);
            printf("\n");

            while(choice != 7)
            {
                switch(choice)
                {
                case 1:

                    BankReg();
                    break;
                case 4:

                    show();
                    break;
                case 5:
                    printf("\n\t\t\t\t****Search_Account_Details****\n\n");
                    SearchAcc();
                    break;
                case 2:

                    withdrawal(SearchAcc);
                    break;
                case 3:

                    deposit(SearchAcc);
                    break;
                case 6:
                    AccDel(SearchAcc);
                    break;
                default:

                    printf("You have Entered Wrong Choice , PLEASE ENTER VALID KEY\nLOADING");
                    for(j=0; j<=6; j++)
                    {
                        fordelay(100000000);
                        printf(".");
                    }
                    break;
                }
r:
                printf("\nPress ""1"" For Main Menu / Press ""0""  to exit\n");
                scanf("%d",&num);
                if(num == 1)
                {
                    system("cls");
                    printf("\n\t\t****WELCOME TO OUR BANK SERVICES****\n\n");
                    printf("\n1.New Registration\n2.Withdrawal\n3.Deposit\n4.Display Account Details\n5.Search Account Details\n6.Account Deletion\n7.Exit\nSelect Your Choice : ");
                    scanf("%d",&choice);

                }
                else if(num == 0)
                {
                    printf("\n\t\t\t****THANK YOU FOR BANKING WITH US****");
                    return 0;
                }
                else
                {
                    printf("\n\t\tINVALID CHOICE ENTERED !!! PLEASE ENTER RIGHT KEY .\nLOADING");
                    for(j=0; j<=6; j++)
                    {
                        fordelay(100000000);
                        printf(".");
                    }
                    goto r;
                }
                if(choice == 7) // FOR GREETING I AM USING ( NOT NECCESSARY )
                {

                    printf("\n\t\t\t****THANK YOU FOR BANKING WITH US****");
                    return 0;

                }
            }
            if(choice == 7) // FOR GREETING I AM USING ( NOT NECCESSARY )
            {

                printf("\n\t\t\t****THANK YOU FOR BANKING WITH US****");
                return 0;

            }
            break;


        case 2:
            signup();
            printf("\n\n\t\tACCOUNT CREATED SUCCESSFULLY\n");
p:
            printf("\n\t\tPRESS '1' TO LOGIN OR PRESS '0' TO EXIT :  ");
            scanf("%d",&l);
            if(l == 1)
            {

                system("cls");
            }
            else if(l==0)
            {
                system("cls");
                printf("\n\t\t\t****THANK YOU FOR BANKING WITH US****");
                return 0;
            }
            else
            {

                printf("\n\t\tINVALID KEY ENTERED , PLEASE ENTER VALID KEY");
                for(j=0; j<=15; j++)
                {
                    fordelay(100000000);
                    printf(".");
                }

                goto p;
            }

            break;
        case 3:
            printf("\n\t\t\t****THANK YOU FOR BANKING WITH US****");
            return 0;
            break;

        default:
            printf("\n\t\tINVALID KEY ENTERED !!!\n");
            printf("\n\n\t\tPLEASE ENTER RIGHT KEY");
            for(j=0; j<=15; j++)
            {
                fordelay(100000000);
                printf(".");
            }
            system("cls");
            break;

        }
    }

    return 0;
}





void BankReg()
{
    system("cls");
    printf("\n\t\t\t\t****NEW_REGISTRATION****\n\n");
    int i,k;
    int tacn,tpass;
    int accn;
    FILE *ptr = NULL;
    ptr = fopen("record.txt","a+");
    temp = (struct Acc*)malloc(sizeof(struct Acc));

    getchar();
    printf("Enter Your First name & Last name : ");
    scanf("%s %s",temp->Fname,temp->Lname);

    getchar();
    printf("Enter Address  : ");
    gets(temp->add);

o:
    printf("Enter mobile num. : ");
    scanf("%s",temp->phone);
    while(!(strlen(temp->phone)==10))
    {
        printf("please enter the only 10 digits!");
        printf("Enter mobile num. : ");
        scanf("%s",temp->phone);
    }
    for( k=0; k<strlen(temp->phone); k++)
    {
        if(!isdigit(temp->phone[k]))
        {
            printf("invalid number!..");
            goto o;
        }
    }

    printf("Enter Account Type (Saving/Current) : ");
    scanf("%s",&temp->atype);

    getchar();
    srand(time(NULL));
    tacn =(rand()%(99999-10000+1))+10000;
    itoa(tacn,temp->acn,10);
    tpass = (rand()%(9999-1000+1))+1000;
    itoa(tpass,temp->pass,10);


    do
    {
        printf("Enter Amount : ");
        scanf("%d",&temp->bal);
        if(temp->bal<500)
            printf("Please Enter Amount Above 500\n");
    }
    while(temp->bal<500);


    fprintf(ptr,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);
    getchar();


    system("cls");
    printf("\n\t\t****Congratulations Your Account has been Created Successfully****\n\n");
    printf("Your account number & password is generated....\n");
    printf("ACCOUNT NUMBER 	: %s\n",temp->acn);
    printf("PASSWORD	: %s",temp->pass);
    fclose(ptr);
    free(temp);
}


void show()
{
    system("cls");
    printf("\n\t\t****WELCOME TO OUR BANK SERVICES****\n\n");
    int count = 0;
    int j = 0;
    int i=3;
    temp = (struct Acc*)malloc(sizeof(struct Acc)); // DYNAMIC MEMORY ALLOCATION
    char user_[10];
    char pass_[5];
    unsigned int month,year;
    char DATE[30],TIME[30];

    FILE *p = fopen("record.txt","r");

    printf("\n\t\t****ADMIN LOGIN****\n\n");
    while(i>0)
    {
        printf("\nLogin    : ");
        scanf("%s",user_);
        printf("\n\nPassword :");
        scanf("%s",pass_);

        if(strcmp(user,user_)== 0 && strcmp(pass,pass_)==0)
        {
            printf("\n\t\t****LOGIN SUCCESSFUL****\n\t\tLOADING");

            break;
        }
        else
        {
            printf("\n\t\t****LOGIN FAILED****\n");
            printf("\n\t\tINVALID USERNAME OR PASSWORD !\n");
            printf("\n\t\tYou have only %d attempts/attempt remaining !!!\n",--i);
        }
    }
    if(i==0)
    {

        printf("\n\t\tTry again latter\n");
        return;
    }

    system("cls");
    printf("\n\t\t\t\t****All_Existing_Accounts_Details****\n\n");


    while(fscanf(p,"%s %lu %lu %s %s %s %s %s %s %s %s %d",DATE,&month,&year,TIME,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,&temp->bal) != EOF)
    {

        count =1;
        printf("\tUPDATED ACCOUNT ON DATE : %s %d %d AT %s\n",DATE,month,year,TIME);
        printf("\tNAME            : %s %s\n",temp->Fname,temp->Lname);
        printf("\tADDRESS         : %s\n",temp->add);
        printf("\tPHONE NUMBER    : %s\n",temp->phone);
        printf("\tACCOUNT TYPE    : %s\n",temp->atype);
        printf("\tACCOUNT NUMBER  : %s\n",temp->acn);
        printf("\tAccount Balance : RS. %d \n\n",temp->bal);
    }

    if(count==0)
    {
        printf("\n\t\tNO ACCOUNTS REGISTERED TO OUR BANK , TRY AGAIN LATTER\n");

    }
    fclose(p);
    free(temp);
}








int SearchAcc()
{



    int i = 3,j;//USER ATTEMPTS (USERNAME)
    int k=3; // USER ATTEMPTS(PASSWORD)
    int choice;// USER CHOICE FOR CONTINUE OR EXIT
    int count=0;// TO KNOW ATLEAST ONE ACCOUNT REGISTERED IN BANK
    char acnum[10];
    char passcode[5];
    char DATE[25],TIME[25];
    unsigned int month,year;
    int flag ;// To know account present or not
    temp = (struct Acc*)malloc(sizeof(struct Acc)); // DYNAMIC MEMORY ALLOCATION
    FILE *p = fopen("record.txt","r");

    while(i>0)
    {


        rewind(p);
        printf("\nENTER ACCOUNT NUMBER : ");
        scanf("%s",acnum);
        flag = 0;

        while(fscanf(p,"%s %lu %lu %s %s %s %s %s %s %s %s %d",DATE,&month,&year,TIME,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,&temp->bal) != EOF)
        {

            if(!(strcmp(temp->acn,acnum)))
            {
                flag = 1; //ACCOUNT PRESENT


                printf("\nENTER YOUR PASSWORD : ");
                scanf("%s",passcode);

                while( strcmp(passcode,temp->pass) && k>0)
                {
                    printf("\nINVALID PASSWORD ENTERED!\n");
                    printf("\n\t\tYou have only %d attempts/attempt remaining !!!\n",--k);
                    if(k==0)
                    {
                        printf("\n\t\tTry again latter\n");
                        return -1;
                    }
                    else
                    {
                        printf("\n\nENTER YOUR PASSWORD : ");
                        scanf("%s",passcode);
                    }
                }
                count++;
                break;

            }
            count++; //ATLEAST ONE ACCOUNT PRESENT

        }
        if(count==0)
        {
            printf("\n\t\tNO ACCOUNTS REGISTERED TO OUR BANK , TRY AGAIN LATTER\n");
            return -1;
        }
        else if(flag == 0)
        {
            printf("\n\t\t****LOGIN FAILED****\n");
            printf("\n\t\tINVALID USERNAME!\n");
            printf("\n\t\tYou have only %d attempts/attempt remaining !!!\n",--i);
            if(i==0)
            {
                printf("\n\t\tTry again latter\n");
                return -1;
            }
r:
            printf("\n\t\tIF YOU WANT TO TRY AGAIN PRESS '1' OR PRESS '0' FOR EXIT .\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                continue;
            }
            else if(choice == 0)
            {
                system("cls");
                printf("\n\t\tTHANK YOU FOR BANKING WITH US\n");
                return -1 ;
            }
            else
            {
                printf("\n\t\tINVALID CHOICE ENTERED !!! PLEASE ENTER RIGHT KEY .\nLOADING");
                for(j=0; j<=6; j++)
                {
                    fordelay(100000000);
                    printf(".");
                }
                goto r;
            }
        }
        else
        {

            break;
        }

    }
    printf("\nMATCH FOUND ! PROCESSING");
    for(j=0; j<=6; j++)
    {
        fordelay(100000000);
        printf(".");
    }

    system("cls");
    printf("\n\t\tWELCOME TO OUR BANK \n\n");
    printf("\n\t\tYour Account Details :\n\n");
    printf("\tAccount No. : %s\n",temp->acn);
    printf("\tName        : %s %s\n",temp->Fname,temp->Lname);

    printf("\tAccount Type: %s\n",temp->atype);
    printf("\tBalance     : %d\n\n",temp->bal);

    fclose(p);
    i = (atoi(temp->acn));
    return i;
}



void withdrawal(int (*p)())
{
    system("cls");
    printf("\n\t\t\t\t****Withdrawal****\n\n");
    char DATE[25],TIME[25];
    int month,year;
    int amount,num;
    
    char accNumber[50];
    int FOUND;// temporary
    FILE *OldFile = fopen("record.txt","r");
    FILE *NewFile = fopen("new.txt","a");
    temp = (struct Acc*)malloc(sizeof(struct Acc)); // DYNAMIC MEMORY ALLOCATION
    FOUND = p();


    if(FOUND==-1)
    {
        printf("NO ACCOUNT ARE REGISTERED !......NOT FOUND");
        return ;
    }
    itoa(FOUND,accNumber,10); // int to string


    while(fscanf(OldFile,"%s %lu %lu %s %s %s %s %s %s %s %s %d",DATE,&month,&year,TIME,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,&temp->bal) != EOF)
    {


        if(strcmp(temp->acn,accNumber)==0)
        {
r:

            printf("\nEnter Withdrawal Amount : ");
            scanf("%d",&amount);
            if((amount<0) || (amount>temp->bal) || (amount%100 != 0))
            {
                printf("\nInvalid Amount Entered , \ni) You can Transact only in multiple of 100!!!\n");
                goto r;
            }
            temp->bal = temp->bal-amount;
            printf("\n\nTrasacting RS. %d",amount);
            printf("\n\nRemaining balance : %d\n\n",temp->bal);
            
            // WE CAN NOT WRITE INTEGER AS A INT USING APPEND MODE , ITS ONLY DONE TROUGH W(WRITE) MODE ***VIMP
            fprintf(NewFile,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);

        }
        else
        {
            
            fprintf(NewFile,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);
        }

    }


    fclose(OldFile);
    fclose(NewFile);
    remove("record.txt");
    rename("new.txt","record.txt");
    free(temp);
}



void deposit(int (*q)())
{
    system("cls");
    printf("\n\t\t\t\t****Deposit****\n\n");

    char accNumber[50];
    int j;
    char DATE[25],TIME[25];
    unsigned int month,year;
    int amount,num;
    
    int FOUND;// FOR STORING THE ACCOOUNT NUMBER
    temp = (struct Acc*)malloc(sizeof(struct Acc)); // DYNAMIC MEMORY ALLOCATION
    FOUND = q();
    FILE *OldFile = fopen("record.txt","r");
    FILE *NewFile = fopen("new.txt","a");
    if(FOUND==-1)
    {

        return;
    }

    itoa(FOUND,accNumber,10); // int to string
    while(fscanf(OldFile,"%s %lu %lu %s %s %s %s %s %s %s %s %d",DATE,&month,&year,TIME,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,&temp->bal) != EOF)
    {
        if(strcmp(temp->acn,accNumber)==0)
        {
r:
            printf("\nENTER AMOUNT TO DEPOSIT ($):  ");
            scanf("%d",&amount);
            if(!(amount>0) || !(amount%100==0))
            {
                printf("Invalid amount Entered !!!\n");
                printf("i)You can deposit amount only in multiple of 100 , please try again\n");
                goto r;
            }
            printf("\nPROCESSING");
            for(j=0; j<=6; j++)
            {
                fordelay(100000000);
                printf(".");
            }
            temp->bal+=amount;
            printf("\n\t\t****YOU HAVE SUCCESSFULLY DEPOSITED RS.%d TO YOUR ACCOUNT****\n",amount);


            printf("\n\t\tMAIN BALANCE : %d\n",temp->bal);
            printf("\n\n\tTHANK YOU FOR BANKING WITH US\n");
            

            fprintf(NewFile,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);
        }
        else
        {
            
            fprintf(NewFile,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);
        }

    }

    fclose(OldFile);
    fclose(NewFile);
    remove("record.txt");
    rename("new.txt","record.txt");
    free(temp);

}

void AccDel(int (*q)())
{
    printf("\n\t\t\t\t****Account_Deletion****\n\n");
    char DATE[25],TIME[25];
    char accNumber[50];
    unsigned int month,year;
    int amount,num,choice;

    int FOUND;// FOR STORING THE ACCOOUNT NUMBER
    temp = (struct Acc*)malloc(sizeof(struct Acc)); // DYNAMIC MEMORY ALLOCATION
    FOUND = q();
    FILE *OldFile = fopen("record.txt","r");
    FILE *NewFile = fopen("new.txt","a");
    if(FOUND==-1)
    {

        return ;
    }

    itoa(FOUND,accNumber,10); // int to string
    while(fscanf(OldFile,"%s %lu %lu %s %s %s %s %s %s %s %s %d",DATE,&month,&year,TIME,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,&temp->bal) != EOF)
    {
        if(strcmp(temp->acn,accNumber)==0)
        {
r:

            printf("\n\t\tIF YOU WANT TO DELETE YOUR ACCOUNT THEN PRESS '1' OR PRESS '0' FOR EXIT .\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("\n\t\tYOU HAVE DELETED YOUR ACCOUNT SUCCESSFULLY , THANK YOU BANKING WITH US\n");
            }
            else if(choice == 0)
            {
                printf("\n\t\tREQUESTING TO EXIT\n");
                return;
            }
            else
            {
                printf("\n\t\tINVALID CHOICE ENTERED !!! PLEASE ENTER RIGHT KEY .\n");
                goto r;
            }


        }
        else
        {
           
            fprintf(NewFile,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,temp->Fname,temp->Lname,temp->add,temp->phone,temp->atype,temp->acn,temp->pass,temp->bal);
        }

    }

    fclose(OldFile);
    fclose(NewFile);
    remove("record.txt");
    rename("new.txt","record.txt");
    free(temp);

}

void fordelay(int j)
{
    int i,k;
    for(i=0; i<j; i++)
        k=i;
}

int login()
{
	int flag =0;
	int j;
	char lpass[10];
	char luser[20];
	char usernm[20];
	char passnm[10];
	FILE *pt=NULL;
	pt=fopen("log.txt","r");
	printf("USERNAME : ");
	scanf("%s",luser);
	printf("PASSWORD : ");
	scanf("%s",lpass);
	while((fscanf(pt,"%s %s",usernm,passnm)) != EOF)
	{
		if(strcmp(usernm,luser)==0 && strcmp(passnm,lpass)==0)
		{
			flag = 1;
			printf("\n\t\tLOGIN SUCCESFULL\n\n\t\tLOADING");
			for(j=0; j<=6; j++)
            {
                fordelay(100000000);
                printf(".");
            }
			fclose(pt);
			return 0;
			
		}
	}
	if(flag ==0)
	{
		printf("LOGIN FAILED ! PLEASE SIGN UP FIRST .....");
		fclose(pt);
		return -1;
	}
	
}

void signup()
{
	char usern[20];
	char passn[10];
	printf("\n\t\t\t*****WELCOME*****\n");
	FILE *p= NULL;
	p=fopen("log.txt","a");
	printf("ENTER USERNAME : ");
    scanf("%s",usern);
	printf("ENTER PASSWORD : ");
	scanf("%s",passn);
	fprintf(p,"%s %s ",usern,passn);
	fclose(p);
}
