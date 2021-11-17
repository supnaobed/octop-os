#include "../include/Smbus.h"
#include "../include/Motor.h"
#include <stdio.h>

int main(){
    uint8_t addr;
    Motor motor;
    int ret;

    motor.fd = 0;
    addr = 0x01;
    ret = set_addr(&motor, addr);
    printf("set_addr status %d\n", ret);
    set_encoder_enable(&motor, ALL);
    
    return ret;
}

int _write_bytes(Motor motor, uint8_t reg, uint8_t *data);
int _read_bytes(Motor motor, uint8_t reg, uint8_t *data);

void _set_control_mode(Motor motor, int mode){
    // _write_bytes(self._REG_CTRL_MODE, [mode])
}

int set_addr(Motor * motor, uint8_t addr){
    Devcm devcm;
    uint8_t reg;
    uint8_t	data[6];																				

    devcm.fd = motor->fd;
    devcm.comand = 0;
    int res = checkAddress(devcm, addr);
    printf("check_addr status %d\n", res);
    if (res < 0) {
        return res;
    }
    motor->addr = addr;
	data[0] = addr;	
    reg = REG_SLAVE_ADDR;									
    return _write_bytes(*motor, reg, data);
}

int begin(Motor * motor){
    								
    return -1;
}

int set_encoder_enable(Motor * motor, int id){
    uint8_t	data[1];																				
    int arr[MOTOR_COUNT];
    int size;
    int ret = parse_id(id, arr, &size);
    if (ret < 0){
        return ret;
    }
    for (int i = 0; i < size; ++i){
        int value = REG_ENCODER1_EN + 5 * (arr[i] - 1);
        data[0] = 0x01;
        printf("result %d\n", value);
        _write_bytes(motor, value, data)						
    }
    return 0;
}
    

int parse_id(int id, int * arr, int * size){
    int ret;
    ret = 0;
    if (id == ALL){
        for(int i = 1; i < MOTOR_COUNT + 1; ++i) {
            arr[i-1] = i;
        } 
        *size = MOTOR_COUNT;
    }else {
        if (id < 1 || id > MOTOR_COUNT) {
            ret = -1;
        } else {
            arr[0] = id;
            *size = 1;
        }
    }
    return ret;
}
    

// int set_encoder_enable(Motor * motor){
//     for (i in self._parse_id(id):
//       self._write_bytes(self._REG_ENCODER1_EN + 5 * (i - 1), [0x01])							
//     return -1;
// }

int _write_bytes(Motor motor, uint8_t reg, uint8_t *data) {
    int ret; 
    int sumtry;
    Devcm devcm;
    devcm.fd = motor.fd;
    devcm.comand = motor.command;

    ret = -1;
    sumtry = 10;
    do {
        ret = writeBytes(devcm, motor.addr, reg, data, sumtry);
        sumtry --;
    } while (sumtry > 0 && ret<0);
    return ret;
}

int _read_bytes(Motor motor, uint8_t reg, uint8_t *data) {
    int ret; 
    int sumtry;
    Devcm devcm;
    devcm.fd = motor.fd;
    devcm.comand = motor.command;
    
    ret = -1;
    sumtry = 10;
    do {
        ret = readBytes(devcm, motor.addr, reg, data, sumtry);
        sumtry --;
    } while (sumtry > 0 && ret<0);
    return ret;
}