#pragma once
#include "IComunicationBuffer.h"
#include "ICommunicationMessage.h"

class TcpServer
{

public:
    TcpServer(){};
    TcpServer(int ipAdress, 
              int port, 
              IComunicationBuffer* rxBuffer,
              IComunicationBuffer* txBuffer) :
              m_ipAdress(ipAdress), m_port(port),
              m_txBuffer(txBuffer), m_rxBuffer(rxBuffer)
              {};
    void Run();

private:
    int m_port;
    int m_ipAdress;
    IComunicationBuffer* m_txBuffer;
    IComunicationBuffer* m_rxBuffer;
};