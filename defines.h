
#ifndef __DEFINES
#define __DEFINES

    // Internal name of the service
    #define SERVICE_NAME                 "MyCustomService"

    // Displayed name of the service
    #define SERVICE_DISPLAY_NAME         "My Sample Service"

    // Service description
    #define SERVICE_LOCAL_DESCRIPTION    "This service is designed to provide an understanding with windows services and how to create/install them in C++ using the MinGW Compiler."

    // Service start options            SERVICE_AUTO_START | SERVICE_BOOT_START | SERVICE_DEMAND_START | SERVICE_DISABLED | SERVICE_SYSTEM_START
    #define SERVICE_START_TYPE           SERVICE_AUTO_START

    // Service error control type       SERVICE_ERROR_IGNORE | SERVICE_ERROR_NORMAL | SERVICE_ERROR_SEVERE | SERVICE_ERROR_CRITICAL
    #define SERVICE_ERROR_SELECT         SERVICE_ERROR_NORMAL

    // Service controls allowed flags   SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE
    #define SERVICE_CONTROLS_ACCEPTED    SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE

    // List of service dependencies - "dep1\0dep2\0\0"
    #define SERVICE_DEPENDENCIES         ""

    // The name of the account under which the service should run
    #define SERVICE_ACCOUNT              NULL

    // The password to the service account name
    #define SERVICE_PASSWORD             NULL

    //Create Event Logs For Every Service Control Handler
    #define SERVICE_CTRL_LOG             FALSE

    //Create Event Logs For This Service - This overrides the SERVICE_CTRL_LOG state when FALSE
    #define SERVICE_LOG                  TRUE


#endif // __DEFINES
