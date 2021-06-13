uint8_t Data_Avilable (void){
if ((UART2_FR_R&0x10) == 0x10){ //MAY BE CHANGED
return 0;
}  
else{
return 1;
}
}


unsigned char com_rx(void){

if(Data_Avilable() == 1){
return ((uint8_t)(UART2_DR_R&0xFF));

}else
{
return 0;
}
}
