#ifndef CONFIG_PARSER_H_
#define CONFIG_PARSER_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<json-c/json.h>

/**
 * \enum parse_t
 * 
 * \brief An enum created for the type of file we want to generate 
 *  
 **/
typedef enum {
	CSV,
	JSON
}parse_t;

/**
 * \struct config_t
 * 
 * \brief A struct that defines the parametres stored in the config,json
 * 
 **/
typedef struct{
	parse_t type; 			/*!< The type for the output file extension */
	char path[100][1024]; 	/*!< The paths of the files that we want to parse */
	int inputs_count; 		/*!< The number of input files */
	int limit_warning; 		/*!< The limit of warnigs we can accept */
}config_t;

/**
 * \fn parse:config
 * 
 * \brief A function that return the parametres stored in the config,json
 * 
 **/
config_t parse_config();

/**
 * \fn parse_t
 * 
 * \brief A function that return the type of the output files
 * 
 **/
parse_t what_type(const char *t);

#endif
