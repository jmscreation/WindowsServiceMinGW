#include "includes.h"

int main(int argc, char *argv[])
    {
        if ((argc > 1) && ((*argv[1] == '-' || (*argv[1] == '/'))))
        {
            if (strcasecmp("install", argv[1] + 1) == 0)
            {
                // Install the service when the command is
                // "-install" or "/install".
                std::cout << "Installing Service..." << std::endl;
                if(InstallService(
                    SERVICE_NAME,               // Name of service
                    SERVICE_DISPLAY_NAME,       // Name to display
                    SERVICE_LOCAL_DESCRIPTION,  // Description to display
                    SERVICE_START_TYPE,         // Service start type
                    SERVICE_DEPENDENCIES,       // Dependencies
                    SERVICE_ACCOUNT,            // Service running account
                    SERVICE_PASSWORD            // Password of the account
                    )){
                    std::cout << "Starting Service" << std::endl;
                    StartService(SERVICE_NAME);
                }

            }
            else if (strcasecmp("remove", argv[1] + 1) == 0)
            {
                // Uninstall the service when the command is
                // "-remove" or "/remove".
                UninstallService(SERVICE_NAME);
            } else if (strcasecmp("start", argv[1] + 1) == 0){
                if(!ServiceInstalled(SERVICE_NAME)){
                    std::cout << "Service Not Installed" << std::endl;
                } else {
                    std::cout << "Starting Service" << std::endl;
                    StartService(SERVICE_NAME);
                }
            } else {
                std::cout << "Invalid Operation" << std::endl;
            }
        }
        else
        {
            std::cout << "Parameters:" << std::endl;
            std::cout << " -install  to install the service." << std::endl;
            std::cout << " -remove   to remove the service." << std::endl;
            std::cout << " -start   to start the service." << std::endl;


            CSampleService service(SERVICE_NAME);
            DWORD errorCode;
            if (!CServiceBase::Run(service, errorCode))
            {
                std::cout << "Service failed to run w/err 0x" << errorCode << std::endl;
            } else {
                std::cout << "Service started successfully" << std::endl;
            }
        }


        return 0;
    }
