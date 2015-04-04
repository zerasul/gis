#include <Arduino.h>
#include <EEPROM.h>
/******************************************
* EEPROM libary: libreria de uso de la memoria EEPROM para guardar los valores de configuracion
*  para el proyecto GIS.
*  v: 1.0.
* Fecha: 12/01/2015
*******************************************/
#define CONFIG_START 25 //Initial Address in the EEPROM.

/*Struct con la configuracion almacenada en EEPROM */
typedef struct{
 int humedadoptima;
 int tiemporiego;
 int humedadmaxima;//Humedad maxima para la calibracion
}Configuration;

Configuration getDefaultConfig(){
 Configuration default_config;
 default_config.humedadoptima=80; //Valor absoluto de humedad optima
 default_config.tiemporiego=30;  //Tiempo de riego en minutos.
 return default_config;
}
/*
 * store the Settings in the EEPROM
 * Parameters:
 * Settings: The Settings to Store.
 * Returns: The number of bytes writed*/  
int store_Settings(Configuration & settings)
{
   int e=CONFIG_START;
   int i=0;
   byte* data=(byte *)&settings;
   for(i=1;i<sizeof(settings);i++){
     byte b=data[i];
     EEPROM.write(e+i,b);
   }
   return i;
}
/*
* loads the Settins form The EEPROM.
* Parameters
* settings: The settings struct for load the information from the EEPROM.
* returns: number of bytes readed.*/
int load_Settings(Configuration & settings)
{
  int e=CONFIG_START;
   int i=0;
   byte* data=(byte *)&settings;
   for(i=1;i<sizeof(settings);i++){
     data[i]=EEPROM.read(e+i);
   }
   memcpy(&settings,data,sizeof(settings));
   return i;
}
/**
* loads the default configuration, and store it in the EERPROM
* Returns: default configuration settings.
*/
Configuration reset_Settings(){
  Configuration current_config=getDefaultConfig();
  store_Settings(current_config);
  return current_config;
}
