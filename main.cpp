#include <iostream>
#include <string>
using namespace std;

int xCoord;
int yCoord;
char heading;
int headingDegrees;
int batteryLevel;

// housekeeping functions

//add negative angle handling
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
    char letters[stringSize];
    for (int i = 0; i < stringSize; i++) {
        letters[i] = command.at(i);
    }
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

void rechargebattery() {
    if (xCoord == 0 && yCoord == 0) {
        batteryLevel = 40;
    }else {
        cout<<"Command rejected: not at charger";
    }
}

void goOnAMission(int goalX, int goalY, string directions) {
    bool quit = false;
    headingDegrees = 0;
    while ((xCoord != goalX) && (yCoord != goalY) && (!quit) && (batteryLevel > 0)) {
        char *commands = splitString(directions);
    }

}
int main() {}

