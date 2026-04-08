#pragma once

#include <stdlib.h>
#include <stdio.h>

#define entries 71

int c_index[] = {7,4,4,7,4,4,7,7,4,10,4,7,4,4,4,4,10,4,4,4,4,10,4,4,4,4,4,7,7,4,4,4,4,7,7,4,4,4,4,4,4,4,4,4,4,7,4,7,7,4,4,25,4,4,10,4,10,4,4,4,4,4,7,4,4,4,4,4,4,4,7,4};

char * cameras[][100] = {
	{"ACTi","Admin","123456","192.168.0.100","admin","123456","192.168.0.100"},
	{"Arecont","admin","none","DHCP"},
	{"Amcrest","admin","admin","DHCP"},
	{"American Dynamics","admin","admin","DHCP","admin","9999","DHCP"},
	{"Arecont Vision","none","none","DHCP"},
	{"AvertX","admin","1234","DHCP"},
	{"Avigilon","admin","admin","DHCP","Administrator","none","DHCP"},
	{"Axis","root","pass","192.168.0.90","root","none","192.168.0.90"},
	{"Basler","admin","admin","DHCP"},
	{"Bosch","none","none","DHCP","service","service","192.168.0.1","Dinion","none","192.168.0.1"},
	{"Brickcom","admin","admin","192.168.1.1"},
	{"Canon","root","camera","DHCP","root","Model # of camera","192.168.100.1"},
	{"CBC Ganz","admin","admin","192.168.100.x"},
	{"Cisco","no default","none","192.168.0.100"},
	{"CNB","CNB","root","admin","192.168.123.100"},
	{"Costar","root","root","DHCP"},
	{"Dahua","admin","admin","192.168.1.108","888888","888888","192.168.1.108","666666","666666","192.168.1.108"},
	{"Digital Watchdog","admin","admin","DHCP"},
	{"DRS","DRS","admin","1234","DHCP"},
	{"DVtel","Admin","1234","192.168.0.250"},
	{"DynaColor","Admin","1234","DHCP"},
	{"FLIR","admin","fliradmin","DHCP","admin","admin","DHCP","admin","admin","DHCP"},
	{"Foscam","admin","none","DHCP"},
	{"GeoVision","admin","admin","192.168.0.10"},
	{"Grandstream","admin","admin","192.168.1.168"},
	{"GVI","GVI","Admin","1234","192.168.0.250"},
	{"HIKVision","admin","12345","192.0.0.64"},
	{"Honeywell","admin","1234","DHCP","administrator","1234","DHCP"},
	{"IndigoVision","none","none","DHCP","Admin","1234","DHCP"},
	{"Intellio","admin","admin","DHCP"},
	{"Interlogix","admin","1234","DHCP"},
	{"IOImage","admin","admin","192.168.123.10"},
	{"IQInvision","root","system","DHCP"},
	{"IPX-DDK","root","admin","192.168.1.168","root","Admin","192.168.1.168"},
	{"JVC","JVC","admin","jvc","DHCP","admin","Model # of Camera","DHCP"},
	{"Longse","admin","12345","DHCP"},
	{"Lorex","admin","admin","DHCP"},
	{"LTS","LTS","admin","12345","DHCP"},
	{"March Networks","admin","none","DHCP"},
	{"Merit Lilin Camera","admin","pass","DHCP"},
	{"Merit Lilin Recorder","admin","1111","DHCP"},
	{"Messoa","admin","Model # of Camera","192.168.1.30"},
	{"Mobotix","admin","meinsm","DHCP"},
	{"Northern","admin","12345","DHCP"},
	{"Oncam","admin","admin","DHCP"},
	{"Panasonic","admin","12345","192.168.0.253","admin1","password","192.168.0.253"},
	{"Pelco","admin","admin","DHCP"},
	{"PiXORD","admin","admin","192.168.0.200","root","pass","192.168.0.200"},
	{"Q-See","admin","admin","DHCP","admin","123456","DHCP"},
	{"QVIS","Admin","1234","192.168.0.250"},
	{"Reolink","admin","none","DHCP"},
	{"Samsung","root","root","DHCP","admin","4321","DHCP","admin","1111111","DHCP","admin","4321","DHCP","root","4321","192.168.1.200","root","admin","192.168.1.200","admin","4321","192.168.1.200","admin","1111111","192.168.1.200"},
	{"Sanyo","admin","admin","192.168.0.2"},
	{"Scallop","admin","password","DHCP"},
	{"Sentry360","admin","1234","DHCP","none","none","DHCP","Admin","1234","192.168.0.250"},
	{"Sony","admin","admin","192.168.0.100"},
	{"Speco","admin","1234","DHCP","root","root","192.168.1.7","admin","admin","192.168.1.7"},
	{"Stardot","admin","admin","DHCP"},
	{"Starvedia","admin","none","DHCP"},
	{"Sunell","admin","admin","DHCP"},
	{"Swann","admin","12344","DHCP"},
	{"Trendnet","admin","admin","DHCP"},
	{"Toshiba","root","ikwd","DHCP","root","ikwb","192.168.0.30"},
	{"VideoIQ","supervisor","supervisor","DHCP"},
	{"Vivotek","root","none","DHCP"},
	{"Ubiquiti","ubnt","ubnt","192.168.1.20"},
	{"Uniview","admin","123456","DHCP"},
	{"Verint","admin","admin","DHCP"},
	{"VideoIQ","supervisor","supervisor","DHCP"},
	{"Vivotek","root","none","DHCP"},
	{"W-Box","admin","wbox123","DHCP","admin","admin","DHCP"},
	{"Wodsee","admin","none","DHCP"}
};

//used to track the index of the queried element
unsigned int c_entry;
char** query(char * input){
	int x = 0;
	int low = 0;
	int high = entries;
	//binary search is just fine for the sample size
	while( low <= high){
		x=low+(high-low)/2;
	
		int c = strcasecmp(input, cameras[x][0]);
		if(!c){
			c_entry=x;
			return cameras[x];
		} else if( c < 0 ){
			high=x-1;
		} else {
			low=x+1;
		}
	}
	return nullptr;
}

void print_all(){
	//nasty nested loops
	for (int i = 0 ; i<entries; i++){
		for (int j = 0; j<c_index[i]; j++){
			printf("%s", cameras[i][j]);
			if(j==c_index[i] - 1){
				printf(")");
				break;
			}
			if( (j-1)%3 == 2 && j>0){
				printf(")");
			}
			printf(":");
			if(j%3 == 0){
				printf("(");
			}
		}
		printf("\n");
	}
	return;
}
