#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
int main()
{
    printf("\n                  *VGA DIGITAL PRINTERS PVT. LTD.*");
    printf("\n                          *CASH REGISTRY*");
    //time
	time_t s,val=1;
	struct tm* current_time;
	s=time(NULL);
	current_time=localtime(&s);
	printf("\n\n    Time = %02d : %02d : %02d",current_time->tm_hour,current_time->tm_min,current_time->tm_sec);

	//name
	char name[100];
	printf("\n\n    Enter your name : ");
	scanf("%s",&name);
	//cash calculation
	long int n1, n2, i, tcrec = 0, tcpay = 0, pcash = 0;
    printf("\n\n    Enter the opening cash : "); //opening cash
	scanf("%d", &pcash);
    printf("\n\n    Enter the number of cash received entries : "); //number of cash received entries
	scanf("%d",&n1);
    printf("\n\n    Enter the number of cash payment entries :  "); //number of cash payment entries
	scanf("%d",&n2);
	long int crec[n1], cpay[n2];
    printf("\n    Enter the cash received entries :\n");
	for(i=0;i<n1;i++) //loop for cash received
    {
	    printf("\n        %d : ",i+1);
    	scanf("%d",&crec[i]);
    }
	for(i=0;i<n1;i++) // summation of cash received
    {
    	tcrec = tcrec + crec[i];
    }
    printf("\n    Enter the cash payment entries : \n");
	for(i=0;i<n2;i++) // loop for cash payment
    {
    	printf("\n        %d : ",i+1);
        scanf(" %d",&cpay[i]);
    }
	for(i=0;i<n2;i++) // summation of cash paid
    {
        tcpay = tcpay + cpay[i];
	}
	printf("\n\n    Total cash received is  : %d", tcrec);
	printf("\n\n    Total cash paid is : %d", tcpay);
    tcrec = tcrec - tcpay;
	//calculation of whether cash paid or received
	if(tcrec<0)
	{
    	printf("\n\n       Nett cash paid : %d", -tcrec);
	}
	else if(tcrec>0)
	{
    	printf("\n\n    Nett cash received : %d", tcrec);
	}
	//ideal cash
	pcash = pcash + tcrec;
	printf("\n\n    Ideal cash : %d",pcash);
	//cash in box calculation
	long int a2k = 0, a5h = 0, a2h = 0, a1h = 0, a5t = 0, a2t = 0, a1t = 0, total = 0, bal = 0;
	printf("\n\n\n\n                   Number of Rs.2000 notes : ");
	scanf("%d",&a2k);
	printf("\n                   Number of Rs.500 notes  : ");
	scanf("%d",&a5h);
	printf("\n                   Number of Rs.200 notes  : ");
	scanf("%d",&a2h);
	printf("\n                   Number of Rs.100 notes  : ");
	scanf("%d",&a1h);
	printf("\n                   Number of Rs.50 notes   : ");
	scanf("%d",&a5t);
	printf("\n                   Number of Rs.20 notes   : ");
	scanf("%d",&a2t);
	printf("\n                   Number of Rs.10 notes   : ");
	scanf("%d",&a1t);
	
	system("CLS");
	system("COLOR E");
    printf("\n\tLOADING YOUR RECORD ... \n");
    for(i=0;i<=100;i++)
	{
        printf("%c",219);
        Sleep(50);
    }
    Sleep(2000);
    system("CLS");
	system("COLOR 7");
	
	//now printing values
		printf("\n\n\n                  DENOMINATION       NOTES  AMOUNT");
		printf("\n\n                       2000		 %d	 %d	 ",a2k,2000*a2k);
		printf("\n\n                       500		 %d	 %d	 ",a5h,500*a5h);
		printf("\n\n                       200		 %d	 %d	 ",a2h,200*a2h);
		printf("\n\n                       100		 %d	 %d	 ",a1h,100*a1h);
		printf("\n\n                       50		 %d	 %d	 ",a5t,50*a5t);
		printf("\n\n                       20		 %d	 %d	 ",a2t,20*a2t);
		printf("\n\n                       10		 %d	 %d	 ",a1t,10*a1t);

	//calculating total cash
	total = 2000*a2k + 500*a5h + 200*a2h + 100*a1h + 50*a5t + 20*a2t + 10*a1t;
	//printing total cash in box;
	printf("\n\n                   CASH IN BOX	 =	 %d",total);
	//balance
    bal = total - pcash;
    if(bal>0)
    {
        system("COLOR C");//console color turns red if error in tally.
		printf("\n\n                   Excess cash  =  %d/-",bal);
    }
	else if(bal<0)
    {
	    system("COLOR C");//console color turns red if error in tally.
		bal = -bal;
    	printf("\n\n                   Short cash  =  (-) %d/-",bal);
    }
    else
    {
    	system("COLOR A");//console color turns green if no error in tally.
		printf("\n\n                   - No Errors in Tally. Funds Checked, All OK. -");
		printf("\n\n                   - Have A Nice Day, %s . Goodbye. -\n\n",name);
	}

	return 0;
}
