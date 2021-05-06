#ifndef PARSE_UBX_H_
#define PARSE_UBX_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * 
 * \struct message_t
 * 
 * \brief A struct that include the parametres of the car extract in the ubx files
 * 
 **/
typedef struct {		
	char utc_time[20]; 		/*!< The time in millisecond of the misuration */
	double latitude;		/*!< The latitude of the car */
	double longitude;		/*!< The longitude of the car */
	char altitude[20];		/*!< The altitude of the car */
	char speed_knots[20];	/*!< The speed of the care */
	char course[20];		/*!<  */
}message_t;

/**
 * 
 * \enum message_name_t
 * 
 * \brief An enum that include all the type of message in the ubx files
 * 
 **/
typedef enum {
	GGA,
	GLL,
	RMC,
	GSA,
	GSV,
	VTG,
	UNKNOWN,
	ERR
}message_name_t;

/**
 * 
 * \brief A function that match the path of file with the ubx extension
 * 
 * \param path the path of files
 * 
 * \return char* String of the complete path of ubx files
 * 
 */
char *matchubx(const char *path);

/**
 * 
 * \brief A function that modify the value of latitude and longitude in a better format for Google Earth
 * 
 * \param value the value of latitude or longitude
 * 
 * \return double A double value modified
 * 
 */
double parseVal(double value);

/**
 * 
 * \brief A function that extract the type of a ubx file line
 * 
 * \param line the line passed to exctract the type
 * 
 * \return message_name_t the type of message extracted
 * 
 */
message_name_t get_line_message(char *line);

/**
 * 
 * \brief A function that extract the message of a GGA line
 * 
 * \param line the line passed to exctract the messages
 * 
 * \return message_t the list of messages extracted
 * 
 */
message_t extract_message_GGA(const char *line);

/**
 * 
 * \brief A function that extract the message of a GLL line
 * 
 * \param line the line passed to exctract the messages
 * 
 * \return message_t the list of messages extracted
 * 
 */
message_t extract_message_GLL(const char *line);

/**
 * 
 * \brief A function that extract the message of a RMC line
 * 
 * \param line the line passed to exctract the messages
 * 
 * \return message_t the list of messages extracted
 * 
 */
message_t extract_message_RMC(const char *line);

/**
 * 
 * \brief A function to initialize and parse the line
 * 
 * \param line the line passed to exctract the messages
 * 
 * \return message_t the list of messages extracted
 * 
 */
void parse_ubx(char* ubx_path, message_t* messages,int limit_warning);



#endif
