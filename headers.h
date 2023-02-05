#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include <sys/stat.h>
#include <dirent.h> 

#define cmd_max_len 1000
#define str_max_len 5000
#define folder_name_max_len 70
#define file_max_len 5000
#define file_max_words 1000
#define word_max_len 1000
#define max_arguments_grep 100
#define line_max_len 1000
#define max_undo 1000

#define sp_char_horizontal 196       
#define sp_char_intersection 195
#define sp_char_L 192               

#define syntax_error(error_str,ret_value)\
        {\
            printf("\nSyntax error: %s command exitted unsuccessfully.\n",error_str);\
            return ret_value;\
        }

#define runtime_error(error_str,ret_value)\
        {\
            printf("\nRuntime error: %s command exitted unsuccessfully.\n",error_str);\
            return ret_value;\
        }

#define expected_cmd(input_str,expected_str,error_str,ret_value)\
        {\
            if(strcmp(input_str,expected_str)!=0)\
            {\
                syntax_error(error_str,ret_value)\
            }\
        }

//main
int input();
int undo(char* path);
int save_file(char* path);
int grep(char* str,int file_count,char files[][str_max_len],int flag,FILE* output_file);
int arman();
int find(char* path,char* find_str, int count, int at, int byword, int all,FILE* output_file,int is_replace,char* replace_str);
int compare(char* path1, char* path2, FILE* output_file);
int auto_indent(char* path);
int tree(int max_depth,int current_depth,char* current_path,char* pre_lines,FILE* output_file);
int pastestr(char* path,int line_index,int char_index);
int copystr(char* path,int size,int line_index,int char_index,int is_forward);
int removestr(char* path,int size,int line_index,int char_index,int is_forward);
int cat(char* path,FILE* output_file);
int insertstr(char* path,char* str,int line_index,int char_index);
int createfile(char* path);
int process_input(char* cmd,int is_find_command);

//minor_functons
int file_existance(char* path);
void str_append(int str_count, char* output, char* str,...);
void two_str_append(char* final_str,char* first,char* second);
void get_text_of_file(char* path,char* text_of_file);
void str_remove(char* str,int start_index,int end_index);
void str_middle_add(char* main_str,char* second_str,int index);
void gap_remove(char* str,int index);
void clear_array(int* arr,int size);
void int_to_string(int a,char* output);
void copy(char* from,char* to);
