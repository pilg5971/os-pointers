// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    //[1]: User ID Number (int) 
    //[2]: First Name (String)
    //[3]: Last Name (String)
    //[4]: Number of assignments (int)
    //[5]: Grade for each assignment (Series of Doubles)

    //[1]: User ID Number (int)
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    //std::cout << student.id << std::endl;

    //[2]: First Name (String)
    std::cout << "Please enter the student's first name: ";
    student.f_name = new char[128];
    std::cin >> student.f_name;
    //std::cout << student.f_name << std::endl;

    //[3]: Last Name (String)
    std::cout << "Please enter the student's last name: ";
    student.l_name = new char[128];
    std::cin >> student.l_name;
    //std::cout << student.l_name << std::endl;
    
    //[4] + [5]: Number of assignments + Grades for each
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    std::cout << std::endl;
    //std::cout << student.n_assignments << std::endl;

    std::string message;
    student.grades = new double[134217728];
    for(int i = 0; i < student.n_assignments; i++){
        message = std::string("Please enter grade for assignment ") + std::to_string(i) + std::string(": ");
        *(student.grades + i) = promptDouble(message, 0.000000, 1000.0);
        //std::cout << *(student.grades + i) << std::endl;
    }

//----------------------------------------------------------------------//
    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    std::cout << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    calculateStudentAverage(&student, &average);
    std::cout << "  " << "Average grade: " << std::fixed << std::setprecision(1) << average << std::endl;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int solution;
    char userInput[10];
    int length; 
    
    std::cout << message;
    scanf("%s", userInput);
    length = strlen(userInput);
    
    /*for(int j = 0; j < length; j++){
        std::cout << userInput[j];
    }
    std::cout << std::endl;*/

    bool valid = false;
    while(valid == false){
        for(int i = 0; i < length; i++){
            if(!isdigit(userInput[i])){
                std::cout << "Sorry, I cannot understand your answer" << std::endl;
                std::cout << message;
                scanf("%s", userInput);
                length = strlen(userInput);
                break;
            }
            
            else if(i == (length - 1)){
                solution = atoi(userInput);
                if((solution >= min) && (solution <= max)){
                    valid = true;
                    break;
                }
                std::cout << "Sorry, I cannot understand your answer" << std::endl;
                std::cout << message;
                scanf("%s", userInput);
                length = strlen(userInput);
                break;
            }
        }
    }

    /*while(true){
        std::cout << message;
        std::cin >> solution;
        if(!std::cin.fail()){
            if(solution > min && solution < max){
                break;
            }
        }
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cin.clear();
        std::cin.ignore(0, '\n');
    }*/
  
    return solution;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double solution;
    char userInput[10];
    int length; 
    
    std::cout << message;
    scanf("%s", userInput);
    length = strlen(userInput);
    
    /*for(int j = 0; j < length; j++){
        std::cout << userInput[j];
    }
    std::cout << std::endl;*/

    bool valid = false;
    while(valid == false){
        for(int i = 0; i < length; i++){
            if(!isdigit(userInput[i])){
                if(userInput[i] != '.'){
                    std::cout << "Sorry, I cannot understand your answer" << std::endl;
                    std::cout << message;
                    scanf("%s", userInput);
                    length = strlen(userInput);
                    break;
                }
            }
            
            else if(i == (length - 1)){
                solution = atof(userInput);
                if((solution >= min) && (solution <= max)){
                    valid = true;
                    break;
                }
                std::cout << "Sorry, I cannot understand your answer" << std::endl;
                std::cout << message;
                scanf("%s", userInput);
                length = strlen(userInput);
                break;
            }
        }
    }
    return solution;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student input = *((Student*)object);

    double sum;
    for(int i = 0; i < input.n_assignments; i++){
        sum += input.grades[i];
    }
    *avg = (sum/input.n_assignments);
}
