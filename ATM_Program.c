/*
Program Description: This is a simple menu driven C program that enables bank customers to manage, verify,
change their Personal Identification Number (PIN) on an Automated Teller Machine (ATM).
The PIN must be 4 digits or else the user is given an appropriate error message.
User also has the option to exit the program gracefully at will fromm within the program.

Development Environment: this program was developed in Visual Studio Code.

Author: Habeeb Alao

Date: 04/11/2020     Modified: 20/11/2020
*/
#include <stdio.h>
#include <stdbool.h>
#define PIN_LENGTH 4
#define BASE10_LENGTH 10

int main(void)
{
     /* 
     initializing and assigning users actual pin,
     temporary pin variables for pin change process 
     */
     char option;
     char spaceholder[1] = {'x'};
     char base10_numbers[BASE10_LENGTH] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
     char actual_pin[PIN_LENGTH] = {'1', '2', '3', '4'};
     char temp_pin1[5] = {'0', '0', '0', '0', '0'};
     char temp_pin2[PIN_LENGTH] = {'0', '0', '0', '0'};
     char entered_pin[PIN_LENGTH] = {'0', '0', '0', '0'};
     //initialize counter variables for both succesful and incorrect incput. i and a are assigned value later within for loops.
     int entered_successful = 0;
     int entered_incorrect = 0;
     int i;
     int a;
     //boolean variables are initised and assigned initial value wchich change through out the program, and get reset before the end of the while loop.
     bool PIN_checker = true;
     bool verification = true;
     bool match = true;

     //menu is guaranteed to show aleast once when booted up.
     do
     {//do while loop starts.
          //Main menu is displayed to the user. they are given 4 option and they are given an option to selcet one of them.

          printf("\nWelcome to 🦄🟣The Purple Unicorn Bank🟣🦄 ATM\n\n");
          printf("  1 • Enter PIN and verify correct\n");
          printf("  2 • Change Pin \n");
          printf("  3 • Display number of times PIN was entered\n");
          printf("  4 • Exit Program\n\n");

          //ask user to selcet an option from the main menu using one of the four complimentary numbers.
          printf("Enter an option from the menu above then press the enter key:  ");
          scanf("%c", &option);
          //place holder is required so that the enter button pressed dosent interfere with pin entry.
          scanf("%c", &spaceholder[0]);
          printf(" \n\n\n");

          switch (option)
          {
               //if user selects option 1 they are brought to this section of the switch statment.
               case '1':
               { //start case '1'
                    //If option 1 is selected the program then asks the user to enter their PIN.
                    printf("Please enter your pin: \n");
                    for (i = 0; i < PIN_LENGTH; i++)
                    {
                         scanf("%1s", &entered_pin[i]);
                    }

                    //program checks if the  the PIN the user entered matches the existing assigned PIN thats on file.
                    for (i = 0; i < PIN_LENGTH; i++)
                    {
                         if (actual_pin[i] != entered_pin[i])
                         {
                              printf("PIN Entered is incorrect\n");
                              printf("Redirecting to Main Menu...\n\n");
                              entered_incorrect = entered_incorrect + 1;
                              match = false;
                              break;
                         }
                    }
                    if (match == true)
                    {
                         //if the PIN the user entered matches the on on file it it will display a "PIN Authenticated" message and the entered_succesful counter will increase by an incriment of 1.
                         entered_successful = entered_successful + 1;
                         printf("PIN entered was correct\n");
                         printf("PIN Authenticated\n\n\n");
                         printf("Redirecting to Main Menu...\n\n\n");
                         break;
                    }
                    //match boolean variable is reset before next run of do while loop.
                    match = true;
                    break;
               } //end case '1'
               case '2':
               {//start case '2'
                    //If option 2 is selected the program then asks the user to enter their new PIN in its entirety, if the user dosent do this and presses enter to early or any other charascter the program will check and give an appropriate response.
                    //asks user to enter new PIN.
                    printf("Enter your complete new PIN then press enter:\n");
                    for (i = 0; i < 5; i++)
                    {    // user MUST enter numbers for first four elements of temp pin array or the user will be given an error, because the program checks if the characters entered are a subset of the base10 numbers, else the pin change process wont go ahead.
                         scanf("%c", &temp_pin1[i]);
                    }
                    for (i = 0; i < PIN_LENGTH; i++)
                    {
                         for (a = 0; a < BASE10_LENGTH; a++)
                         {
                              if (base10_numbers[a] == temp_pin1[i])
                              {//as soon as a match is found within the base10 number array the program immediatly moves to the next temporary pin digit
                                   PIN_checker = true;
                                   break;
                              }
                              else
                              {//otherwise the program will turn the pin checker boolean to false meaning a character outside those allowed (base10 numbers) was entered.
                                   PIN_checker = false;
                              }
                         }//program will end for loop as soon as a digit outside those in the base10 number array, as there no point checkong the rest because it dosen't meet 4 numeric digit criteria set out.
                         if (PIN_checker == false)
                         {
                              break;
                         }
                    }
                    if (PIN_checker == true && temp_pin1[4] == '\n')
                    {//if all the first 4 digits in the users new pin lay within the parameters of base 10 numbers then the user may continue to the re-entry confirmation stage of the setting new pin process.
                    //only way to get to this stage is if and only if user enters 4 base10 digits then presses enter after.
                         printf("Please re-enter to confirm your new PIN :\n");
                         for (i = 0; i < 3; i++)
                         {//user asked to enter new pin
                              scanf("%1s", &temp_pin2[i]);

                              if (temp_pin2[i] != temp_pin1[i])
                              {//user is shown an error if it finds a mismatch match of any kind, and then verification proces becomes void or false immediately.
                                   printf("error: your new PIN didn't match\n");
                                   printf("We couldn't confirm your new PIN\n\n");
                                   printf("Redirecting to Main Menu...\n\n");
                                   verification = false;

                                   break;
                              }
                              else
                              {//if no mismatches are found the verification process is true or succuesful and new pin will be set.
                                   verification = true;
                              }
                         }
                    }
                    else
                    {//if an input error of any kind that dosen't match parameters, users verification status changes to false 
                         PIN_checker = false;
                    }
                    if (PIN_checker == false)
                    {//user is shown and appropiate error message if new PIN entered doesnt't meet the set out requirements.
                         printf("Your new PIN didn't meet our 4 nemeric digit PIN criteria\n\n");
                    }
                    else if (verification == false)
                    {//user is shown an error message if verification process has any mismatch or inputs outside set parameters.
                         printf("PIN entered couldnt be verified\n\n");
                         printf("Redirecting to Main Menu...\n\n");
                    }
                    else if (verification == true && PIN_checker == true)
                    {//new PIN is set as default PIN if all if and only if first temp_pin1 meets requirements, then no miss match was found in the first four didgits of the first temp_pin1 and the first four digits in the first four digitds of temp_pinq2 if and only if this happens the new pin will be assigned to the the users default pin.
                         for (i = 0; i < PIN_LENGTH; i++)
                         {
                              actual_pin[i] = temp_pin1[i];
                         }
                         printf("PIN entered has been verified\nNew PIN has been set\n\n");
                         printf("Redirecting to Main Menu...\n\n");
                    }
                    else
                    {
                         for (i = 0; i < PIN_LENGTH; i++)
                         {// the users pin will remain the same and the program will display an appropriate "PIN will remain the same" message.
                              actual_pin[i] = actual_pin[i];
                              printf("PIN will remain the same");
                         }
                    }
                    //all PIN verification booleans are reset after this process to make sure preveous settings don't interfere with it in the future.
                    PIN_checker = true;
                    verification = true;
                    break;
               }//end case '2'
               case '3':
               { //start case '3'
                    //If option 3 is selected the program then displays how many times the pin was entered succesfully and incorrectly.
                    //program display the number of times the user entered their PIN succesfully and incorrectly.
                    printf("Your PIN was entered %d times Succesfully\n", entered_successful);
                    printf("Your PIN was entered %d times Incorrectly\n\n", entered_incorrect);
                    printf("Redirecting to Main Menu...\n\n");
                    break;
               }
               case '4':
               { //start case '4'
                    //If option 4 is selected the program exits gracefully.
                    //exits the program gracefully by breaking the while loop and turninng the ATM off once option == '4'.
                    printf("You have now exited the program,\n");
                    printf("Good Bye :( \n");
                    printf("ATM is now offline");
                    break;
               } //end case.
               default:
               {
                    //if the user enters an option outside of the Mina Menu parameters the user will be shown an appropriate error Message.
                    printf("error: ivalid option selection");
                    printf("\n\n");
               }
          } //end switch.
          //clears all inputed data before next run. so preveous inputed data wont interfere with new inputed data.
          fflush(stdin);
          //this menu will rerun forever unless the user enters option 4.
     } while (option != '4');
     //program ends.
     return 0;
}