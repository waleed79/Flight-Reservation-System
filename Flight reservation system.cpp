#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

    const int size=1000; //globally declared array size
    int counter_dom=0;//counter to keep a check on number of entries in domestic database arrays
    int counter_int=0;//counter to keep a check on number of entries in international database arrays
    //globally declared arrays to store data of previous reservations for domestic flight
    string flight_day[size],flight_dom[size], passenger_name_dom[size], airline_dom[size], airline_code_dom[size],
	time_dom[size], passenger_passport_no_dom[size], passenger_phone_no_dom[size];
	//globally declared arrays to store data of international passengers
	string flight_day_int[size],flight_int[size], passenger_name_int[size], airline_int[size], airline_code_int[size],
	time_int[size], passenger_passport_no_int[size], passenger_phone_no_int[size];


int main();
/*
This function allows us to save a lot of space, how? we just need to send it minimum and maximum range of input user can
enter and it would get us, just that.
*/
int validation(int min, int max)
{
int validation=0;
int option;
            do//loop to get answer in the desired range
            {
                cout<<endl;
                cout<<"Please enter your choice: ";
                cin>>option;
                if(cin.fail())
            {
                cout<<"Please enter an integer";
                validation++;
            }
                else if(option<min || option>max)
            {
                    validation++;
            }
                else
                    validation=0;
            }
            while(validation != 0);
	return option;//returning user input to the function that called for validation
}
/*
This function would allow us to retrieve user data of domestic flights and store it in arrays. This would help us to access
the data in cancel a flight and checking a reserved flight function
*/
void domestic_data()
{
    ifstream Flightreservation_domestic("flightreservation_domestic.txt");//calling input file stream to copy data from it.
    while(Flightreservation_domestic.good()) //loop to store all the domestic flight data in arrays
    {
        //getline is used to store line by line as data is store in the same order
        getline(Flightreservation_domestic, flight_day[counter_dom]);
        getline(Flightreservation_domestic, flight_dom[counter_dom]);
        getline(Flightreservation_domestic, airline_dom[counter_dom]);
        getline(Flightreservation_domestic, airline_code_dom[counter_dom]);
        getline(Flightreservation_domestic, time_dom[counter_dom]);
        getline(Flightreservation_domestic, passenger_name_dom[counter_dom]);
        getline(Flightreservation_domestic, passenger_phone_no_dom[counter_dom]);
        getline(Flightreservation_domestic, passenger_passport_no_dom[counter_dom]);
        counter_dom++;
    }
}
/*
This function would allow us to retrieve user data of international flights and store it in arrays. This would help us to access
the data in cancel a flight and checking a reserved flight functions.
*/
void international_data()
{

    ifstream Flightreservation_international("flightreservation_international.txt");//inputting from a file
    while(Flightreservation_international.good())//loop to store international passengers data
    {
        //getline is used to store line by line as data is store in the same order
        getline(Flightreservation_international, flight_day_int[counter_int]);
        getline(Flightreservation_international, flight_int[counter_int]);
        getline(Flightreservation_international, airline_int[counter_int]);
        getline(Flightreservation_international, airline_code_int[counter_int]);
        getline(Flightreservation_international, time_int[counter_int]);
        getline(Flightreservation_international, passenger_name_int[counter_int]);
        getline(Flightreservation_international, passenger_phone_no_int[counter_int]);
        getline(Flightreservation_international, passenger_passport_no_int[counter_int]);
        counter_int++;
    }
}
/*
This is the front page function which will be displayed on the terminal window having four options for the passengers to decide
and select from. As the user inputs his choice, there will a special validation which will ensure that the user input is
correct and following the required parameters
*/
int front_page()
{
    int option;//to input user choice
    cout<<"\n";
    cout<<"\t\t\t\t\t   FLIGHT RESERVATION SYSTEM"<<endl;
    cout<<"\t\t\t\tA convenient way of booking your airline tickets!"<<endl;
    cout<<"\t\t\t\t    ";
    for(int i=0; i<40;i++)//loop to print asteriks
        cout<<"*";
    cout<<endl;
    cout<<"1) Book a flight"<<endl;
    cout<<"2) Check a reserved flight"<<endl;
    cout<<"3) Random selection"<<endl;  // This is covering innovation part of rubric
    cout<<"4) Cancel a flight"<<endl;
    option=validation(1,4);    //If user input is wrong it will ask again for correct user input
    return option;//return user option to main function

}
/*
The function below is used for getting user input from the passenger for inputting in our
system in order to store in file made for domestic travelers and calling back when needed
for use in other functions in our program.
*/
void ticket_data_domestic()
{
    char passenger_name[100];
    string  fname, lname,passenger_phone_no,passenger_passport_no;
    //outputting passenger data in a file, so opening that file for output in the file
    ofstream Flight_reservation_domestic("flightreservation_domestic.txt", fstream::app);
    //getting input from user
    cout<<"Passenger name: ";
    cin.ignore();
    cin.getline(passenger_name, 100);
    while(atoi(passenger_name)!=0)//atoi returns number of integers converted
    {
        cout<<"Passenger name: ";
        cin.ignore();
        cin.getline(passenger_name, 100);
    }
    cout<<"Passenger phone number(without dashes): ";
    cin>>passenger_phone_no;
    cout<<"Passenger passport number): ";
    cin>>passenger_passport_no;
    //outputting passenger data on text file
    Flight_reservation_domestic<<passenger_name<<endl<<passenger_phone_no<<endl
                               <<passenger_passport_no<<"\n";
    Flight_reservation_domestic.close();
    system("CLS");
    cout<<"\n\n\nThank You for using our service.\nYour ticket is BOOKED!!"<<endl;
    cout<<"Do you want to continue? (Yes/No): ";
    string choice;
    cin>>choice;
    //allowing user to continue or stop
    if(choice=="Yes" || choice=="yes")
    {
        system("CLS");
        main();
    }
    else
        return ;
}
/*The function below is used for getting user input from the passenger for inputting
in our sytem in order to store in file made for international travellers and calling
 back when needed for implementing other functions in our program*/
void ticket_data_international()
{
    char passenger_name[100];
    string passenger_phone_no,passenger_passport_no;
    //outputting passenger data in a file, so opening that file for output in the file
    ofstream Flight_reservation_international("flightreservation_international.txt", fstream::app);
    cout<<"Passenger name: ";
    cin.ignore();
    //getting input from user
    cin.getline(passenger_name, 100);
    while(atoi(passenger_name)!=0)//atoi returns number of integers converted
    {
        cout<<"Passenger name: ";
        cin.ignore();
        cin.getline(passenger_name, 100);
    }
    cout<<"Passenger phone number(without dashes): ";
    cin>>passenger_phone_no;
    cout<<"Passenger passport number: ";
    cin>>passenger_passport_no;
    //outputting user data on text file
    Flight_reservation_international<<passenger_name<<endl
                                    <<passenger_phone_no<<endl<<passenger_passport_no<<"\n";
    Flight_reservation_international.close();
    system("CLS");
    cout<<"\n\n\nThank You for using our service.\nYour ticket is BOOKED!!\nHave a safe journey."<<endl;
    cout<<"Do you want to continue? (Yes/No): ";
    string choice;
    cin>>choice;
    //allowing user to continue or stop
    if(choice=="Yes" || choice=="yes")
    {
        system("CLS");
        main();
    }
    else
        return ;
}
/*This function below is going to take user input for different travelling facilities
 available for the passenger internationally along with the timings. It provides our users an array of
 opportunities to travel with us */
void airline_generator_international()
{
    int option;
    string airline[4];
    string airline_code[4];
    string time1[4];
    system("CLS");
    ofstream Flight_reservation_international("flightreservation_international.txt", fstream::app);

	airline[0]="British Airways";
	airline[1]="Emirates";
	airline[2]="Qatar Airways";
    airline[3]="Air Sial";

    airline_code[0]="BA 212";
	airline_code[1]="E 323";
	airline_code[2]="QA 522";
	airline_code[3]="AS321";

	time1[0]="8:30 am";
	time1[1]="11:00 am";
	time1[2]="4:30 pm";
	time1[3]="9:45 pm";

    for (int i=0;i<4;i++)
    {
        cout<<i+1<<") ";
        cout<<airline[i]<<endl;
        cout<<airline_code[i]<<endl;
        cout<<time1[i]<<endl;
        cout<<endl;
    }
    option=validation(1,4); // this offers validation to ensure that our user inputs the correct choice.
        //upon getting input from user, we are storing that data in text file according to the choice user makes
        if(option==1)
        {
            Flight_reservation_international<<airline[0]<<endl<<airline_code[0]<<endl<<time1[0]<<endl;
        }
        else if(option==2)
        {
            Flight_reservation_international<<airline[1]<<endl<<airline_code[1]<<endl<<time1[1]<<endl;
        }
        else if(option==3)
        {
            Flight_reservation_international<<airline[2]<<endl<<airline_code[2]<<endl<<time1[2]<<endl;
        }
        else if(option==4)
        {
            Flight_reservation_international<<airline[3]<<endl<<airline_code[3]<<endl<<time1[3]<<endl;
        }
    Flight_reservation_international.close();
    ticket_data_international();
}
/*This function below is going to take user input for different travelling facilities
available for the passenger domestically along with the timings. It provides our users an array of
opportunities to travel with us */
void airline_generator_domestic()
{
    system("CLS");
    int option;
    ofstream Flight_reservation_domestic("flightreservation_domestic.txt", fstream::app);
    string airline[4];    //We are using four airlines in our reservation system hence array stores a maximum of 4
    string airline_code[4];
    string time1[4];

        airline[0]="PIA";
        airline[1]="Air Blue";
        airline[2]="Qatar Airways";
        airline[3]="Air Sial";

        airline_code[0]="PK212";
        airline_code[1]="A1323";
        airline_code[2]="QA522";
        airline_code[3]="AS321";

        time1[0]="8:30 am";
        time1[1]="11:00 am";
        time1[2]="4:30 pm";
        time1[3]="9:45 pm";

    for(int i=0;i<4;i++)    //A for loop is used to print on screen
    {
        cout<<i+1<<") ";
        cout<<airline[i]<<endl;
        cout<<airline_code[i]<<endl;
        cout<<time1[i]<<endl;
        cout<<endl;
    }
    option=validation(1,4);   //These 4 options help us in validation process resulting in improved efficacy
    //upon getting input from user, we are storing that data in text file according to the choice user makes
    if(option==1)
    {
        Flight_reservation_domestic<<airline[0]<<endl<<airline_code[0]<<endl<<time1[0]<<endl;
    }
    else if(option==2)
    {
        Flight_reservation_domestic<<airline[1]<<endl<<airline_code[1]<<endl<<time1[1]<<endl;
    }
    else if(option==3)
    {
        Flight_reservation_domestic<<airline[2]<<endl<<airline_code[2]<<endl<<time1[2]<<endl;
    }
    else if(option==4)
    {
        Flight_reservation_domestic<<airline[3]<<endl<<airline_code[3]<<endl<<time1[3]<<endl;
    }
    //closing text file to prevent store of any junk value
    Flight_reservation_domestic.close();
    //calling ticket function to get passenger information
    ticket_data_domestic();

}
// This function below offers us an opportunity to book domestic flights
void book_flight_domestic()
{
    ofstream Flight_reservation_domestic("flightreservation_domestic.txt", fstream::app);
    int a,b, option2;
    string city,city1,city2, flight_date[6];
    flight_date[0]="Friday, 1st January, 2021";
    flight_date[1]="Saturday, 2nd January, 2021";
    flight_date[2]="Sunday, 3rd January, 2021";
    flight_date[3]="Monday, 4th January, 2021";
    flight_date[4]="Tuesday, 5th January, 2021";
    flight_date[5]="Wednesday, 6th January, 2021";
    flight_date[6]="Thursday, 7th January, 2021";
    cout<<"\n\n";
    for(int k=0;k<7;k++)
    {
        cout<<k+1<<") "<<flight_date[k]<<endl;
    }
    option2=validation(1,7);
    Flight_reservation_domestic<<flight_date[option2-1]<<endl;
    system("CLS");
    cout<<"\t\t\t\tWelcome to Flight reservation for domestic flights\n\n"<<endl;
    //Our system covers the major cities of Pakistan which have proper airports to fly
          cout<<"Available cities for departure\n\n";
          cout<<"  Departure Cities"<<endl;
          cout<<"1.Lahore"<<endl;
          cout<<"2.Islamabad"<<endl;
          cout<<"3.karachi"<<endl;
          cout<<"4.Quetta"<<endl;
          cout<<"5.Peshawar"<<endl;

          a=validation(1,5);

          switch(a)   //switch statemenets are used to improve the efficacy of our program.
          {
          case 1: city1="Lahore";
          break;
          case 2: city1="Islambad";
          break;
          case 3: city1="Karachi";
          break;
          case 4: city1="Quetta";
          break;
          case 5: city1="Peshawar";
          break;
          }

          cout<<"  Arrival Cities"<<endl;
          cout<<"1.Lahore"<<endl;
          cout<<"2.Islamabad"<<endl;
          cout<<"3.karachi"<<endl;
          cout<<"4.Quetta"<<endl;
          cout<<"5.Peshawar"<<endl;

          b=validation(1,5);
          while(a==b)//to make sure that departure and arrival cities are different
          {
                cout<<"Departure"<<endl;
                a=validation(1,5);
                cout<<"Arrival"<<endl;
                b=validation(1,5);
          }
          switch(b)   //switch statements are used to improve the efficacy of our program.
          {
          case 1: city2="Lahore";
          break;
          case 2: city2="Islamabad";
          break;
          case 3: city2="Karachi";
          break;
          case 4: city2="Quetta";
          break;
          case 5: city2="Peshawar";
          break;
          }
        city=city1+" to "+city2;
        Flight_reservation_domestic<<city<<endl;
        Flight_reservation_domestic.close();
        airline_generator_domestic();
}
/*
Function to book international flights.
User would be asked to enter departure city and arrival city.
Explanation:
This function would first display dates and ask for user input, then move to next screen, and displays several cities of
departure and arrival to the user. User can then select the cities of their choice.The user preference would be stored in
string variables using switch statements. In the later part, the user place of departure and arrival are stored into a text
file and finally, another function is called that would print out available flights.
*/
void book_flight_international()
{
    ofstream Flight_reservation_international("flightreservation_international.txt", fstream::app);
    //calling output file stream to enter user data into text file to store it permanently and access it later
        string city, city1, city2, flight_date1[6]; //variables to store departure and arrival cities
        int c,d, option2; //integers to stores user input
        //storing dates in array
        flight_date1[0]="Friday, 1st January, 2021";
        flight_date1[1]="Saturday, 2nd January, 2021";
        flight_date1[2]="Sunday, 3rd January, 2021";
        flight_date1[3]="Monday, 4th January, 2021";
        flight_date1[4]="Tuesday, 5th January, 2021";
        flight_date1[5]="Wednesday, 6th January, 2021";
        flight_date1[6]="Thursday, 7th January, 2021";
        cout<<"\n\n";
        for(int k=0;k<7;k++)//loop to print dates available for travel
        {
            cout<<k+1<<") "<<flight_date1[k]<<endl;
        }
        option2=validation(1,7);//calling validation function for user prefered date
        Flight_reservation_international<<flight_date1[option2-1]<<endl;//save date in text file
        system("CLS");//to clear screen
        cout<<"\t\t\t\tWelcome to Flight Reservation for 'International Flights'\n\n"<<endl;
        cout<<"Available cities for departure\n\n";
        //printing available cities for departure on screen
        cout<<"  Departure Cities"<<endl;
        cout<<"1.Lahore"<<endl;
        cout<<"2.Karachi"<<endl;
        cout<<"3.Islamabad"<<endl;
        cout<<"4.New York"<<endl;
        cout<<"5.London"<<endl;
        cout<<"6.Sydney"<<endl;
        cout<<"7.Berlin"<<endl;
        cout<<"8.Toronto"<<endl;
        cout<<endl;
        c=validation(1,8); //taking input from user by calling validation function
        cout<<endl;

        switch(c) //switch statement to store user departure city
        {
            case 1: city1="Lahore";
            break;
            case 2: city1="Karachi";
            break;
            case 3: city1="Islamabad";
            break;
            case 4: city1="New York";
            break;
            case 5: city1="London";
            break;
            case 6: city1="Sydney";
            break;
            case 7: city1="Berlin";
            break;
            case 8: city1="Toronto";
            break;
        }
        //printing available cities for arrival on screen
        cout<<"  Arrival Cities"<<endl;
        cout<<"1.Lahore"<<endl;
        cout<<"2.Karachi"<<endl;
        cout<<"3.Islamabad"<<endl;
        cout<<"4.New York"<<endl;
        cout<<"5.London"<<endl;
        cout<<"6.Sydney"<<endl;
        cout<<"7.Berlin"<<endl;
        cout<<"8.Toronto"<<endl;
        cout<<endl;
        d=validation(1,8); //calling validation function to take input
        while(c==d) //making sure that same city is not selected as departure and arrival
        {
                cout<<"Departure"<<endl;
                c=validation(1,8);
                cout<<"Arrival"<<endl;
                d=validation(1,8);
        }
        switch(d) //switch statement to store user's arrival city
        {
            case 1: city2="Lahore";
            break;
            case 2: city2="Karachi";
            break;
            case 3: city2="Islamabad";
            break;
            case 4: city2="New York";
            break;
            case 5: city2="London";
            break;
            case 6: city2="Sydney";
            break;
            case 7: city2="Berlin";
            break;
            case 8: city2="Toronto";
            break;
        }
        cout<<endl;
        city=city1+" to "+city2; //concatenating strings to help us store only one variable in file and simplifying things
        Flight_reservation_international<<city<<endl; //storing data in text file (using file handling here)
        Flight_reservation_international.close(); //closing text file to prevent dumping of data into it
        airline_generator_international(); //calling function to generate and display international flights available
}
/*
Function to book national and international flight.
This function is linked to many other functions above.
Explanation:
At the start, user will be presented with the option to book domestic or international flights, or to go back on previous page.
Upon entering the input, it would be validated, and then according to the user preference, book flight function would redirect
to the relevant functions above.
*/
void book_flight()
{
    system("CLS"); //to clear screen
        cout << "\n\n(1)Domestic Fights \n(2)International Flights\n(3)Back" << endl; //option presented to user to select from
        int option_book_flight; //variable to store user choice
        option_book_flight=validation(1,3); //calling validation function to make sure correct input is entered
        system("CLS"); //to clear screen
        if(option_book_flight==1)
        //to book a domestic flight
        {
            book_flight_domestic(); //calling booking function for domestic flights
        }
        else if(option_book_flight==2)
        //to book an international flight
        {
            book_flight_international(); //calling booking function for international flights
        }
        else if(option_book_flight==3)
        //to get back to the main screen
        {
            system("CLS"); //to clear screen
            main(); //allowing user to go back on previous screen (that was main function)
        }

}
//a function to help user check their reserved flight
/*
The function would ask user to enter their passport number and then would check in the database for the passenger information
registered against that passport. Then, it would print out the respective ticket on screen. User can also choose to continue
to use the program or quit.

*/
void check_reserved_flight()
{
    system("CLS"); //to clear main screen
              int option; //to store user input
              cout << "\n\n(1)Domestic Fights \n(2)International Flights\n(3)Back" << endl;
              //presenting user with a choice
              option=validation(1,3);  //validating user input
              if (option==1)//to check domestic reserved flight
              {
                  system("CLS");
                  string passport_num;//asking user for passenger passport number
                  int i=0, k=0;
                  cout<<"\n\n\nPlease enter passenger passport number. ";
                  cin>>passport_num;//inputting passport number
                  bool flag=false;//bool to check if passport matches or not
                  for(i; i<size; i++)//looping through all passport numbers in domestic text file
                  {
                      //comparing strings, by using strcmp function
                      if(strcmp(passport_num.c_str(),passenger_passport_no_dom[i].c_str())==0)
                      {
                          k=i;//saving index of passport number that matches
                          flag=true;
                          break;//break out of loop in case passport number matches
                      }
                  }
                  if(flag==false)//display error in case passport number doesn't match
                      {
                          cout<<"Invalid passport number, please try again.";
                          system("CLS");
                          main();
                      }
                  //printing out detail of passenger in case passport number matches
                  cout<<"\n\n\nYour reserved flight is:\n";
                  cout<<"Day: "<<flight_day[k]<<endl;
                  cout<<"Flight: "<<flight_dom[k]<<endl;
                  cout<<"Name: "<<passenger_name_dom[k]<<endl;
                  cout<<"Airline: "<<airline_dom[k]<<endl;
                  cout<<"Code: "<<airline_code_dom[k]<<endl;
                  cout<<"Time: "<<time_dom[k]<<endl;
                  cout<<"Passport no.: "<<passenger_passport_no_dom[k]<<endl;
                  cout<<"Phone no.: "<<passenger_phone_no_dom[k]<<endl;
                  cout<<"\n\n\nDo you wish to continue? (Yes/No): ";
                  string choice;
                  cin>>choice;
                  //user can continue or quit
                  if(choice=="Yes" || choice=="yes")
                  {
                        system("CLS");
                        main();
                  }
                  else
                        return ;
                  }

              if (option==2)//to check international reserved flight
              {
                  system("CLS");
                  string passport_num;//asking user for passenger passport number
                  int i=0, k=0;
                  cout<<"\n\n\nPlease enter passenger passport number. ";
                  cin>>passport_num;//inputting passport number
                  bool flag=false;//bool to check if passport matches or not
                  for(i; i<size; i++)//looping through all passport numbers in international text file
                  {
                      //comparing strings, by using strcmp function
                      if(strcmp(passport_num.c_str(),passenger_passport_no_int[i].c_str())==0)
                      {
                          k=i;//saving index of passport num that matches
                          flag=true;
                          break;
                      }
                  }
                  if(flag==false)
                      {
                          cout<<"Invalid passport number, please try again.";
                          system("CLS");
                          main();
                      }
                  //outputting ticket information for passport number that matches
                  cout<<"\n\n\nYour reserved flight is:\n";
                  cout<<"Date: "<<flight_day_int[k]<<endl;
                  cout<<"Flight: "<<flight_int[k]<<endl;
                  cout<<"Name: "<<passenger_name_int[k]<<endl;
                  cout<<"Airline: "<<airline_int[k]<<endl;
                  cout<<"Code: "<<airline_code_int[k]<<endl;
                  cout<<"Time: "<<time_int[k]<<endl;
                  cout<<"Passport no.: "<<passenger_passport_no_int[k]<<endl;
                  cout<<"Phone no.:"<<passenger_phone_no_int[k]<<endl;
                  cout<<"\n\n\nDo you wish to continue? (Yes/No): ";
                  string choice;
                  cin>>choice;
                  //user can continue or quit
                  if(choice=="Yes" || choice=="yes")
                  {
                        system("CLS");
                        main();
                  }
                  else
                        return ;
              }

              if(option==3)
                //in case user wants to go back to previous screen(main screen)
              {
                    system("CLS"); //clearing screen
                    main(); //returning to main
              }
}
//As part of our innovation in the program, this function would generate a random flight for traveling lovers
void random_selection()
{
     ofstream Flight_reservation_domestic("flightreservation_domestic.txt", fstream::app);
     ofstream Flight_reservation_international("flightreservation_international.txt", fstream::app);
     system("CLS"); //to clear main screen
              int option; //to store user input
              cout << "\n\n(1)Domestic Fights \n(2)International Flights\n(3)Back" << endl;
              //presenting user with a choice
              option=validation(1,3);  //validating user input
              //random selection of domestic flights
              if (option==1)
              {
                  system("CLS");
                  string city1,city2, city, flight_date1[7];
                  int a=0,b=0, option2;
                  cout<<"\t\t\t\tWelcome to Flight reservation for domestic flights\n\n"<<endl;
                  cout<<"  Arrival Cities"<<endl;
                  cout<<"1.Lahore"<<endl;
                  cout<<"2.Islamabad"<<endl;
                  cout<<"3.karachi"<<endl;
                  cout<<"4.Quetta"<<endl;
                  cout<<"5.Peshawar"<<endl;
                  a=validation(1,5);
                  switch(a)
                  {
                  case 1: city1="Lahore";
                  break;
                  case 2: city1="Islamabad";
                  break;
                  case 3: city1="Karachi";
                  break;
                  case 4: city1="Quetta";
                  break;
                  case 5: city1="Peshawar";
                  break;
                  }
                  b=rand()%5+1;
                  while(a==b)//validation check
                  {
                        b=rand()%5+1;
                  }
                  switch(b)
                  {
                  case 1: city2="Lahore";
                  break;
                  case 2: city2="Islamabad";
                  break;
                  case 3: city2="Karachi";
                  break;
                  case 4: city2="Quetta";
                  break;
                  case 5: city2="Peshawar";
                  break;
                  }
                  city=city1+" to "+city2;
                  string choice;
                  cout<<"Would you like to travel between, "<<city<<". "<<endl;
                  cout<<"Yes/No"<<": ";
                  cin>>choice;
                  if(choice=="Yes" || choice=="yes")
                  {
                      system("CLS");
                      flight_date1[0]="Friday, 1st January, 2021";
                      flight_date1[1]="Saturday, 2nd January, 2021";
                      flight_date1[2]="Sunday, 3rd January, 2021";
                      flight_date1[3]="Monday, 4th January, 2021";
                      flight_date1[4]="Tuesday, 5th January, 2021";
                      flight_date1[5]="Wednesday, 6th January, 2021";
                      flight_date1[6]="Thursday, 7th January, 2021";
                      cout<<"\n\n";
                      for(int k=0;k<7;k++)//loop to print dates available for travel
                      {
                          cout<<k+1<<") "<<flight_date1[k]<<endl;
                      }
                      option2=validation(1,7);
                      Flight_reservation_domestic<<flight_date1[option2-1]<<endl;//save date in text file
                      Flight_reservation_domestic<<city<<endl;
                      Flight_reservation_domestic.close();
                      airline_generator_domestic();
                  }
                  else
                  {
                      system("CLS");
                      main();
                  }
               }
                  //random selection of international flights
                  else if(option==2)
                  {
                      system("CLS");
                      int a=0,b=0, option2;
                      string city1,city2, city, flight_date1[7];
                      cout<<"\t\t\t\tWelcome to Flight Reservation for 'International Flights'\n\n"<<endl;
                      cout<<"  Departure Cities"<<endl;
                      cout<<"1.Lahore"<<endl;
                      cout<<"2.Karachi"<<endl;
                      cout<<"3.Islamabad"<<endl;
                      cout<<"4.New York"<<endl;
                      cout<<"5.London"<<endl;
                      cout<<"6.Sydney"<<endl;
                      cout<<"7.Berlin"<<endl;
                      cout<<"8.Toronto"<<endl;
                      cout<<endl;
                      a=validation(1,8);
                  switch(a) //switch statement to store user departure city
                  {
                      case 1: city1="Lahore";
                      break;
                      case 2: city1="Karachi";
                      break;
                      case 3: city1="Islamabad";
                      break;
                      case 4: city1="New York";
                      break;
                      case 5: city1="London";
                      break;
                      case 6: city1="Sydney";
                      break;
                      case 7: city1="Berlin";
                      break;
                      case 8: city1="Toronto";
                      break;
                      default: city1="Invalid";
                      break;
                  }
                  b=rand()%5+1;
                  while(a==b)//validation check
                  {
                      b=rand()%5+1;
                  }
                  switch(b) //switch statement to store user's arrival city
                  {
                      case 1: city2="Paris";
                      break;
                      case 2: city2="Amsterdam";
                      break;
                      case 3: city2="Cambridge";
                      break;
                      case 4: city2="Texas";
                      break;
                      case 5: city2="Moscow";
                      break;
                      default: city2="Invalid";
                      break;
                  }
                      city=city1+" to "+city2;
                      string choice;
                      cout<<"Would you like to travel between, "<<city<<". "<<endl;  //User Input helps to make a tailored plan
                      cout<<"Yes/No"<<": ";
                      cin>>choice;
                  if(choice=="Yes" || choice=="yes")
                  {
                      system("CLS");
                      flight_date1[0]="Friday, 1st January, 2021";
                      flight_date1[1]="Saturday, 2nd January, 2021";
                      flight_date1[2]="Sunday, 3rd January, 2021";
                      flight_date1[3]="Monday, 4th January, 2021";
                      flight_date1[4]="Tuesday, 5th January, 2021";
                      flight_date1[5]="Wednesday, 6th January, 2021";
                      flight_date1[6]="Thursday, 7th January, 2021";
                      cout<<"\n\n";
                      for(int k=0;k<7;k++)//loop to print dates available for travel
                      {
                          cout<<k+1<<") "<<flight_date1[k]<<endl;
                      }
                      option2=validation(1,7);
                      Flight_reservation_international<<flight_date1[option2-1]<<endl;//save date in text file
                      Flight_reservation_international<<city<<endl;
                      Flight_reservation_international.close();
                      airline_generator_international();
                  }
                      else
                  {
                      system("CLS");
                      main();
                  }
                  }

                  if(option==3)
                //in case user wants to go back to previous screen(main screen)
                {
                    system("CLS"); //clearing screen
                    main(); //returning to main
                }

}

//function declaration and definition, this would cancel a reserved flight
/*
This function would ask the user to input their passport number, and if it exists in the database, all the record of the
passenger registered on that passport number would be removed.
*/

void cancel_flight()
{

    system("CLS"); //to clear main screen
              int option,a, b; //to store user input
              cout << "\n\n(1)Domestic Fights \n(2)International Flights\n(3)Back" << endl;
              //presenting user with a choice
              option=validation(1,3);  //validating user input
              if (option==1)  //Cancelling a domestic flight
              {
                  ofstream Flight_reservation_domestic("flightreservation_domestic.txt");//opening database for domestic passenger
                  system("CLS");   //to store user input
                  string passport_num;
                  int i=0;   //to store user input
                  int k=0;
                  cout<<"\n\n\nPlease enter passenger passport number: ";
                  cin>>passport_num;
                  bool flag=false; //using bool to ensure whether passport number matches or not
                  for(i; i<counter_dom; i++)
                  {
                      //Comparing passport_num with the available data stored in our text file
                      if(strcmp(passport_num.c_str(),passenger_passport_no_dom[i].c_str())==0)
                      {
                          k=i; //storing index when passport number matches
                          flag=true;
                          break;
                      }
                  }
                  if(flag==false) //if passport number does not matches, our program will take user to main screen
                      {
                          cout<<"Invalid passport number, please try again.";
                          system("CLS");
                          main();
                      }
                  cout<<"\n\n\nYour reserved flight is canceled.\n";
                  //Printing user data when passport number matches
                  flight_day[k]="\0";
                  flight_dom[k]="\0";
                  passenger_name_dom[k]="\0";
                  airline_dom[k]="\0";
                  airline_code_dom[k]="\0";
                  time_dom[k]="\0";
                  passenger_passport_no_dom[k]="\0";
                  passenger_phone_no_dom[k]="\0";
                  for(int j=0;j<counter_dom;j++)
                   {
                        if(j==k)
                            continue;   //If index matches to the cancel flight index, loop will skip that index
                        //Storing the updated data after flight is cancelled by the passenger
                        Flight_reservation_domestic<<flight_day[j]<<endl
                                                        <<flight_dom[j]<<endl<<airline_dom[j]<<"\n";
                        Flight_reservation_domestic<<airline_code_dom[j]<<endl
                                                        <<time_dom[j]<<endl<<passenger_name_dom[j]<<"\n";
                        Flight_reservation_domestic<<passenger_phone_no_dom[j]<<endl
                                                        <<passenger_passport_no_dom[j]<<"\n";
                   }
                  Flight_reservation_domestic.close();
                  cout<<"\n\n\nDo you wish to continue? (Yes/No): ";
                  string choice;
                  cin>>choice;
                  //user can continue or quit
                  if(choice=="Yes" || choice=="yes")
                  {
                    system("CLS");
                    main();
                  }
                  else
                    return;
              }

              if (option==2)  //Canceling an international flight
              {
                  //opening database for international passenger
                  ofstream Flight_reservation_international("flightreservation_international.txt");
                  system("CLS");   //to store user input
                  string passport_num;
                  int i=0;   //to store user input
                  int k=0;
                  cout<<"\n\n\nPlease enter passenger passport number: ";
                  cin>>passport_num;
                  cout<<passport_num;
                  bool flag=false; //using bool to ensure whether passport number matches or not
                  for(i; i<counter_int; i++)
                  {
                      //Comparing passport_num with the available data stored in our text file
                      if(strcmp(passport_num.c_str(),passenger_passport_no_int[i].c_str())==0)
                      {
                          k=i; //storing index when passport number matches
                          flag=true;
                          break;
                      }
                  }
                  if(flag==false) //if passport number does not matches, our program will take user to main screen
                      {
                          cout<<"Invalid passport number, please try again.";
                          system("CLS");
                          main();
                      }
                  cout<<"\n\n\nYour reserved flight is canceled.\n";
                  //Printing user data as null in file when passport number matches
                  flight_day_int[k]="\0";
                  flight_int[k]="\0";
                  passenger_name_int[k]="\0";
                  airline_int[k]="\0";
                  airline_code_int[k]="\0";
                  time_int[k]="\0";
                  passenger_passport_no_int[k]="\0";
                  passenger_phone_no_int[k]="\0";
                  for(int j=0;j<counter_int;j++)
                   {
                        if(j==k)
                            continue;   //If index matches to the cancel flight index, loop will skip that index
                        //Storing the updated data after flight is cancelled by the passenger
                        Flight_reservation_international<<flight_day_int[j]<<endl
                                                        <<flight_int[j]<<endl<<airline_int[j]<<"\n";
                        Flight_reservation_international<<airline_code_int[j]<<endl
                                                        <<time_int[j]<<endl<<passenger_name_int[j]<<"\n";
                        Flight_reservation_international<<passenger_phone_no_int[j]<<endl
                                                        <<passenger_passport_no_int[j]<<"\n";
                   }
                  Flight_reservation_international.close();
                  cout<<"\n\n\nDo you wish to continue? (Yes/No): ";
                  string choice;
                  cin>>choice;
                  //user can continue or quit
                  if(choice=="Yes" || choice=="yes")
                  {
                    system("CLS");
                    main();
                  }
                  else
                    return ;
              }

              if(option==3)
                  //in case user wants to go back to previous screen(main screen)
                 {
                    system("CLS"); //clearing screen
                    main(); //returning to main
                 }

}

//main function of our program
//redirection to different functions is done based on user input
int main()
{
     srand(time(0));
     domestic_data();
     international_data();
     int option; //taking user input
     option=front_page(); //redirecting to function which will display front screen of program and return the option user enter

     if(option==1) //in case user wants to book a flight
       {
         book_flight();   //call to a function that deals with everything related to booking a flight
       }
     else if(option==2) //in case user wants to check a reserved flight
       {
         check_reserved_flight();
        //call to a function that check for a reserved flight
       }
     else if(option==3) //in case travelers user our program
       {
         random_selection();
        //call to a function that generates a random flight
       }
     else if(option==4) //in case user wants to cancel a previously reserved flight
       {
         cancel_flight();
        //call to a function that cancels a reserved flight
       }
}

