#ifndef SMBUS
#define SMBUS

#include <unistd.h>
#include <sys/ioctl.h> 
#include <stdint.h> 
#include <sys/ioctl.h>

typedef struct Devcm
{
    int fd;
    unsigned long comand;
} Devcm;


// Функция пакетной записи нескольких байт данных в регистр модуля:
// аргументы: адрес_модуля, адрес_первого_регистра, указатель_на_массив, количество_байт
int writeBytes(Devcm devcm, uint8_t addr, uint8_t reg, uint8_t *data, uint8_t sum);

// Функция пакетной записи нескольких байт данных в модуль:
// аргументы: адрес_модуля, указатель_на_массив, количество_байт
int writeBytesMod(Devcm devcm, uint8_t addr, uint8_t *data, uint8_t sum);

// Функция пакетного чтения нескольких байт данных из регистров модуля:
// аргументы: адрес_модуля, адрес_первого_регистра, указатель_на_массив, количество_байт
int readBytes(Devcm devcm, uint8_t addr, uint8_t reg, uint8_t *data, uint8_t sum);

// Функция пакетного чтения нескольких байт данных из модуля:
// аргументы: адрес_модуля, указатель_на_массив, количество_байт
int readBytesMod(Devcm devcm, uint8_t addr, uint8_t *data, uint8_t sum);


//  Функция чтения одного байта из регистра модуля:
//  аргументы: адрес_модуля, адрес_регистра
uint8_t readByteReg(Devcm devcm, uint8_t adr, uint8_t reg);

//  Функция чтения одного байта из модуля:
uint8_t readByte(Devcm devcm, uint8_t adr);

// Функция записи одного байта в регистр модуля:
int writeByteReg(Devcm devcm, uint8_t adr, uint8_t reg, uint8_t data);

// Функция записи одного байта в модуль:
int writeByte(Devcm devcm, uint8_t adr, uint8_t data);

// Функция проверки наличия ведомого по его адресу:
// аргументы: адрес_регистра, байт_данных
int checkAddress(Devcm devcm, uint8_t addr);
#endif

