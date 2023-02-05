#include "headers.h"

int file_existance(char* path)
{ 
    char current_path[str_max_len];
    for(int i=0;path[i]!='\0';i++)
    {
        current_path[i]=path[i];
        if(path[i]=='/')
        {
            if(strcmp(current_path,"root/")==0)
            {
                continue;
            }

            current_path[i]='\0';

            //check folder existence        
            DIR *d;
            d = opendir(current_path);
            if(d==NULL)
            {
                return -2;
            }
            closedir(d);

            current_path[i]='/';
        }
    }
	
    FILE* new_file=fopen(path, "r");
    if(new_file==NULL)
    {
        return -1;
    }
    fclose(new_file);

    return 0;
}

void str_append(int str_count, char* output, char* str,...)
{
    va_list valist;
    va_start(valist, str);

    strcpy(output,str);

    for (int i=0; i<str_count-1; i++) 
    {
        two_str_append(output,output,va_arg(valist, char*));
    }

    va_end(valist);
}

void two_str_append(char* final_str,char* first,char* second)
{
    int index=0;
    int first_len;
    while(first[index]!='\0')
    {
        final_str[index]=first[index];
        index++;
    }
    first_len=index;
    while(second[index-first_len]!='\0')
    {
        final_str[index]=second[index-first_len];
        index++;
    }
    final_str[index]='\0';
}

void get_text_of_file(char* path,char* text_of_file)
{
    text_of_file[0]='\0';
    FILE* file=fopen(path,"r");
    while(1)
    {
        char inp[file_max_len];
        if(fgets(inp,file_max_len,file)==NULL)
        {
            break;
        }

        str_append(2,text_of_file,text_of_file,inp);
    }
    fclose(file);
}

void str_remove(char* str,int start_index,int end_index)
{
    if(end_index<start_index)
    {
        return;
    }

    int len=strlen(str);
    int diff=end_index-start_index+1;

    for(int i=end_index+1;i<=len;i++)
    {
        str[i-diff]=str[i];
    }
}

void str_middle_add(char* main_str,char* second_str,int index)
{
    char tmp[str_max_len];
    strcpy(tmp,main_str);

    main_str[index]='\0';

    str_append(3,main_str,main_str,second_str,tmp+index);
}

void gap_remove(char* str,int index)
{
    int i=index-1;

    while(str[i+1]==' ' || str[i+1]=='\n')
    {
        i++;
    }

    str_remove(str,index,i);
}

void clear_array(int* arr,int size)
{
    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }
}

void int_to_string(int a,char* output)
{
    output[0]='\0';
    while(a>0)
    {
        char c[10];
        c[0]=a%10 +'0';
        a/=10;
        c[1]='\0';

        str_middle_add(output,c,0);
    }
}

void copy(char* from,char* to)
{
    char text_of_file[file_max_len];
    get_text_of_file(from,text_of_file);

    FILE* file=fopen(to,"w");
    fputs(text_of_file,file);
    fclose(file);
}
