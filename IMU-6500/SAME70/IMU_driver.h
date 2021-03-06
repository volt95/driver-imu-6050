/*
 * IMU_driver.h
 * this driver is otpimized for full speed read in samE7 20MHz only when do you need to read the sense
 * when do you need to write the registers the speed of the SPI is changed to 1MHz 
 * Created: 23/04/2016 03:36:31 p. m.
 *  Author: aleja_000
 */ 


#ifndef IMU_DRIVER_H_
#define IMU_DRIVER_H_

#include "IMU_filter.h"

typedef enum{
	TYPE_GYRO_DATA,
	TYPE_ACCEL_DATA,
	TYPE_IMU_6050_DATA
	}type_data_out;

//types and structs

typedef struct gyro_struct{
		uint32_t g_x;
		uint32_t g_y;
		uint32_t g_z;
	}gyro_data_t;

typedef struct accel_struct{
		uint32_t a_x;
		uint32_t a_y;
		uint32_t a_z;
	}accel_data_t;

typedef struct IMU_6050_data_t{
		accel_data_t accel;
		gyro_data_t gyro;
	}IMU_6050_t;


//global variables

uint32_t lastUpdate = 0;

void enable_IMU(void);
uint32_t update_and_get_Data_IMU(void);
uint32_t get_data_position_IMU(void);


#endif /* IMU_DRIVER_H_ */