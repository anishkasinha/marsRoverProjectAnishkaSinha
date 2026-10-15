#include <iostream>
#include <string>
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
            //fix?
            break;
    }
}


//check that this works in main(). make a ptr
char* splitString(string command) {
    int stringSize = command.length();
    char letters[stringSize + 1];
    for (int i = 0; i < stringSize; i++) {
        letters[i] = command.at(i);
    }
    letters[stringSize + 1] = 'z';
    return letters;
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
        default:
            cout<<"Command rejected: invalid direction";
            //modify this
            break;
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
        cout<<"Command rejected: not at charger";
    }
}

void goOnAMission(int goalX, int goalY, string directions) {
    bool quit = false;
    headingDegrees = 0;
    xCoord = 0;
    yCoord = 0;
    batteryLevel = 40;
    while ((xCoord != goalX) && (yCoord != goalY) && (!quit) && (batteryLevel > 0)) {
        char *commands = splitString(directions);
        while (*commands != 'z') {
            switch (*commands) {
                case 'F':
                    goForward();
                    cout<<"Command F successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<".";
                    break;
                case 'L':
                    rotateLeft();
                    cout<<"Command L successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<".";
                    break;
                case 'R':
                    rotateRight();
                    cout<<"Command R successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<".";
                    break;
                case 'S':
                    scanArea();
                    cout<<"Command S successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<".";
                    break;
                case 'C':
                    rechargeBattery();
                    cout<<"Command C successful. Current coordinates:("<<xCoord<<","<<yCoord<< "). heading: "<<headingDegrees<<".";
                    break;
                default:
                    cout<<"Invalid input"<<endl;
                    break;
            }
            if (batteryLevel == 0) {
                break;
            }
            *(commands+1);
        }
    }
    heading = translateDegreesToHeading(headingDegrees);
    cout<<"mission complete. rover is at: ("<<xCoord<<","<<yCoord<<"), and battery is at "<<batteryLevel<<". heading: "<<heading<<".";
}

int main() {
    goOnAMission(1, 0, "F");
}

