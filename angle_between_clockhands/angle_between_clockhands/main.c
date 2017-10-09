//
//  main.c
//  angle_between_clockhands
    /*
    minute hand/per minute: 6
    Since every one min, hour hand moves = 0.5   
    hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;// with respect
     
    Example: 3:15
    hour hand = 3*30 + 0.5* 15 = 90+7.5 = 97.5
    min hand = 15*6 = 90
    Angle between is 7.5
    */
//  Created by Anoja Rajalakshmi on 9/15/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>

float find_angle(int hr,int min){
    
    if (hr == 12) hr = 0;
    if (min == 60) min = 0;
    float hr_angle = 0.5 * (hr*60 + min); //0.5* (3*60+15)
    float min_angle = 6*min;
    
    float angle = abs(hr_angle - min_angle);
    angle = (360-angle < angle)? 360-angle: angle;
    return angle;
}
int main(int argc, const char * argv[]) {
    printf("%0.2f\n",find_angle(3,10));
    printf("%0.2f\n",find_angle(12,30));
    printf("%0.2f\n",find_angle(1,20));
    printf("%0.2f\n",find_angle(10,30));
    return 0;
}
