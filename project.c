#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu();
void adminMenu();
void adminLogin();
void addTrain();
void viewBookings();
void userMenu();
void viewTrain();
void bookTicket();
void cancelTicket();
void searchTicket();
int generatePNR();

struct train {
	int train_no;
	char train_name[50];
	char src[20];
	char dest[20];

	int seat_sleeper;
	int seat_3ac;
	int seat_2ac;
	int seat_1ac;
	
	float fare_sleeper;
	float fare_3ac;
	float fare_2ac;
	float fare_1ac;
	
	int seat_alloc_3ac;
	int seat_alloc_2ac;
	int seat_alloc_1ac;
	int seat_alloc_sleeper;
};

struct Passenger{
	int pnr;
	char pass_name[30];
	int age;
	char src[20];
	char dest[20];
	
	int train_no;
	char travel_class[10];
	int seat_no;
	char status[10];
	float fare;
	char berth[10];
};

int generatePNR() 
{
    struct Passenger b;
    FILE *fp = fopen("passengers.dat", "rb");
    int last_pnr = 100234; // Default starting point

    if (fp != NULL) 
	{
        // Move to the last record in the file
        fseek(fp, -(long)sizeof(struct Passenger), SEEK_END);
        if (fread(&b, sizeof(struct Passenger), 1, fp)) 
		{
            last_pnr = b.pnr;
        }
        fclose(fp);
    }
    return ++last_pnr;
}
 
int main()
{
	mainMenu();
	return 0;
}

void mainMenu()
{
	int choice;
	while (1)
	{
		printf("\n===============================");
		printf("\n  RAILWAY RESERVATION SYSTEM   ");
		printf("\n===============================");
		printf("\n1. Admin Login");
		printf("\n2. User Login");
		printf("\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
			
		switch (choice)
		{
			case 1:
				adminLogin();
				break;
			case 2:
				userMenu();
				break;
			case 3:
				exit(0);
			default:
				printf("\nInvalid choice!! Please try again..");
		}
	}
}

void adminLogin()
{
	char id[20], pass[10], ans;
	printf("\nEnter login id: ");
	scanf("%s",id);
	printf("\nEnter password: ");
	scanf(" %s",pass);
	
	if (strcmp(id,"admin")==0 && strcmp(pass,"1234")==0)
	{
		printf("\nLogin Successful!!");
		adminMenu();
	}
	else
	{
		printf("\nInvalid Credentials!!");
		printf("\nWant to try again (y/n)?");
		scanf(" %c",&ans);
		if (ans=='y')
		{
			adminLogin();
		}
		else
		{
			mainMenu();
		}
	}
	
}

void adminMenu()
{
	int choice;
	
	
	while (1)
	{
		printf("\n=================");
		printf("\n   ADMIN MENU    ");
		printf("\n=================");
		printf("\n1. Add Train ");
		printf("\n2. View Trains ");
		printf("\n3. View all bookings ");
		printf("\n4. Logout ");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				addTrain();
				printf("Called");
				break;
			case 2:
				viewTrain();
				break;
			case 3:
				viewBookings();
				break;
			case 4:
				return;
			default:
				printf("Invalid Choice!!");
		}
	}
}

void userMenu()
{
	int choice;
	
	while(1)
	{
		printf("\n=================");
		printf("\n    USER MENU    ");
		printf("\n=================");
		printf("\n1. View Available Trains ");
		printf("\n2. Book Ticket ");
		printf("\n3. Cancel Booking ");
		printf("\n4. View Ticket ");
		printf("\n5. Logout");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				viewTrain();
				break;
			case 2:
				bookTicket();
				break;
			case 3:
				cancelTicket();
				break;
			case 4:
				searchTicket();
				break;
			case 5:
				return;
			default:
				printf("Invalid Choice!!");
		}
	}
}

void addTrain()
{
	struct train t;
	FILE *filepointer;
	filepointer=fopen("train.dat","ab");
	
	if (filepointer== NULL)
	{
		printf("\nError!! File not found..");
		return;
	}
	
	printf("\nEnter train number: ");
	scanf("%d",&t.train_no);
	printf("\nEnter train name: ");
	scanf("%s",t.train_name);
	printf("\nEnter source: ");
	scanf("%s",t.src);
	printf("\nEnter destination: ");
	scanf("%s",t.dest);
	
	printf("\nEnter no. of seats in 1ac: ");
	scanf("%d",&t.seat_1ac);
	printf("\nEnter fare for 1ac: ");
	scanf("%f",&t.fare_1ac);
	
	printf("\nEnter no. of seats in 2ac: ");
	scanf("%d",&t.seat_2ac);
	printf("\nEnter fare for 2ac: ");
	scanf("%f",&t.fare_2ac);
	
	printf("\nEnter no. of seats in 3ac: ");
	scanf("%d",&t.seat_3ac);
	printf("\nEnter fare for 3ac: ");
	scanf("%f",&t.fare_3ac);
	
	printf("\nEnter no. of seats in sleeper: ");
	scanf("%d",&t.seat_sleeper);
	printf("\nEnter fare for sleeper: ");
	scanf("%f",&t.fare_sleeper);
	
	t.seat_alloc_1ac=1;
	t.seat_alloc_2ac=1;
	t.seat_alloc_3ac=1;
	t.seat_alloc_sleeper=1;
	
	fwrite(&t,sizeof(t),1,filepointer);
	fclose(filepointer);
	
	printf("\nTrain added successfully..");
}

void viewTrain()
{
	struct train t;
	FILE *filepointer;
	int flag=0;
	filepointer=fopen("train.dat","rb");
	
	if (filepointer== NULL)
	{
		printf("\nNo train records found..");
		return;
	}
	
	printf("\n==========TRAIN LIST==========");
	
	while (fread(&t,sizeof(t),1,filepointer))
	{
		flag=1;
		printf("\nTrain no: %d",t.train_no);
		printf("\nTrain name: %s",t.train_name);
		printf("\nRoute: %s to %s",t.src,t.dest);
		printf("\nAvailable 1ac seats: %d  | Fare: %.2f",t.seat_1ac,t.fare_1ac);
		printf("\nAvailable 2ac seats: %d  | Fare: %.2f",t.seat_2ac,t.fare_2ac);
		printf("\nAvailable 3ac seats: %d  | Fare: %.2f",t.seat_3ac,t.fare_3ac);
		printf("\nAvailable Sleeper seats: %d  | Fare: %.2f",t.seat_sleeper,t.fare_sleeper);
		printf("\n----------------------------------------------------");
	}
	
	if (!flag)
	{
		printf("\nNo Trains available..");
	}
	fclose(filepointer);
}

void bookTicket()
{
	struct train t;
	struct Passenger b;
	FILE *fpTrain, *fpPass;
	int trainNo, flag=0, passengers,i, Tclass, pnr;
	
	printf("\nEnter Train Number: ");
	scanf("%d", &trainNo);
	fpTrain=fopen("train.dat","rb+");
	if (fpTrain==NULL)
	{
		printf("\nTrain File not found..");
		return;
	}
	
	while (fread(&t,sizeof(t),1,fpTrain))
	{
		if (t.train_no==trainNo)
		{
			flag=1;
			printf("\nHow many passengers? ");
			scanf("%d",&passengers);
			
			for (i=1;i<=passengers; i++)
			{
				printf("\n----Passenger %d----",i);
				printf("\nEnter name of passenger: ");
				scanf("%s",&b.pass_name);
				printf("\nEnter age: ");
				scanf("%d",&b.age);
				printf("\nSelect travel class: ");
				printf("\n1. 1AC \n2. 2AC \n3. 3AC \n4.SLEEPER");
				printf("\nEnter your choice: ");
				scanf("%d",&Tclass);
				printf("\nEnter berth Preference (lower/middle/upper): ");
				scanf("%s",&b.berth);
				
				b.train_no=trainNo;
				strcpy(b.src,t.src);
				strcpy(b.dest,t.dest);
				strcpy(b.status,"Confirmed");
				b.pnr=generatePNR();
				
				if (Tclass==1 && t.seat_1ac>0)
				{
					strcpy(b.travel_class,"1AC");
					b.seat_no=t.seat_alloc_1ac++;
					b.fare=t.fare_1ac;
					t.seat_1ac--;
				}
				
				else if (Tclass==2 && t.seat_2ac>0)
				{
					strcpy(b.travel_class,"2AC");
					b.seat_no=t.seat_alloc_2ac++;
					b.fare=t.fare_2ac;
					t.seat_2ac--;
				}
				
				else if (Tclass==3 && t.seat_3ac>0)
				{
					strcpy(b.travel_class,"3AC");
					b.seat_no=t.seat_alloc_3ac++;
					b.fare=t.fare_3ac;
					t.seat_3ac--;
				}
				
				else if(Tclass==4 && t.seat_sleeper>0)
				{
					strcpy(b.travel_class,"Sleeper");
					b.seat_no=t.seat_alloc_sleeper++;
					b.fare=t.fare_sleeper;
					t.seat_sleeper--;
				}
				
				else{
					printf("\nSeats not available for this class!!");
					continue;
				}
				
				fpPass=fopen("passengers.dat","ab");
				fwrite(&b,sizeof(b),1,fpPass);
				fclose(fpPass);
				
				printf("\nTicket booked!");
				printf("\nPNR Id: %d",b.pnr);
				printf("\nSeat Number: %d",b.seat_no);
				printf("\nTravel Class: %s",b.travel_class);
				printf("\nCalculated Fare: %.2f",b.fare);
			}
			fseek(fpTrain, -(long)sizeof(t), SEEK_CUR);
			fwrite(&t,sizeof(t),1,fpTrain);
			break;
		}
	}
	
	if (!flag)
	{
		printf("\nTrain not found");
	}
	fclose(fpTrain);
}

void viewBookings() 
{
    struct Passenger b;
    FILE *fp;
    int found = 0;

    fp = fopen("passengers.dat", "rb");
    if (fp == NULL) {
        printf("\nNo bookings found!");
        return;
    }

    printf("\n=========== BOOKING DETAILS ===========\n");

    while (fread(&b, sizeof(b), 1, fp)) {
        found = 1;

        printf("\nPNR: %d", b.pnr);
        printf("\nName: %s", b.pass_name);
        printf("\nAge: %d", b.age);
        printf("\nTrain No: %d", b.train_no);
        printf("\nClass: %s", b.travel_class);
        printf("\nBerth: %s", b.berth);
        printf("\nSeat No: %d", b.seat_no);
        printf("\nFare: %.2f", b.fare);
        printf("\n--------------------------------------");
    }

    if (!found) {
        printf("\nNo booking records available.");
    }

    fclose(fp);
}

void cancelTicket() 
{
    struct Passenger b;
    struct train t;
    FILE *fpPass, *fpTemp, *fpTrain;
    int pnr, found = 0;

    printf("\nEnter PNR to cancel ticket: ");
    scanf("%d", &pnr);

    fpPass = fopen("passengers.dat", "rb");
    fpTemp = fopen("temp.dat", "wb");

    if (fpPass == NULL) 
	{
        printf("\nNo bookings found!");
        return;
    }

    while (fread(&b, sizeof(b), 1, fpPass)) 
	{
        if (b.pnr == pnr) 
		{
            found = 1;
			// Restoring seat in train file
            fpTrain = fopen("train.dat", "rb+");
            while (fread(&t, sizeof(t), 1, fpTrain)) 
			{
                if (t.train_no == b.train_no) 
				{

                    if (strcmp(b.travel_class, "3AC") == 0)
                        t.seat_3ac++;
                    else if (strcmp(b.travel_class, "2AC") == 0)
                        t.seat_2ac++;
                    else if (strcmp(b.travel_class, "1AC") == 0)
                        t.seat_1ac++;
                    else if (strcmp(b.travel_class, "Sleeper") == 0)
                        t.seat_sleeper++;

                    fseek(fpTrain, -(long)sizeof(t), SEEK_CUR);
                    fwrite(&t, sizeof(t), 1, fpTrain);
                    break;
                }
            }
            fclose(fpTrain);

            printf("\nTicket cancelled successfully!");
        } 
		else {
            fwrite(&b, sizeof(b), 1, fpTemp);
        }
    }

    fclose(fpPass);
    fclose(fpTemp);

    remove("pasengers.dat");
    rename("temp.dat", "passengers.dat");

    if (!found)
        printf("\nPNR not found!");
}

void searchTicket() 
{
    struct Passenger b;
    FILE *fp;
    int pnr, found = 0;

    printf("\nEnter PNR number to search: ");
    scanf("%d", &pnr);

    fp = fopen("passengers.dat", "rb");
    if (fp == NULL) 
	{
        printf("\nNo booking records found!");
        return;
    }

    while (fread(&b, sizeof(b), 1, fp)) 
	{
        if (b.pnr == pnr) 
		{
            found = 1;

            printf("\n========== TICKET DETAILS ==========");
            printf("\nPNR: %d", b.pnr);
            printf("\nName: %s", b.pass_name);
            printf("\nAge: %d", b.age);
            printf("\nTrain No: %d", b.train_no);
            printf("\nClass: %s", b.travel_class);
            printf("\nBerth: %s", b.berth);
            printf("\nSeat No: %d", b.seat_no);
            printf("\nFare: %.2f", b.fare);
            printf("\n===================================");
            break;
        }
    }

    if (!found)
    {
        printf("\n Ticket not found!");
    }
    fclose(fp);
}

