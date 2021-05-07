// Initialise variables
int lux = 0;
int hour = 0;
int prevlux = 0;
int totallux = 0;

void setup() {
}

void loop() {
    // Save the previous value
    prevlux = lux;
    
    // Generate fake data
    if (hour == 12) {
        lux = 3;
    } else if (hour == 13) {
        lux = 5;
    } else if (hour > 23) {
        hour = -1;
    } else {
        lux = 0;
    }
    
    totallux += lux;
    
    if (lux > 0 and prevlux == 0) {
        Particle.publish("Started receiving light!", "Started receiving light at hour " + String(hour));
        //beginlight = 1;
    }
    if (lux == 0 and prevlux > 0) {
        Particle.publish("Stopped receiving light!", "Stopped receiving light at hour " + String(hour) + ". Total light received was " + String(totallux));
        //endlight = 1;
        totallux = 0;
    }
    

    // Wait a second before moving one "hour" ahead
    delay(1000);
    
    // Move to the next hour
    hour++;
}
