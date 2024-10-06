#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <sstream>

class Date {
private:
    int month;
    int day;
    int year;
    std::string monthNames[12];

public:
    Date(){
    	month = 1;
    	day = 1;
    	year = 2023;
    	initializeMonthNames();
	}

    Date(int month, int day, int year){
    	this->month = month;
    	this->day = day;
    	this->year = year;
    	initializeMonthNames();
	}
	
	// Getters
    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    int getYear() const {
        return year;
    }

    // Setters
    void setMonth(int month) {
        this->month = month;
    }

    void setDay(int day) {
        this->day = day;
    }

    void setYear(int year) {
        this->year = year;
    }

    //validate month, day, year(and leap year)
    bool isValidMonth() const {
        return (month >= 1 && month <= 12);
    }

    bool isValidDay() const {
        if (month == 2) {  
            if (isLeapYear()) {
                return (day >= 1 && day <= 29);
            } else {
                return (day >= 1 && day <= 28);
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return (day >= 1 && day <= 30);
        } else {
            return (day >= 1 && day <= 31);
        }
    }

    bool isValidYear() const {
        return (year >= 0 && year < 9000); 
    }

    bool isLeapYear() const {
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
    }
    
  

    std::string Big(char separator) const {
        std::string formattedDate = std::to_string(year) +
                                    separator +
                                    formatTwoDigits(month) +
                                    separator +
                                    formatTwoDigits(day);
        return formattedDate;
    }
    std::string BigName(char separator) const {
        std::string formattedDate = std::to_string(year) +
                                    separator +
                                    getMonthName(month) +
                                    separator +
                                    formatTwoDigits(day);
        return formattedDate;
    }

    std::string Little(char separator) const {
        std::string formattedDate = formatTwoDigits(day) +
                                    separator +
                                    formatTwoDigits(month) +
                                    separator +
                                    std::to_string(year);
        return formattedDate;
    }
    
    std::string LittleName(char separator) const {
        std::string formattedDate = formatTwoDigits(day) +
                                    separator +
                                    getMonthName(month) +
                                    separator +
                                    std::to_string(year);
        return formattedDate;
    }

    std::string Middle(char separator) const {

        std::string formattedDate = formatTwoDigits(month) + " " +
                                	formatTwoDigits(day) + " " +
                                	std::to_string(year);
        return formattedDate;
    }
    
    std::string MiddleName(char separator) const {
        std::string formattedDate = getMonthName(month) + " " +
                                	formatTwoDigits(day) + " " +
                                	std::to_string(year);
        return formattedDate;
    }

private:
   std::string formatTwoDigits(int value) const {
        if (value < 10) {
            return "0" + std::to_string(value);
        } else {
            return std::to_string(value);
        }
    }
    
void initializeMonthNames() {
        monthNames[0] = "January";
        monthNames[1] = "February";
        monthNames[2] = "March";
        monthNames[3] = "April";
        monthNames[4] = "May";
        monthNames[5] = "June";
        monthNames[6] = "July";
        monthNames[7] = "August";
        monthNames[8] = "September";
        monthNames[9] = "October";
        monthNames[10] = "November";
        monthNames[11] = "December";
    }
std::string getMonthName(int month) const {
        if (month >= 1 && month <= 12) {
            return monthNames[month - 1];
        }
        return "";
    }


};//end of date class

//prototype
void formatDate();



int main(){
	
	char choice;

    do {
        formatDate();

  		do {
            std::cout<<"\nDo you want to format another date? (y/n): ";
            std::cin>>choice;

            if (std::cin.fail() || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice == 'y' || choice == 'Y');
 


    return 0;
}

void formatDate(){
	
	int month, day, year, formatChoice, sepChoice, displayMonthChoice;
    char separator;

    std::cout<<"\nWelcome to the date formatting program!" << std::endl;

    std::cout<<"Please enter the date you wish to format (only numbers):" << std::endl;

    std::cout<<"Month: ";
    std::cin>>month;

    while (std::cin.fail() || month > 12) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid month (1-12): ";
        std::cin>>month;
    }

    std::cout<<"Day: ";
    std::cin>>day;

    while (std::cin.fail() || !Date(month, day, year).isValidDay()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid day: ";
        std::cin>>day;
    }

    std::cout<<"Year: ";
    std::cin>>year;

	while (std::cin.fail() || (Date(month, day, year).isLeapYear() && day == 29)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid year: ";
        std::cin>>year;
    }

    std::cout<<"Choose the format:" << std::endl;
    std::cout<<"1. Big Format (YYYYMMDD)" << std::endl;
    std::cout<<"2. Little Format (DDMMYYYY)" << std::endl;
    std::cout<<"3. Middle Format (MM DD YYYY)" << std::endl;
    std::cout<<"Enter your choice (1, 2, or 3): ";
    std::cin>>formatChoice;
    
    while(std::cin.fail() || formatChoice < 1 || formatChoice > 3){
    	std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid choice: ";
        std::cin>>formatChoice;
	}

    std::cout<<"Please enter the separator you prefer (as the number):" << std::endl;
    std::cout<<"1. '.'" << std::endl;
    std::cout<<"2. '-'" << std::endl;
    std::cout<<"3. '/'" << std::endl;
    std::cout<<"4. None (just a space)" << std::endl;
    std::cin>>sepChoice;
    
    while(std::cin.fail() || sepChoice < 1 || sepChoice > 4){
    	std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid choice: ";
        std::cin>>sepChoice;
	}

    switch (sepChoice) {
        case 1:
            separator = '.';
            break;
        case 2:
            separator = '-';
            break;
        case 3:
            separator = '/';
            break;
        case 4:
            separator = ' ';
            break;
        default:
            std::cout<<"Invalid choice. Setting separator to default ('/')."<<std::endl;
            separator = '/';
            break;
    }

    std::cout<<"Would you like the month to be displayed as the name or number?"<<std::endl;
    std::cout<<"1. Name"<<std::endl;
    std::cout<<"2. Number"<<std::endl;
    std::cout<<"Enter your choice (1 or 2): ";
    std::cin>>displayMonthChoice;
    
    while(std::cin.fail() || displayMonthChoice < 1 || displayMonthChoice > 2){
    	std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid input. Please enter a valid choice: ";
        std::cin>>displayMonthChoice;
	}

    Date date(month, day, year);

   
    switch (formatChoice) {
        case 1:
            if (displayMonthChoice == 1) {
                std::cout<<"\nFormatted Date: " << date.BigName(separator) << std::endl;
            } else {
                std::cout<<"\nFormatted Date: " << date.Big(separator) << std::endl;
            }
            break;
        case 2:
            if (displayMonthChoice == 1) {
                std::cout<<"\nFormatted Date: " << date.LittleName(separator) << std::endl;
            } else {
                std::cout<<"\nFormatted Date: " << date.Little(separator) << std::endl;
            }
            break;
        case 3:
            if (displayMonthChoice == 1) {
                std::cout<<"\nFormatted Date: " << date.MiddleName(separator) << std::endl;
            } else {
                std::cout<<"\nFormatted Date: " << date.Middle(separator) << std::endl;
            }
            break;
        default:
            std::cout<<"Invalid choice. Displaying default format (Big Format)." << std::endl;
            if (displayMonthChoice == 1) {
                std::cout<<"\nFormatted Date: " << date.BigName(separator) << std::endl;
            } else {
                std::cout<<"\nFormatted Date: " << date.Big(separator) << std::endl;
            }
            break;
    }
	
	
	
}
    
    

