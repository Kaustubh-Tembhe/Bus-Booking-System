#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[20];
    int busno;
    int num_seat;
}pd;

void Booking();
void viewbus(void);
void printticket(char name[],int,int,float);
void findbus(int);
float charge(int,int);

int main()
{

    int choice,n;
	start:
    system("cls");
    system("color 7D");
    printf("\n\t\t\t\t=================================\n");
	printf(" \t\t\t\t    BUS BOOKING SYSTEM");
	printf("\n\t\t\t\t=================================");
	printf("\n\t\t\t\t1) Booking");
	printf("\n\t\t\t\t------------------------");
	printf("\n\t\t\t\t2) View Buses");
	printf("\n\t\t\t\t------------------------");
	printf("\n\t\t\t\t3) Search Bus by Number");
	printf("\n\t\t\t\t------------------------");
	printf("\n\t\t\t\t4) Exit");

	printf("\n\t\t\t\t:)");
	scanf("%d",&choice);
    switch(choice)
	{
		case 1:
			Booking();
			break;
		case 2:
			viewbus();
			printf("\n\nPress any key to go on Main Menu..");
			getch();
			break;
		case 3:
            printf("Enter a number of bus :\t");
            scanf("%d",&n);
            findbus(n);
            break;
        case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

void viewbus(void)
{
	system("cls");
	system("color 04");
	printf("---------------------------------------------------------------------------------------");
	printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n1001\tPooja Travels        \tNagpur To Mumbai       \tRs.3850   \t\t9:00  AM");
	printf("\n1002\tDevit Travels        \tNagpur To Nashik       \tRs.2500  \t\t12:00 PM");
	printf("\n1003\tHero Travels         \tNagpur To Pune         \tRs.2450   \t\t1:50  PM");
	printf("\n1004\tSuper Deluxe         \tNagpur To Hydrabad     \tRs.2450   \t\t11:00 AM");
	printf("\n1005\tSai Baba Travels     \tNagpur To Cheenai      \tRs.1900  \t\t7:05  AM");
	printf("\n1006\tShine On Travels     \tNagpur To Delhi        \tRs.3400   \t\t9:30  AM");
    printf("\n1007\tMayur Travels        \tNagpur To Mumbai       \tRs.3350   \t\t1:00  PM");
    printf("\n1008\tShree Travels        \tNagpur To Pune         \tRs.3250   \t\t4:00  PM");
    printf("\n1009\tHydrabad Express     \tNagpur To Hydrabad     \tRs.2600  \t\t5:35  PM");
    printf("\n1010\tSouth Express        \tNagpur To Banglore     \tRs.3600   \t\t4:15  PM");

}

void Booking(void)
{
    system("cls");
    system("color 98");
	char confirm;
	int i=0;
	float price;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_Booking.txt","a");
	printf("\t\t-------------------\n");
	printf("\t\tTICKET BOOKING\n");
	printf("\t\t-------------------\n\n");


    printf("\n\t\tEnter Your Name-> ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\n\t\tEnter Number of Passengers-> ");
	scanf("%d",&passdetails.num_seat);

	viewbus();
	printf("\n\n\t\tEnter bus number-> ");
	start1:
	scanf("%d",&passdetails.busno);
	if(passdetails.busno>=1001 && passdetails.busno<=1010)
	{
		price=charge(passdetails.busno,passdetails.num_seat);
		printticket(passdetails.name,passdetails.num_seat,passdetails.busno,price);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\n\t\tConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
	        system("color 98");

		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_seat,passdetails.busno,price);
		printf("\t\t==================");
		printf("\n \t\tBooking Done\n");
		printf("\t\t==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\n\t\tBooking Not Done!\n");
		}
		else
		{
			printf("\n\t\tInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int busno,int num_seat)
{

	if (busno==1001)

	{
		return(3850*num_seat);
	}
	if (busno==1002)
	{
		return(2500*num_seat);
	}
	if (busno==1003)
	{
		return(2450*num_seat);
	}
	if (busno==1004)
	{
		return(2450*num_seat);
	}
	if (busno==1005)
	{
		return(1900*num_seat);
	}
	if (busno==1006)
	{
		return(3400*num_seat);
	}
	if (busno==1007)
	{
		return(3350*num_seat);
	}
	if (busno==1008)
	{
		return(3250*num_seat);
	}
	if (busno==1009)
	{
		return(2600*num_seat);
	}
	if (busno==1010)
	{
		return(3600*num_seat);
	}
}

void printticket(char name[],int num_seat,int busno,float price)
{
	system("cls");
    system("color 0A");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_seat);
	printf("\nBus Number:\t\t%d",busno);
	findbus(busno);
	printf("\nAmount Paid:\t\t%.2f",price);
}

void findbus(int bus_num)
{

	if (bus_num==1001)
	{
		printf("\nBus:\t\t\tPooja Travels");
		printf("\nDestination:\t\tNagpur To Mumbai");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==1002)
	{
		printf("\nBus:\t\t\tDevit Travels ");
		printf("\nDestination:\t\tNagpur To Nashik");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==1003)
	{
		printf("\nBus:\t\t\tHero Travels ");
		printf("\nDestination:\t\tNagpur To Pune");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==1004)
	{
		printf("\nBus:\t\t\tSuper Deluxe ");
		printf("\nDestination:\t\tNagpur To Hydrabad");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==1005)
	{
		printf("\nBus:\t\t\tSai Baba Travels ");
		printf("\nDestination:\t\tNagpur To Cheenai");
		printf("\nDeparture:\t\t7am");
	}
	if (bus_num==1006)
	{
		printf("\nBus:\t\t\tShine On Travels ");
		printf("\nDestination:\t\tNagpur To Delhi ");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (bus_num==1007)
	{
		printf("\nBus:\t\t\tMayur Travels");
		printf("\nDestination:\t\tNagpur To Mumbai ");
		printf("\nDeparture:\t\t1pm ");
	}
	if (bus_num==1008)
	{
		printf("\nBus:\t\t\tShree Travels ");
		printf("\n Destination:\t\tNagpur To Pune");
		printf("\nDeparture:\t\t4pm ");
	}
	if (bus_num==1009)
	{
		printf("\nBus:\t\t\tHydrabad Express");
		printf("\nDestination:\t\tNagpur To Hydrabad");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (bus_num==1010)
	{
		printf("\nBus:\t\t\tSouth Express");
		printf("\nDestination:\t\tNagpur To Banglore");
		printf("\nDeparture:\t\t1.15 ");
	}
}
