#define TEMP 2      //TEMPERATURE ACQUISITION ON ANALOG PIN 2
#define HUMID 1      //HUMIDITY ACQUISITION ON ANALOG PIN 1
#define PRESS 0     //PRESSURE ACQUISITION ON ANALOG PIN 0
float val = 0.0;
float T= 0.0;
double humidity = 0.0;
double RH = 0.0;
double RHout = 0.0;
double UM = 0.0;
double Pascal=0.0;
double PS=0.0;
double P=0.0;
float VADC= 5;
int DPR = 0;
int RHCORR = 0;
int PCORR = 0;
int TCORR= 0;
double PRINT_T = 0;
double PRINT_U = 0;
double PRINT_P = 0 ;
byte degree[8] = { //  CHARACTER "°C" DEFINITION
  B10111,
  B01000,
  B10000,
  B10000,
  B10000,
  B01000,
  B00111,
};



float readTemp() {
  double nread = 100.0;          // NUMBER OF READINGS
  double sum = 0.0; 
  for (int i=0; i<nread; i++)
  {
    val = analogRead(TEMP);
    T = (((VADC/1024.0*val)-0.5)* 100)+TCORR;   //TEMPERATURE 
    sum += T;
  }
  delay(100);
  return (sum/nread);
}

double readHUMID(){
  double nread = 100.0;          // NUMBER OF READINGS 
  double sum = 0.0; 
  for (int i=0; i<nread; i++)
  {
    UM = analogRead( HUMID );              
    RHout=(((UM*VADC/1024.0/3.3)-0.1515)/0.00636)+RHCORR;    //HUMIDITY
    sum += RHout;       
  }
  delay(100);
  return  ( sum / nread );
}

float readPressure(){
  double nread = 100.0;           // NUMBER OF READINGS 
  double sum = 0.0; 
  for (int i=0; i<nread; i++)
  {
    Pascal=analogRead(PRESS);
    P=(((Pascal*VADC/1024)/VADC+0.095)/0.009)*10+DPR+PCORR;  //PRESSURE TRANSFERT FUNCTION
    sum += P;
  }
  delay(100);
  return  ( sum / nread ); 
}
