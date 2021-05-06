#ifndef GENERATE_OUTPUT_H_
#define GENERATE_OUTPUT_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../parse_ubx/parse_ubx.h"
#include "../config_parser/config_parser.h"

/**
 * \fn matchtype
 * 
 * \brief A funtion that build a string of the path of output files
 * 
 * \param n the path string
 * \param type the type of output files
 * 
 * \return char* String of the complete path
 * 
 **/
char *matchtype(const char *n, parse_t type);

/**
 * \fn print_json
 * 
 * \brief A function which print the value in the json output files
 * 
 * @param json_file the FILE variable of the output file
 * @param messages the messages to print in the output files 
 * 
 **/
void print_json(FILE *json_file, const message_t messages);

/**
 * \fn generate_output_json
 * 
 * \brief A function that initialize the print on the json output files
 * 
 * @param output_path The list of the output file paths
 * @param messages The list of all messages to print in the output files
 * 
 **/
void generate_output_json(const char* output_path, const message_t* messages);

/**
 * \fn print_csv
 * 
 * \brief A function which print the value in the csv output files
 * 
 * @param csv_file the FILE variable of the output file
 * @param messages the messages to print in the output files 
 * 
 **/
void print_csv(FILE *csv_file, const message_t messages);

/**
 * \fn generate_output_csv
 * 
 * \brief A function that initialize the print on the csv output files
 * 
 * @param output_path The list of the output file paths
 * @param messages The list of all messages to print in the output files
 * 
 **/
void generate_output_csv(const char* output_path, const message_t* messages);

/**
 * \fn generate_output
 * 
 * \brief A function that initialize the print on the output files
 * 
 * @param path The list of the file paths
 * @param messages The list of all messages to print in the output files
 * @param type The type of the output files
 * 
 **/
void generate_output(const char* path, const message_t* messages, const parse_t type);

#endif
