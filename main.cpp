#include <iostream>
#include <unistd.h>

using namespace std;

class Operator
{
private:
    string Username;
    string Password;

public:
    void setUsername(string usern)
    {
        this -> Username = usern;
    }
    void setPassword(string passwd)
    {
        this -> Password = passwd;
    }
    string getUsername()
    {
        return this -> Username;
    }
    string getPassword()
    {
        return this -> Password;
    }
};

class OperatorList
{
private:
    Operator Employees[10];
    int NrOfEmpl;

public:
    OperatorList()
    {
        NrOfEmpl = 0;
        Employees[NrOfEmpl].setUsername("voicu_costin");
        Employees[NrOfEmpl].setPassword("dinamo123");
        NrOfEmpl++;
        Employees[NrOfEmpl].setUsername("chis.daniel");
        Employees[NrOfEmpl].setPassword("OOP1145");
    }
    void EmployeesDetails(string *v, int &n, string *u)
    {
        v[0] = Employees[0].getUsername();
        v[1] = Employees[1].getUsername();
        u[0] = Employees[0].getPassword();
        u[1] = Employees[1].getPassword();
        n = 2;
    }
};

class Flight
{
private:
    string FlightName;
    string FlightOrigin;
    string FlightDestination;
    string Date;

public:
    void setFlightName(string Name)
    {
        this -> FlightName = Name;
    }
    void changeOrigin(string newOrigin)
    {
        this -> FlightOrigin = newOrigin;
    }
    void changeDestination(string newDestination)
    {
        this -> FlightDestination = newDestination;
    }
    void changeDate(string newDate)
    {
        this -> Date = newDate;
    }
    string getFlightName()
    {
        return this -> FlightName;
    }
    string getOrigin()
    {
        return this -> FlightOrigin;
    }
    string getDestination()
    {
        return this -> FlightDestination;
    }
    string getDate()
    {
        return this -> Date;
    }

    void FlightDetails(int nr)
    {
        cout << nr << ", " << getFlightName() << "Origin: " << getOrigin() << " Destination: " << getDestination() << " Date: " << getDate() << endl;
    }
};

class AllFlights
{
private:
    Flight Flights[50];
    int NrOfFlights;

public:
    AllFlights()
    {
        NrOfFlights = 0;
    }
    void createFlight(string Name, string Origin, string Destination, string Date)
    {
        Flights[NrOfFlights].setFlightName(Name);
        Flights[NrOfFlights].changeOrigin(Origin);
        Flights[NrOfFlights].changeDestination(Destination);
        Flights[NrOfFlights].changeDate(Date);
        NrOfFlights++;
    }
    void ListAllFlights()
    {
        for(int i = 0; i < NrOfFlights; i++)
            Flights[i].FlightDetails(i + 1);
    }

    int NumberOfFlights()
    {
        return this -> NrOfFlights;
    }
};

OperatorList Company;
AllFlights FlightList;

void OperatorLogin();
void MainMenu();
void OperatorMenu(string username);
bool isDateValid(int day, int month, int year);

void OperatorLogin()
{
    string username, password;
    string EmployeesUsernames[10], EmployeesPassword[10];
    int nrOfEmployees, index;
    string choiceNumber;

    cout<< "Enter as an operator:" << endl;
    sleep(1);
    cout << "Please enter your username: " << endl;

    Company.EmployeesDetails(EmployeesUsernames, nrOfEmployees, EmployeesPassword);

    try
    {
        cin >> username;
        for(int i = 0; i < nrOfEmployees; i++)
        {
            if (username == EmployeesUsernames[i])
            {
                cout << "Username found! Please enter your password." << endl;
                index = i;
                cin >> password;
                if(password == EmployeesPassword[index])
                {
                    cout << "Logging in as " << username << endl;
                    sleep(1);
                    OperatorMenu(username);
                }
                else { throw i; }
                return;
            }
            throw username;
        }
    }
    catch (string user)
    {
        cout << "Operator username " << user << " not found!" << endl;

        while (choiceNumber != "1" || choiceNumber != "2")
        {
            cout << "Would you like to try again (1) or to go back to the main menu (2) ?" << endl;
            cin >> choiceNumber;
            if(choiceNumber == "1")
            {
                OperatorLogin();
                return;
            }
            else if (choiceNumber == "2")
            {
                    MainMenu();
                    return;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }
    }

    catch(int i)
    {
        sleep(1);
        cout << "Invalid password!" << endl;
        sleep(1);
        while(choiceNumber != "1" || choiceNumber != "2")
        {
            cout << "Return to the main menu (1) or try again (2) " << endl;
            cin >> choiceNumber;
            if (choiceNumber == "2")
            {
               OperatorLogin();
               return;
            }
            else if (choiceNumber == "1")
            {
                MainMenu();
                return;
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        cout << "Return to operator menu!" << endl;
        OperatorLogin();
    }
}

void OperatorMenu(string username)
{
    string choice;
    cout << "Welcome, " << username << "!" << endl;
    cout << "Show all flights(1) | Add a new flight (2) Log out (3)" << endl;
    cin >> choice;

    try
    {
      if (choice == "1")
      {
          FlightList.ListAllFlights();
          sleep(1);
          OperatorMenu(username);
          return;
      }
      else if (choice == "2")
      {
          return;
      }

      else if (choice == "3")
      {
          return;
      }
      else
      {
         throw choice;
      }
    }
    catch (string choice)
    {
        cout << "Invalid selection!" << endl;
        OperatorMenu(username);
    }
}

void MainMenu()
{
    string checkPersonStatus;
    cout << "Welcome to our flight reservation app!" << endl;
    sleep(1);

    cout << "Are you an operator (1), an existing client(2), or would you like to register (3) ?" << endl;

    cin >> checkPersonStatus;

    try
    {
        if (checkPersonStatus == "1")
        {
            OperatorLogin();
        }
        else if (checkPersonStatus == "2")
        {
            cout << "Existing client" << endl;
        }
        else
        {
            throw checkPersonStatus;
        }
    }
    catch (...)
    {
        cout << "Invalid selection." << endl;
        cout << "Please enter a number from 1 to 3." << endl;
        cout << endl;
        MainMenu();
    }
    return;
}
int main()
{
    FlightList.createFlight("BR2453S", "Brazil", "Abu Dhabi", "23/11/2021");
     FlightList.createFlight("RO1713", "Bucharest", "Roma", "20/12/2021");
      FlightList.createFlight("SP4344G", "Madrid", "Leipzig", "25/12/2021");
       FlightList.createFlight("FR12S", "Paris", "Barcelona", "10/11/2021");

    MainMenu();
    return 0;
}
