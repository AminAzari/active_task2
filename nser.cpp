 
 #include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdint.h>
using namespace std;


int main () {
 
    ///////////////////////////////////////////////////
    // DS18b20 Temperature sensor
    ///////////////////////////////////////////////////
		
	 char path[50] = "/sys/bus/w1/devices/";
	char rom[20];
	char buf[100];
	 
	struct dirent *direntp;
	int fd =-1;
	char *temp;
	float value;
			
	// atof: changes string to float.
char buffer[256];
  printf ("Enter degrees: ");
  fgets (buffer,256,stdin);
	value = atof(buffer)/1000;
	char c[50]; //size of the number
	//sprintf(c, "%.2f °C", value);
	sprintf(c, "%.2f", value);
		
	//printf("Temperature: %s\n", c);
			
    ///////////////////////////////////////////////////
    // DS18b20 Temperature sensor
    ///////////////////////////////////////////////////
		
	uint8_t RF_GATEWAY_ID =2;
    // Send Temperature data to rf95_server
    //uint8_t data[] = "Hi Hackster !";
    uint8_t * data = (uint8_t *)c;
    uint8_t len = sizeof(data);
    printf("Sending %02d bytes to node #%d => ", len, RF_GATEWAY_ID );
    int dada = strtol((const char*)data, NULL, 10);
    printf("data %d",dada);
    printf("\n" );
 //rf95.send(data, len);
    // rf95.waitPacketSent();
        

 ofstream myfile1;
  myfile1.open ("n1.txt");
  myfile1 << "deg \n";
  myfile1.close();
  //return 0;

int ef =2;

std::ofstream outfile;
switch(ef) {
    case 1 : outfile.open("n1.txt", std::ios_base::app);
    case 2 : outfile.open("n2.txt", std::ios_base::app);
}
  outfile << dada << endl ; 


  int number_of_lines = 0;
    std::string line;
    std::ifstream myfile("n2.txt");
    while (std::getline(myfile, line))
        ++number_of_lines;
    std::cout << "Number of lines in text file: " << number_of_lines;
//printf("cout %02d ",number_of_lines);
    printf("\n" );

 
    return 0;
}

