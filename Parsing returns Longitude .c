double ParsingLong(void){
	
double longitude;
	double latitude;


	unsigned int   j, k;				/* dummy variable */
  unsigned int	 i;		     		/* Number of chars read per GPS message string */
  
  unsigned char  charRead;	     		/* char read from COM port */
  unsigned char	 stringRead[MAXSIZE]; 		/* Buffer collects chars read from GPS */
  unsigned char  tempString[MAXSIZE];
  unsigned char  timeString[12];
  unsigned char  latitudeString[11];
  unsigned char  longitudeString[12];

  unsigned char  *pChar;

  
  unsigned  char lastCommaPosition;
	int longdegrees;
	double longminutes;
	double longitudef;
	
	
	charRead = com_rx();  	/* read char from serial port */
      if(charRead == '$') {     /* GPS messages start with $ char */
	  i = 0;
	  
	  stringRead[i] = charRead;
			}
	  do {
	     charRead = com_rx();
	      if( (charRead != '\0') && (isalnum(charRead) ||  isspace(charRead) || ispunct(charRead)) ) {
		i++;
		stringRead[i] = charRead;
	     }
		 }
	 
 
	  
		while(charRead != CR);

	  /* By this point, a complete GPS string has been read so save it to file */
	  /* Append the null terminator to the string read */
	  stringRead[i+1] = '\0';
		
		 /* Analyze string that we collected */
	  j = 0;
	  pChar = stringRead;
	  while(*(pChar+j) != COMMA) {
	       tempString[j] = *(pChar+j);
	       j++;
	  }
		tempString[j] = '\0';
		if(tempString[0] == '$' && tempString[1] == 'G' && tempString[2] == 'P') {
			 pChar = stringRead;
			    /* Get UTC time */
	      j = 7;  /* start of time field */
	      k = 0;
	      while(*(pChar+j) != COMMA) {
		   timeString[k] = *(pChar+j);
		   j++;
		   k++;
	      }
	      lastCommaPosition = j;
	      timeString[k] = '\0';
				
				
/* Get longitude: dddmm.mmmm */
	      pChar = stringRead;
	      j = lastCommaPosition + 1;
	      k = 0;
	      while(*(pChar+j) != COMMA) {
		   longitudeString[k] = *(pChar+j);
		   j++;
		   k++;
	      }
	      lastCommaPosition = j;
	      longitudeString[k] = '\0';

	      sscanf(longitudeString, "%lf", &longitude);
				
				longdegrees = (int)(longitude/100);
				longminutes = (double)(longitude-(longdegrees*100));
				
				longitudef = longdegrees + (longminutes/60);

	      

				
			}		
	     				return longitudef;

		}
