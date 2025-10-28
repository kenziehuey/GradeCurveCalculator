// Name: Mackenzie Huey
// Section:
// Project 1: Grade Curve Calculator

#include <iostream>
#include <string>
#include <iomanip>
#include "FinalGrade.h"
#include "Gradebook.h"

using namespace std;

int main() 
{
    Gradebook CS218gradebook_original;
    string input;
    double score;

    // input scores
    while (true) 
    {
        cout << "Please enter a score for CS218 (type 'Q' or 'q' to quit): ";
        getline(cin, input);

        if (input == "Q" || input == "q") break;

        try 
            {
            score = stod(input);
        } catch (...) {
            cout << "Invalid input, please try again..." << endl;
            continue;
        }

        if (score < 0 || score > 100) 
        {
            cout << "The score is not in the correct range, please try again..." << endl;
            continue;
        }

        CS218gradebook_original.insert(FinalGrade(score));
    }

    // handle empty input 
    if (CS218gradebook_original.getSize() == 0) 
    {
        cout << "The gradebook is Empty!\nThank you for using CS218 Grade Curve Calculator." << endl;
        return 0;
    }

    cout << fixed << setprecision(2); // 2 decimal places
    double originalAvg = CS218gradebook_original.getAverage();

    // keep asking for expected average until user quits
    while (true) 
    {
        cout << "\nThe original average score is: " << originalAvg << endl;
        cout << "Please enter your expected average score to curve (type 'Q' or 'q' to quit): ";
        getline(cin, input);

        if (input == "Q" || input == "q") 
        {
            cout << "Exiting..." << endl;
            break;
        }

        double expectedAvg;
        try 
            {
            expectedAvg = stod(input);
        } catch (...) {
            cout << "The expected average is not in the correct range, please try again..." << endl;
            continue;
        }

        if (expectedAvg <= originalAvg || expectedAvg > 100) 
        {
            cout << "The expected average is not in the correct range, please try again..." << endl;
            continue;
        }

        if (abs(expectedAvg - originalAvg) < 0.01) 
        { // almost equal
            cout << "The scores are perfect, no need for the grading curve!" << endl;
            continue;
        }

        // curve the scores
        double extraPoints = expectedAvg - originalAvg;
        Gradebook CS218gradebook_curved = CS218gradebook_original;
        CS218gradebook_curved.incrementScore(extraPoints);

        // show original gradebook 
        cout << "\nThe original gradebook for CS218:" << endl;
        CS218gradebook_original.print();
        cout << "The number of scores is: " << CS218gradebook_original.getSize() << endl;
        cout << "The maximum score is: ";
        CS218gradebook_original.getMax().print();
        cout << "The minimum score is: ";
        CS218gradebook_original.getMin().print();
        cout << "The original average score is: " << originalAvg << endl;
        cout << "The expected average score is: " << expectedAvg << endl;

        // show curved gradebook
        cout << "\nThe curved gradebook for CS218:" << endl;
        CS218gradebook_curved.print();
        cout << "The number of scores is: " << CS218gradebook_curved.getSize() << endl;
        cout << "The maximum score is: ";
        CS218gradebook_curved.getMax().print();
        cout << "The minimum score is: ";
        CS218gradebook_curved.getMin().print();
        cout << "The actual average score is: " << CS218gradebook_curved.getAverage() << endl;
    }

    return 0;
}
