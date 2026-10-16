#include <iostream>
//#include <string>
using namespace std;

int xCoord;
int yCoord;
char heading;
int headingDegrees;
int batteryLevel;

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


void testCondition(char command){
    if (batteryLevel < 0) {
        cout<<"Command "<<command<<" rejected: insufficient battery"<<endl;
    }else if ((xCoord))
}

*/



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
}
void rotateRight() {
    batteryLevel--;
    headingDegrees -= 90;
}

//double check what this is supposed to do
void scanArea() {
    batteryLevel -= 3;
}

void rechargeBattery() {
    if (xCoord == 0 && yCoord == 0) {
        batteryLevel = 40;
    }else {
        cout<<"Command C rejected: not at charger";
    }
}

void goOnAMission(int goalX, int goalY, string directions) {
    for (char c : directions) {
        switch (c) {
            case 'F':
                goForward();
                cout<<"Command F successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            case 'L':
                rotateLeft();
                cout<<"Command L successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            case 'R':
                rotateRight();
                cout<<"Command R successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            case 'S':
                scanArea();
                cout<<"Command S successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            case 'C':
                rechargeBattery();
                cout<<"Command C successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<"."<<endl;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
            }
        }
    heading = translateDegreesToHeading(headingDegrees);
    cout<<"mission complete. rover is at: ("<<xCoord<<","<<yCoord<<"), and battery is at "<<batteryLevel<<". heading: "<<heading<<".";
}

int main() {
    headingDegrees = 0;
    xCoord = 0;
    yCoord = 0;
    batteryLevel = 40;
    int goalXCoord;
    int goalYCoord;

    cin<<
}

