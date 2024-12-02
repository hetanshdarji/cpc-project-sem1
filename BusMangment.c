#include <stdio.h>
void detail()
{
  FILE *detail;
  detail = fopen("detail.txt", "w");
  if (detail == NULL)
  {
    printf("File Not Found");
  }
  char Username[50], Password[50];
  printf("Enter User Name:");
  scanf(" %s", &Username);
  printf("Enter User Password:");
  scanf(" %s", &Password);
  fprintf(detail, "Username:- %s\n", Username);
  fprintf(detail, "Password:- %s\n", Password);
  fclose(detail);
}

void Menu()
{
  while (1)
  {
    int choice, booking;
    FILE *file;
    char TrainInfromation[100];

    file = fopen("bus.txt", "r");
    if (file == NULL)
    {
      printf("File Not Found");
      break;
    }
    printf(":=Main Menu=:\n");
    printf("1 Book Bus Ticket\n");
    printf("2 Cancel The Ticket\n");
    printf("3 Exit\n");
    printf("Make Your Choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("Which bus\n");
      while (fgets(TrainInfromation, 100, file))
        printf(" %s", TrainInfromation);
      printf("\nEnter The Sr Number for book:");
      scanf("%d", &booking);
      printf("Thank You for Booking\n");

      break;
    }
    else if (choice == 2)
    {
      printf("No Ticket Book\n");
      break;
    }
    else if (choice == 3)
    {
      break;
    }
    else if (choice >= 4)
    {
      printf("\nInvaid choice");
    }

    fclose(file);
  }
}
int main()
{

  int login;
  char phone[10];
  char email[30];
  while (1)
  {
    printf(":=Main Menu=:\n");
    printf("1 Login\n");
    printf("2 Create A Account\n");
    printf("3 Exit\n");
    printf("Make Your Choice:");
    scanf("%d", &login);
    if (login == 1)
    {

      detail();
      printf("**Login Successfully**\n");
      Menu();
      break;
    }

    else if (login == 2)
    {

      detail();
      FILE *detail;
      detail = fopen("detail.txt", "a");
      printf("Enter Your Mobile Number:");
      scanf(" %s", &phone);
      printf("Enter Your Email: ");
      scanf(" %s", &email);
      fprintf(detail, "Mobile:- %s\n", phone);
      fprintf(detail, "Email:- %s\n", email);
      printf("**Acccount Created Successfully\n**");
      fclose(detail);
      Menu();
      break;
    }
    else if (login == 3)
    {
      break;
    }
    else if (login >= 4)
    {
      printf("Invaild choice\n");
    }
  }
  return 0;
}
