#pragma once
#include "IComunicator.h"
#include <thread>

class NetworkComunicator : public IComunicator
{

public:
    NetworkComunicator(int port, int ipAddressV4) {};
    ICommunicationMessage* ReciveMessage();
    void SendMessage(const ICommunicationMessage* message);
    void Initialize();

private:
    std::thread* m_serverThread;

};