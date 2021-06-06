//Main Function
int main(void){
	
//declaring SW1	
unsigned long SW1;
PortF_Init(); 
while(1){
	
// LED TURNS ON WHEN GETTING DISTANCE AND LCD SHOWS IT'S OUTPUT > 100
	SW1 = GPIO_PORTF_DATA_R&0x10; //STORING SWITCH ONE DATA IN VARIABLE
  if( SW1 ==	0x00){
		Delay(); //
    distance_Inc();	//Increasing Distance with 10 everytime SW1 is pressed
		
	  
      if (D>100){
         GPIO_PORTF_DATA_R|= 0x04;  //Turning on Blue LED when Distance greater than 100
         Display_at_100();				//Displaying output to LCD
        }
    }
		 
  }
		
}
