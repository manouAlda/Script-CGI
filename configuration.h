#ifndef CONFIGURATION_H
#define CONFIGURATION_H

int hex_to_char(char* tab);
char* withoutHex(char* tab) ;
char* balise_html (char* balise, char* attribut, char* text, char* fin_balise);
void print_balise_html (char* balise, char* attribut, char* text, char* fin_balise);
void classe (char* balise, char* text);
char* create_conf (char* conf);
void create_hosts (char* serverName);

#endif