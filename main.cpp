#include <iostream>
//#include <string>
using namespace std;
int successes;
int xCoord;
int yCoord;
char heading;
int headingDegrees;
int batteryLevel;
bool good;
bool goalReached;
// housekeeping functions

//add negative angle handling for later
int translateHeadingToDegrees(char direction) {
    if (direction == 'E') {
        return 0;
    }else if (direction == 'N') {
        return 90;
    }else if (direction == 'W') {
        return 180;
    }else if (direction == 'S') {
        return 270;
    }else {
        return -1;
    }
}

char translateDegreesToHeading(int direction) {
    switch (direction) {
        case 0:
            return 'E';
            break;
        case 90:
            return 'N';
            break;
        case 180:
            return 'W';
            break;
        case 270:
            return 'S';
            break;
        default:
            return 'E';
            break;
    }
}

/*
 *fuh ahh function
//check that this works in main(). make a ptr
static char* splitString(string command) {
    int stringSize = command.length();
    char letters[stringSize];
    for (int i = 0; i < stringSize; i++) {
        letters[i] = command[i];
    }
    letters[stringSize] = 0;
    return letters;
}

*/

//🤮
void testCondition(char command) {
    int projectedXCoord1 = xCoord + 1;
    int projectedXCoord2 = xCoord - 1;
    int projectedYCoord1 = yCoord + 1;
    int projectedYCoord2 = yCoord - 1;

    if ((command == 'F' && batteryLevel < 2) || ((command == 'L' || command == 'R') && batteryLevel < 1) || (command == 'S' && batteryLevel < 3)) {
        cout<<"Command "<<command<<" rejected: insufficient battery"<<endl;
        good = false;
    }else if (command == 'F' && ((headingDegrees == 0 && projectedXCoord1 > 9) || (headingDegrees == 90 && projectedYCoord1 > 9))) {
        cout<<"Command "<<command<<" rejected: out of bounds"<<endl;
        good = false;
    }else if (command == 'F' && ((headingDegrees == 180 && projectedXCoord2 < 0) || (headingDegrees == 270 && projectedYCoord2 < 0))) {
        cout<<"Command "<<command<<" rejected: out of bounds"<<endl;
        good = false;
    }else if (command == 'C' && (xCoord != 0 || yCoord != 0)) {
        cout<<"Command C rejected: not at charger"<<endl;
        good = false;
    }else{
        good = true;
    }
}
/*
void testCondition(char command) {
    int projectedXCoord1 = xCoord + 1;
    int projectedXCoord2 = xCoord - 1;
    int projectedYCoord1 = yCoord + 1;
    int projectedYCoord2 = yCoord - 1;
    if (batteryLevel < 0) {
        cout<<"Command "<<command<<" rejected: insufficient battery"<<endl;
        good = false;
    }else if ((projectedXCoord1 > 9) || (projectedXCoord1 < 0) || (projectedYCoord1 > 9) || (projectedYCoord1 < 0)) {
        cout<<"Command "<<command<<" rejected: out of bounds"<<endl;
        good = false;
    }else if ((projectedXCoord2 > 9) || (projectedXCoord2 < 0) || (projectedYCoord2 > 9) || (projectedYCoord2 < 0)) {
        cout<<"Command "<<command<<" rejected: out of bounds"<<endl;
        good = false;
    }else{
        good = true;
    }
}
*/
void printSuccess(char c){
    cout<<"Command "<<c<<" successful. Current coordinates: ("<<xCoord<<","<<yCoord<< "). heading: "<<translateDegreesToHeading(headingDegrees)<<", and battery is at "<<batteryLevel<<"."<<endl;
}



//functional functions
void goForward() {
    batteryLevel -= 2;
    switch (headingDegrees) {
        case 90:
            yCoord++;
            break;
        case 270:
            yCoord--;
            break;
        case 0:
            xCoord++;
            break;
        case 180:
            xCoord--;
            break;
        /*default:
            cout<<"Command rejected: invalid direction";
            //modify this
            break;
            */
    }
}
void rotateLeft(){
    batteryLevel--;
    headingDegrees += 90;
    headingDegrees = headingDegrees % 360;
}
void rotateRight() {
    batteryLevel--;
    headingDegrees -= 90;
    headingDegrees = (headingDegrees + 360) % 360;
}

//double check what this is supposed to do
void scanArea() {
    if (batteryLevel < 3) {
        cout<<"Command S rejected: insufficient battery"<<endl;
    }else {
        batteryLevel -= 3;
    }
}

void rechargeBattery() {
    if (xCoord == 0 && yCoord == 0) {
        successes++;
        batteryLevel = 40;
        printSuccess('C');
    }else {
        cout<<"Command C rejected: not at charger"<<endl;
    }
}

void goOnAMission(int goalX, int goalY, string directions) {
    successes = 0;
    goalReached = (xCoord == goalX && yCoord == goalY);
    for (char c : directions) {
        switch (c) {
            case 'F':
                testCondition('F');
                if (good) {
                    goForward();
                    successes++;
                    printSuccess('F');
                }
                break;
            case 'L':
                testCondition('L');
                if (good) {
                    rotateLeft();
                    successes++;
                    printSuccess('L');
                }
                break;
            case 'R':
                testCondition('R');
                if (good) {
                    rotateRight();
                    successes++;
                    printSuccess('R');
                }
                break;
            case 'S':
                testCondition('S');
                if (good) {
                    scanArea();
                    successes++;
                    printSuccess('S');
                }
                break;
            case 'C':
                rechargeBattery();
                //cout<<"Command C successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
        if ((xCoord == goalX) && (yCoord == goalY)) {
            goalReached = true;
        }
    }
    heading = translateDegreesToHeading(headingDegrees);
    cout<<"mission complete. rover is at: ("<<xCoord<<","<<yCoord<<"), and battery is at "<<batteryLevel<<". heading: "<<heading<<"."<<endl;
}


int main() {
    headingDegrees = 0;
    xCoord = 0;
    yCoord = 0;
    batteryLevel = 40;
    bool quit = false;
    string mission;
    int goalXCoord;
    int goalYCoord;
    cout<<"Input mission"<<endl;
    cin>>mission;
    if (mission == "quit") {
        quit = true;
    }
    while (!quit){
        cout<<"Input goal X coordinate"<<endl;
        cin>>goalXCoord;
        cout<<"Input goal Y coordinate"<<endl;
        cin>>goalYCoord;
        goOnAMission(goalXCoord, goalYCoord, mission);
        cout<<"Number of successful commands: "<<successes<<endl;
        if (goalReached && xCoord == 0 && yCoord == 0 && batteryLevel == 40) {
            cout<<"Goal reached and rover reset."<<endl;
        }else if (goalReached) {
            cout<<"Goal reached but rover not reset."<<endl;
        }else if (xCoord == 0 && yCoord == 0 && batteryLevel == 40) {
            cout<<"Goal not reached but rover reset."<<endl;
        }else {
            cout<<"Goal not reached and rover not reset."<<endl;
        }
        cout<<"Input mission"<<endl;
        cin>>mission;
        if (mission == "quit") {
            quit = true;
        }
    }
}
