/*
File name: Packetize

Scope:
Get all sensor data from sensor drivers
check all sensor data to see if value is valid
put all data into a data paclet to be send to
the communication/ datalog job.

Auther: Caleb Malcarne

Date: 9/27/2023
*/

/*
functions to add:
packet for transmission 
prep data for transmission
*/

float temp, pres, hum, alta, act_rte;

float temp_, pres_, hum_, alta_, act_rte_ = 0;

float a_temp, a_pres, a_hum, a_alta, a_act_rte = 0;

float tolerence [] = {0.0};



typedef struct{
    float temp;
    float pres;
    float hum;
    float alta;
    float act_rte;
} sensorPacket;

void read_config(){
    ;
}

void get_sensor_data(){
    temp_ = temp; pres_ = pres; hum_ = hum; alta_ = alta; act_rte_ = act_rte;

    a_temp = avg(temp, temp_); a_pres = avg(pres, pres_),a_hum = avg(hum, hum_); a_alta = avg(alta, alta_);
}

float avg(int a, int b){
    return (a + b) / 2;
}

void add_to_queue(sensorPacket packet){
    ;
    
}

int check_value(float tolerance_percent, float value, float avg){
    int valid = 1;

    float tolerance = tolerance_percent * value;

    float upper = value + tolerance;

    float lower = value - tolerance;

    valid = value > upper ? 0 : 1;
    valid = value < lower ? 0 : 1;

    if(valid) return value; 
    
    else return avg;
}   

sensorPacket packetize(float temp, float pres, float hum, float alta, float act_rte){

    sensorPacket packet;

    packet.temp = temp;
    packet.pres = pres;
    packet.hum = hum;
    packet.alta = alta;
    packet.act_rte = act_rte;

    add_to_queue(packet);
}
