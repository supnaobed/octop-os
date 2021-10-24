#ifndef APP
#define APP

struct App
{
    char * name;
};

extern struct App app;

extern int runApp(char *name);
#endif