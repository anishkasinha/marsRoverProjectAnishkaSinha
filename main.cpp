#include <iostream>
#include <string>
using namespace std;

int xCoord;
int yCoord;
char heading;
int headingDegrees;
int batteryLevel;

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
void goOnAMission(int goalX, int goalY, string directions) {

}

int main() {
}
