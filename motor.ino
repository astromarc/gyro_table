// Marc Cortes Fargas
// NanoSatLab
// 2017
// Code based in Mike McCauley example from AccelStepper library
/// author of base code: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

double v_trans;
double v_hertz;
double rel_trans;
double deg_sec;
double trans_driver;
double deg_sec_user;
String a;
char copy[50];
AccelStepper stepper(1,11,13); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  

  Serial.begin(115200);
  ////Input from user
  deg_sec_user = 0; // input desired velocity in deg / sec
  trans_driver = 16; // input reduction from driver 
  rel_trans = 25/2;  // input reduction from gearbox
  //
  deg_sec = deg_sec_user * trans_driver;
  v_hertz  = deg_sec/360;
  v_trans = v_hertz * (360/1.8) * rel_trans;

  stepper.setMaxSpeed(1000000);
  stepper.setSpeed(v_trans);

}

void loop()
{
  if(Serial.available()){
   while(Serial.available()) {
   a = Serial.readString();// read the incoming data as string
  a.toCharArray(copy, 50);
  deg_sec_user = atof(copy);
  deg_sec = deg_sec_user * trans_driver;
  v_hertz  = deg_sec/360;
  v_trans = v_hertz * (360/1.8) * rel_trans;
  stepper.setSpeed(v_trans);
  Serial.print(deg_sec_user);Serial.print('\n');

}}

  stepper.runSpeed();

}



