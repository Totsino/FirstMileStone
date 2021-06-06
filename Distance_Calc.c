//  lat_init, lon_init,  lat_final,  lon_final will be recieved from GPS_UART Module
   
    /*
    double calc_Distance(double lat_init, double lon_init, double lat_final, double lon_final) {

    double pi = 3.141592653589793;
    int Earth_Radius = 6371; //Radius of the Earth
    lat_init = (pi/180)*(lat_init);
    lon_final = (pi/180)*(lon_final);
    double difference_Lon = (pi/180)*(lon_final- lat_init);
    double difference_Lat = (pi/180)*(lon_final - lat_init);
    double a = sin(difference_Lat/2) * sin(difference_Lat/2) + 
    cos(lat_init) * cos(lon_final) * 
    sin(difference_Lon/2) * sin(difference_Lon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = Earth_Radius * c;
    return distance;
}
   */
