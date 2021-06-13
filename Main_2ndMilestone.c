//Main Function
int main(void){
	 
	double latitude1;
	double longitude1;
  double final_lat;
	double final_long;
	double alldistance=0;
	
PortF_Init(); 
UART2_PortD_Init();

while(1){
	


	 longitude1=ParsingLong() ;

	 latitude1=ParsingLat();
			

	 delay_milli(1000);
	 


	
	final_lat =  ParsingLat();
	final_long = ParsingLong();
	
	alldistance = alldistance + calc_Distance(latitude1, longitude1 , final_lat , final_long);
 

	
// LED TURNS ON WHEN GETTING DISTANCE AND LCD SHOWS IT'S OUTPUT > 100
	if (alldistance >= 100){
  GPIO_PORTF_DATA_R|= 0x04;  //Turning on Blue LED when Distance greater than 100
	Display_at_100();		 
 
	}
	
	delay_milli(1000);
		 
  }
 


}
